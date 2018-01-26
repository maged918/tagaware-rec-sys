import csv
import sys
import pickle
from itertools import product
from collections import Counter
from collections import defaultdict

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from sklearn.cluster import KMeans
from sklearn.svm import LinearSVC, SVC
from sklearn.naive_bayes import MultinomialNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import chi2, SelectKBest, mutual_info_classif
from sklearn.metrics import precision_recall_fscore_support, f1_score, roc_auc_score
from sklearn.metrics import precision_score, recall_score, confusion_matrix, classification_report
from sklearn.model_selection import train_test_split, StratifiedKFold, StratifiedShuffleSplit, cross_val_score

import imblearn
from imblearn.over_sampling import SMOTE, ADASYN
from imblearn.combine import SMOTEENN, SMOTETomek
from imblearn.under_sampling import NearMiss, RandomUnderSampler

classifier = 'rft'
classifiers = {'rft':RandomForestClassifier(n_estimators=100, random_state=0, n_jobs=-1),
	'lrc':LogisticRegression(C=5, class_weight='balanced'),
	'lsv':LinearSVC(class_weight='balanced', C=1, dual=False),
	'svc':SVC(kernel='poly', degree=2, random_state=0, C=3, probability=True),
	'mnb': MultinomialNB(), 'knn': KNeighborsClassifier(n_neighbors = 5)}

samplers = {'nm':NearMiss(ratio='majority', random_state=0, version=2, n_jobs=-1), 'rnd': RandomUnderSampler(random_state=0),\
		'smote': SMOTE(random_state=0), 'smoteenn':SMOTEENN(random_state=0), 'smotetomek':SMOTETomek(random_state=0),\
		'adasyn':ADASYN(random_state=0)}
sampler = 'smote'

sampling = True
selecting = False
stratifying = True

# train_ratios = [0.1,0.2,0.3,0.4,0.5]
# train_ratios += [0.6,0.7,0.8,0.9]

train_ratios = [0.2]

# train_ratios = [0.01]
# train_ratios = [1.0]
n_splits=10

split = 'kf'
if split == 'kf':
	train_ratios = [1-1/n_splits]

tagging = []
# tagging = ['greedy', 'imp', 'dp']
# tagging = ['greedy']
# tagging=['dp']
# tagging = ['greedy', 'dp']
# tagging = ['graphs']

# tag_mode = 'all'
# tag_mode = 'math'
# tag_mode='-all'
tag_mode = ['none']
if tag_mode == '-all':
	# tagging = ['dp_gr', 'dp_bf']
	# tagging = []
	tagging += ['graphs', 'dp', 'implementation', 'greedy', 'math']
elif tag_mode == 'math':
	tagging = ['math']
else:
	tagging = []

# valid = 'single'
valid = 'cross'

# var_drop = 'vars'
# var_drop = 'none'
var_drop = '-fns'

if not sampling:
	sampler = 'None'

# duplicates = ['--keep']
duplicates=['remove']
def sample(features_df, labels):



	nm = samplers[sampler]
	reduced_df, reduced_labels = nm.fit_sample(features_df, labels)

	reduced_df = pd.DataFrame(reduced_df)
	reduced_df.columns = features_df.columns
	return reduced_df, reduced_labels


def train(X_train, X_test, y_train, y_test, classifier, sample_flag=True, select_flag = True):
	after_sampling = 0 ## Value of after sampling size
	if sample_flag:
		X_train, y_train = sample(X_train, y_train)
		after_sampling = X_train.shape[0]

	if select_flag:
		selector = SelectKBest(chi2, k=10)
		X_train_trans = selector.fit_transform(X_train, y_train)
		X_test = selector.transform(X_test)

		idxs_selected = selector.get_support(indices=True) # Get best columns indices
		X_train = X_train.iloc[:,idxs_selected] # Create df using only these columns
		print(X_train.columns)

	rft = classifier

	rft.fit(X_train, y_train)
	preds = rft.predict(X_test)
	probs = [x[1] for x in rft.predict_proba(X_test)]
	acc = rft.score(X_test, y_test)
	f1 = f1_score(y_test, preds)
	roc = roc_auc_score(y_test, probs)

	## Old result prints
	# print(acc, f1, roc)
	# # print(rft.score(reduced_df, reduced_labels), f1_score(y_test, preds))
	# # print((precision_recall_fscore_support(y_test, preds)))
	# print(classification_report(y_test, preds))
	# print(confusion_matrix(y_test, preds))
	
	return acc, f1, roc, after_sampling

def single_run(classifier, reduced_df, reduced_labels):
	if not stratifying: # dont make stratifying none as to print False in csv
		st = None
	else:
		st = labels

	print('test size', test_size)
	X_train, X_test, y_train, y_test = train_test_split(reduced_df, reduced_labels, train_size = train_size, \
		test_size=test_size, stratify=st, random_state=0)
	acc, f1, roc, after_sampling = \
	 train(X_train, X_test, y_train, y_test, classifier, select_flag=selecting, sample_flag=sampling)
	print('ACC = %f, F1 = %f, ROC = %f'%(acc,f1,roc))
	return acc, f1, roc, after_sampling

def cross_validate(classifier, reduced_df, reduced_labels):
	
	if split == 'kf':
		skf = StratifiedKFold(n_splits=n_splits, shuffle=True, random_state=0)	

	elif split == 'ss':
		skf = StratifiedShuffleSplit(n_splits=n_splits, train_size=train_size, \
			test_size= test_size, random_state=0)

	## Sanity check, results almost the same
	# print('CROSS VAL SCORE', cross_val_score(classifier, reduced_df, reduced_labels, scoring='roc_auc', cv=skf))

	total_f_score = 0
	total_acc = 0
	total_auc=0

	for train_idx, test_idx in skf.split(reduced_df, reduced_labels):
		X_train, y_train = reduced_df.iloc[train_idx], reduced_labels.iloc[train_idx]
		X_test, y_test = reduced_df.iloc[test_idx], reduced_labels.iloc[test_idx]
		acc,f_score,roc,after_sampling = \
			train(X_train, X_test, y_train, y_test, classifier, sample_flag=sampling, select_flag=selecting)
		total_f_score+=f_score
		total_acc+=acc
		total_auc+=roc
	acc, f1, roc = total_acc/n_splits, total_f_score/n_splits, total_auc/n_splits
	print('ACC = %f, F1 = %f, ROC = %f'%(acc,f1,roc))
	return acc,f1,roc,after_sampling

''' Select a single problem from the features DataFrame
Format: Contest/ProblemDifficulty
'''
def select_problem(df, problem):
	return df[df['problem_id']==problem]

''' Mix 2 problems, 
positive class will be accepted submissions of one problem, negative class will be accepted submissions of another problem 
'''
def mix_problem(original_df, problem_1, problem_2):
	df1 = select_problem(original_df, problem_1)
	df2 = select_problem(original_df, problem_2)

	df1 = df1[df1['verdict']=='OK']
	df2 = df2[df2['verdict']=='OK']
	df2['verdict'] = ['OK2'] * df2.shape[0] ## Change label of second problem to OK2 to have 2 classes
	return df1.append(df2)

''' Visualizes data according to a given grouping features_df
Cases used: according to cluster, or according to verdict
'''

def get_stats(df, hue):
	
	df['verdict'] = df['verdict'].map(lambda x : "%d"%x) # to change to categorical, there must be a cleaner way

	grouped = df.groupby(hue)
	print(grouped['verdict'].apply(lambda x: x.value_counts())) # get value counts of verdict in each group

	cols = ['recursion', 'variables', 'single_loop', 'cyclo']

	for col in cols:
		# plot each column box plot, with the grouping feature on x axis, separate plots per verdict
		sns.boxplot(x=hue, y=col, hue='verdict', data=df) 
		plt.show()

	for col in cols:
		print(grouped[col].apply(lambda x : x.describe()))


def cluster(original_feats_df, accepted_only = False):
	if accepted_only:
		df_init = original_feats_df.loc[original_feats_df['verdict'].isin([1])] # select only accepted subs
	else:
		df_init = original_feats_df

	df = df_init.drop(['problem_id', 'id'], axis=1) # to have only numeric features fo clustering
	
	km = KMeans(n_clusters=3, random_state=0)
	km.fit(df)
	
	# keep list of labels per cluster
	labels = defaultdict(lambda:list())
	for idx, val in enumerate(km.labels_):
		labels[val].append(idx)

	print('Number of labels per cluster', [len(lst) for lst in labels.values()])

	df_init = df_init.assign(cluster = km.labels_) # assign cluster ids to a new column

	for cluster_id in range(len(np.unique(km.labels_))): # print some of the ids of submissions in this cluster
		print('Cluster %d ids' % cluster_id)
		print(list(df_init.loc[df_init['cluster']==cluster_id, ['id']].values)[:20])

	get_stats(df_init, 'cluster')	

''' Add tag information to features DataFrame
1) Load n tag-only/pair models
2) Predict all submissions using each model
3) Create n new columns in features dataframe containing predictions
'''

def add_tags(features_df):
	gen_tags = []
	for tag in tagging:
		fn = lambda x: 1 if x else 0
		if tag in ['implementation', 'graphs', 'greedy', 'dp', 'math']:
			model = pickle.load(open('models/%s_only_model.pickle'%tag, 'rb'))
			greedy_preds = [i !='other' for i in model.predict(features_df)]
			greedy_preds = [fn(i) for i in greedy_preds]
		else:
			model = pickle.load(open('models/%s_model.pickle'%tag, 'rb'))
			greedy_preds = model.predict(features_df)
			uniques = np.unique(greedy_preds)
			key_dict = {}
			for idx, val in enumerate(uniques):
				key_dict[val] = idx
			# greedy_preds = [key_dict[val] for val in greedy_preds]
		print(Counter(greedy_preds))
		gen_tags.append(greedy_preds)

	for tag_idx, tag_list in enumerate(gen_tags):
		features_df['tag_%d'%tag_idx] = tag_list
	return features_df

def remove_duplicates(df):
	print('Size before duplicate removal', df.shape)

	duplicates_df = pd.read_pickle(open('dataset/feats/features-unique-grading.pickle', 'rb'))
	df = df[df['id'].isin(duplicates_df['id'].values)]

	print('Size after duplicate removal', df.shape)
	return df

if __name__ == "__main__":

	actual_file = open('out-grading.csv', 'a')
	f = csv.writer(actual_file)
	loc = 'dataset/feats/features-pandas-grading.pickle'
	problems = []
	# problems += ['909/B'] # MATH

	diffs = ['A', 'B', 'C', 'D', 'E']
	
	contests = ['909', '864', '900', '282', '848']
	diffs_dict = {k:diffs.copy() for k in contests}
	diffs_dict['848'].remove('D')
	diffs_dict['848'].remove('E')
	problems += ['455/A', '899/A', '899/C', '911/E', '915/C', '113/B']
	problems += ['%s/%s'%(contest,diff) for contest in contests for diff in diffs_dict[contest]]
	
	# problems += ['909/%s'%s for s in diffs] # 909/E has limited exmaples
	# problems+= ['864/%s'%s for s in diffs]
	# problems+= ['900/%s'%s for s in diffs]
	# problems+= ['282/%s'%s for s in diffs]
	# problems += ['848/%s'%s for s in diffs] # Div 1, poor performance

	for train_ratio, problem, duplicate in product(train_ratios, problems, duplicates):

		if train_ratio == 1: # Don't use ratio, use absolute value for train size
			train_size = 300
		else:
			train_size = train_ratio

		print('TESTING PROBLEM', problem)
		original_feats_df = pd.read_pickle(open(loc, 'rb'))
		original_feats_df = select_problem(original_feats_df, problem)
		original_feats_df = original_feats_df.loc[original_feats_df['lines'] > 4]

		if duplicate == 'remove':
			original_feats_df = remove_duplicates(original_feats_df)

		# original_feats_df = mix_problem(original_feats_df, problem, '911/E')
		## Transform verdicts to binary
		cls = "OK" ## Class assigned to OK
		original_feats_df = original_feats_df[original_feats_df['verdict'].isin(['OK', 'WRONG_ANSWER', 'OK2'])]
		original_feats_df['verdict'] = original_feats_df['verdict'].map(lambda x: 1 if x==cls else 0) # All other verdicts are 0

		labels = original_feats_df['verdict']
		features_df = original_feats_df.drop(['verdict', 'problem_id', 'id'], axis=1)

		# Incorporate tag information (most predictions are other, not making much difference)
		features_df = add_tags(features_df)

		# features_df = features_df.drop(['cnt_pointers', 'arrays_double'], axis=1)

		# Drop variable features
		if var_drop == 'vars':
			features_df = features_df.drop(['int', 'double', 'float', 'char', 'vector', 'll', 'point', 'arrays'], axis=1)
		elif var_drop == '-fns':
			features_df = features_df.drop(['min', 'max', 'sort'], axis=1)
		# Class distribution (accepted/rejected)
		value_counts = labels.value_counts()/labels.shape
		print('Class distribution\n',value_counts)

		reduced_df, reduced_labels = features_df, labels
		total_size = reduced_df.shape[0]
		print('Total shape', reduced_df.shape)

		# If train size is ratio, test size is inverse of ratio
		if type(train_size) == int:
			test_size = reduced_df.shape[0]-train_size
			train_size_write = total_size
		else:
			test_size=1-train_size
			train_size_write = int(total_size * train_size)

		cur_classifier = classifiers[classifier]
		
		# Choose between cross validation or standard train-test split
		if valid=='single':
			acc,f_value,roc, after_sampling = single_run(cur_classifier, reduced_df, reduced_labels)
		elif valid =='cross':
			acc,f_value,roc, after_sampling = cross_validate(cur_classifier, reduced_df, reduced_labels)

		f.writerow([problem, classifier, sampling, sampler, selecting, stratifying, valid, \
			duplicate, "%4d"%total_size, split, train_ratio, "%4d"%train_size_write, "%4d"%after_sampling, \
			tag_mode, var_drop, cls, \
			"%.2f"%f_value, "%.2f"%acc, "%.2f"%roc, "%.2f"%value_counts.loc[1], "%.2f"%value_counts.loc[0]])
		print('ENDING PROBLEM')

		# get_stats(original_feats_df, 'verdict')
		# cluster(original_feats_df, accepted_only=False)
		actual_file.flush()
	f.writerow([])