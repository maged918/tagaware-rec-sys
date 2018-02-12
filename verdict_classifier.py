import csv
import sys
import time
import pickle
from math import sqrt
from itertools import product
from collections import Counter
from collections import defaultdict

import matplotlib
import numpy as np
import pandas as pd
import seaborn as sns
import scikitplot as skplt
import matplotlib.pyplot as plt

from sklearn.decomposition import PCA
from sklearn.svm import LinearSVC, SVC
from sklearn.naive_bayes import MultinomialNB
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import chi2, SelectKBest, mutual_info_classif
from sklearn.metrics import precision_recall_fscore_support, f1_score, roc_auc_score
from sklearn.cluster import KMeans, DBSCAN, SpectralClustering, AgglomerativeClustering
from sklearn.metrics import precision_score, recall_score, confusion_matrix, classification_report, roc_curve
from sklearn.model_selection import train_test_split, StratifiedKFold, StratifiedShuffleSplit, cross_val_score

import imblearn
from imblearn.over_sampling import SMOTE, ADASYN
from imblearn.combine import SMOTEENN, SMOTETomek
from imblearn.under_sampling import NearMiss, RandomUnderSampler


def latexify(fig_width=None, fig_height=None, columns=2):
    """Set up matplotlib's RC params for LaTeX plotting.
    Call this before plotting a figure.

    Parameters
    ----------
    fig_width : float, optional, inches
    fig_height : float,  optional, inches
    columns : {1, 2}
    """

    # code adapted from http://www.scipy.org/Cookbook/Matplotlib/LaTeX_Examples

    # Width and max height in inches for IEEE journals taken from
    # computer.org/cms/Computer.org/Journal%20templates/transactions_art_guide.pdf

    assert(columns in [1,2])

    if fig_width is None:
        fig_width = 3.32 if columns==1 else 6.64 # width in inches
    from math import sqrt
    if fig_height is None:
        golden_mean = (sqrt(5)-1.0)/2.0    # Aesthetic ratio
        fig_height = fig_width*golden_mean # height in inches

    MAX_HEIGHT_INCHES = 8.0
    if fig_height > MAX_HEIGHT_INCHES:
        print("WARNING: fig_height too large:" + fig_height + 
              "so will reduce to" + MAX_HEIGHT_INCHES + "inches.")
        fig_height = MAX_HEIGHT_INCHES

    # params = {'backend': 'ps',
    #           'text.latex.preamble': [r'\usepackage{gensymb}'],
    #           'axes.labelsize': 8, # fontsize for x and y labels (was 10)
    #           'axes.titlesize': 8,
    #           'font.size': 8, # was 10
    #           'legend.fontsize': 12, # was 10
    #           'xtick.labelsize': 8,
    #           'ytick.labelsize': 8,
    #           'text.usetex': True,
    #           'figure.figsize': [fig_width,fig_height],
    #           'font.family': 'serif'
    # }

    params = {'backend': 'ps',
              'text.latex.preamble': [r'\usepackage{gensymb}'],
              'axes.labelsize': 8, # fontsize for x and y labels (was 10)
              'axes.titlesize': 8,
              'font.size': 8, # was 10
              'legend.fontsize': 12, # was 10
              'xtick.labelsize': 8,
              'ytick.labelsize': 8,
              'text.usetex': True,
              'figure.figsize': [fig_width,fig_height],
              'font.family': 'serif'
    }

    matplotlib.rcParams.update(params)


def latexify_2():
	fig_width_pt = 240  # Get this from LaTeX using \showthe\columnwidth
	inches_per_pt = 1.0/72.27               # Convert pt to inch
	golden_mean = (sqrt(5)-1.0)/2.0         # Aesthetic ratio
	fig_width = fig_width_pt*inches_per_pt  # width in inches
	fig_height = fig_width*golden_mean      # height in inches
	fig_size =  [fig_width,fig_height]
	params = {'backend': 'ps',
	          'axes.labelsize': 10,
	          'font.size': 10,
	          'legend.fontsize': 10,
	          'xtick.labelsize': 8,
	          'ytick.labelsize': 8,
	          'text.usetex': False,
	          'figure.figsize': fig_size}
	plt.rcParams.update(params)

def format_axes(ax):

    for spine in ['top', 'right']:
        ax.spines[spine].set_visible(False)

    for spine in ['left', 'bottom']:
        ax.spines[spine].set_color(SPINE_COLOR)
        ax.spines[spine].set_linewidth(0.5)

    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')

    for axis in [ax.xaxis, ax.yaxis]:
        axis.set_tick_params(direction='out', color=SPINE_COLOR)

    return ax

latexify()


classifier_names = ['rft']
# classifier_names = ['rft', 'lrc', 'svc', 'knn']
classifiers = {'rft':RandomForestClassifier(n_estimators=100, random_state=0, n_jobs=-1),
	'lrc':LogisticRegression(),
	'lsv':LinearSVC(),
	# 'svc':SVC(kernel='poly', degree=2, random_state=0, C=3, probability=True),
	'svc':SVC(kernel='linear', probability=True),
	'mnb': MultinomialNB(), 'knn': KNeighborsClassifier(n_neighbors = 5)}


answer_modes = [\
				#['OK', 'WRONG_ANSWER'], \
				['OK', 'TIME_LIMIT_EXCEEDED'],]

write = True
n_clusters = 2
clustering = False
plot_roc = False
plot_importances = True
samplings = [False]
selectings = [False]
stratifying = True

# train_ratios = [0.1,0.2,0.3,0.4,0.5]
# train_ratios += [0.6,0.7,0.8,0.9]

# train_ratios = [0.05]
# train_ratios = [100,200,400]
# train_ratios = [0.01]
# train_ratios = [1.0]
# train_ratios=[50,150,300, 400]
# train_ratios = [50, 100, 200, 400]
train_ratios=[100]
n_splits=10

split = 'ss'
if split == 'kf':
	train_ratios = [1-1/n_splits]

tagging = []
# tagging = ['greedy', 'imp', 'dp']
# tagging = ['greedy']
# tagging=['dp']
# tagging = ['greedy', 'dp']
# tagging = ['graphs']

# tag_mode = 'math'
tagging = []
# tag_mode = ['dpgr']
tag_mode = ['all']
# tag_mode = ['-all']
if tag_mode == ['-all']:
	tagging += ['graphs', 'dp', 'implementation', 'brute force', 'greedy', 'math']
	tagging += ['dp_gr']
	tagging+=['dp_bf']
elif tag_mode == ['math']:
	tagging = ['math']
elif tag_mode == ['dpgr']:
	tagging+= ['dp_gr']

valid = 'single'
# valid = 'cross'
# valid = 'all'

# var_drop = 'vars'
var_drops = ['none']
# var_drop = '-fns'

# duplicates = ['--keep']
duplicates=['remove']

scale = 'nosca'

def sample(features_df, labels):
	samplers = {'nearm':NearMiss(ratio='majority', random_state=0, version=2, n_jobs=-1), \
			'rnd': RandomUnderSampler(random_state=0),\
			'smote': SMOTE(random_state=0, kind='regular'), \
			'smoteenn':SMOTEENN(random_state=0), 'smotetomek':SMOTETomek(random_state=0),\
			'adasyn':ADASYN(random_state=0)}
	sampler = 'smote'

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
		selector = SelectKBest(mutual_info_classif, k=40)
		X_train_trans = selector.fit_transform(X_train, y_train)
		X_test = selector.transform(X_test)

		idxs_selected = selector.get_support(indices=True) # Get best columns indices
		X_train = X_train.iloc[:,idxs_selected] # Create df using only these columns
		# X_train = X_train.loc[:,['or', 'arrays', '-', 'operations', 'variables', '+', 'plus']]
		# X_test = X_test.loc[:,['or', 'arrays', '-', 'operations', 'variables', '+', 'plus']]
		# print(X_train.columns)

	# pca = PCA(n_components=10)
	# X_train = pca.fit_transform(X_train)
	# X_test = pca.transform(X_test)
	t1 = time.time()
	rft = classifier
	rft.fit(X_train, y_train)
	print('Training time', time.time() - t1)

	t2 = time.time()
	preds = rft.predict(X_test)
	probs = [x[1] for x in rft.predict_proba(X_test)]
	acc = rft.score(X_test, y_test)
	f1 = f1_score(y_test, preds)
	roc = roc_auc_score(y_test, probs)
	print('Testing time', time.time() - t2)

	if plot_roc:
		y_pred_proba = rft.predict_proba(X_test)[::,1]
		fpr, tpr, _ = roc_curve(y_test,  y_pred_proba)
		auc = roc_auc_score(y_test, y_pred_proba)
		plt.plot(fpr,tpr,label="train size=%d, auc=%f"%(train_size,auc))
		plt.legend(loc=4)
		# plt.show()

	importances = None

	if plot_importances:
		col_lists = [col.replace('_', ' ').replace('ll', 'long long').replace('+', 'plus').replace('*', 'multiply') \
								for col in X_train.columns]
		importances = pd.DataFrame({'feature':X_train.columns,'importance':np.round(rft.feature_importances_,3)})
		importances = importances.sort_values('importance',ascending=False).set_index('feature').iloc[:7]
		# importances.plot.bar()
		# plt.xticks(rotation=0, ha='center')
		# plt.show()
		# plt.savefig('importances.pdf')

	## Old result prints
	# print(acc, f1, roc)
	# # print(rft.score(reduced_df, reduced_labels), f1_score(y_test, preds))
	# # print((precision_recall_fscore_support(y_test, preds)))
	# print(classification_report(y_test, preds))
	# print(confusion_matrix(y_test, preds))
	
	return acc, f1, roc, after_sampling, importances

def single_run(classifier, reduced_df, reduced_labels, sampling, selecting):
	if not stratifying: # dont make stratifying none as to print False in csv
		st = None
	else:
		st = labels

	print('test size', test_size)
	X_train, X_test, y_train, y_test = train_test_split(reduced_df, reduced_labels, train_size = train_size, \
		test_size=test_size, stratify=st, random_state=0)

	acc, f1, roc, after_sampling, importances = \
	 train(X_train, X_test, y_train, y_test, classifier, select_flag=selecting, sample_flag=sampling)
	print('ACC = %f, F1 = %f, ROC = %f'%(acc,f1,roc))
	return acc, f1, roc, after_sampling, importances

def cross_validate(classifier, reduced_df, reduced_labels, sampling, selecting):
	
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
		acc,f_score,roc,after_sampling, importances = \
			train(X_train, X_test, y_train, y_test, classifier, sample_flag=sampling, select_flag=selecting)
		total_f_score+=f_score
		total_acc+=acc
		total_auc+=roc
	acc, f1, roc = total_acc/n_splits, total_f_score/n_splits, total_auc/n_splits
	print('ACC = %f, F1 = %f, ROC = %f'%(acc,f1,roc))
	return acc,f1,roc,after_sampling, importances

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

def get_stats(df, hue, importances):
	
	df['verdict'] = df['verdict'].map(lambda x : "%d"%x) # to change to categorical, there must be a cleaner way

	grouped = df.groupby(hue)
	print(grouped['verdict'].apply(lambda x: x.value_counts())) # get value counts of verdict in each group


	# fig, ax = plt.subplots(3,3)
	# ax = ax.flatten()
	# for idx, col in enumerate(importances.index.values[:9]):
	# 	# plot each column box plot, with the grouping feature on x axis, separate plots per verdict
	# 	sns.boxplot(x=hue, y=col, data=df, ax = ax[idx], showfliers=0) 
	# 	# g = sns.FacetGrid(df, hue=hue)
	# 	# g = g.map(sns.distplot, col)

	fig, ax = plt.subplots(1,2)
	ax = ax.flatten()
	boxplot_cols = ['triple_loop', 'ifs']
	boxplot_cols = ['or', 'arrays']
	boxplot_cols = ['recursion', 'arrays double']

	df = df.rename(columns={'arrays_double': 'arrays double'})

	# for idx, col in enumerate(boxplot_cols):
	# 	sns.boxplot(x=hue, y=col, data=df, ax = ax[idx], showfliers=0)
	# 	# sns.kdeplot(x=col, data=df, ax = ax[idx])
	# plt.savefig('boxplot.pdf')

	# for col in importances.index.values:
	# 	sns.distplot(data=df, hue=hue, x=col)
	# 	plt.show()

	# for col in importances.index.values:
	# 	print(grouped[col].apply(lambda x : x.describe()))

	# for col in boxplot_cols:
	# 	print(sns.countplot(grouped[col].apply(lambda x : x.value_counts(normalize=True)), hue='verdict'))
	# 	plt.show()
	# print(df.loc[df['verdict']=='1','recursion'].value_counts(normalize=True))
	# sns.countplot(y = df.loc[df['verdict']=='1','recursion'].value_counts(normalize=True), label='accepted')
	# sns.barplot(y = df.loc[df['verdict']=='0','recursion'].value_counts(normalize=True), label='time limit')
	# pd.value_counts(df['verdict'], normalize=True).plot(kind='bar')
	
	# sns.barplot(x="recursion", y="recursion", hue='verdict',data=df, estimator=lambda x: len(x) / len(df) * 100)

	for idx, col in enumerate(boxplot_cols):
		occupation_counts = (df.groupby(['verdict'])[col]
	                     .value_counts(normalize=True)
	                     .rename('percentage')
	                     .mul(100)
	                     .reset_index()
	                     .sort_values(col))
		p = sns.barplot(x=col, y="percentage", hue="verdict", data=occupation_counts, ax = ax[idx])


	plt.savefig('count-plots.pdf')


def cluster(original_feats_df, importances, accepted_only = False):
	if accepted_only:
		df_init = original_feats_df.loc[original_feats_df['verdict'].isin([1])] # select only accepted subs
	else:
		df_init = original_feats_df

	df = df_init.drop(['problem_id', 'id'], axis=1) # to have only numeric features fo clustering
	
	scaler = StandardScaler()
	scaled = scaler.fit_transform(df)
	km = KMeans(n_clusters=2, random_state=0)
	# km = SpectralClustering(n_clusters=n_clusters, random_state=0, n_jobs=-2)
	# km = DBSCAN(eps=0.5, min_samples = 3, n_jobs=-2)
	# km = AgglomerativeClustering(n_clusters=2, linkage='average')
	km.fit(scaled)
	
	# keep list of labels per cluster
	labels = defaultdict(lambda:list())
	for idx, val in enumerate(km.labels_):
		labels[val].append(idx)

	print('Number of labels per cluster', [len(lst) for lst in labels.values()])

	df_init = df_init.assign(cluster = km.labels_) # assign cluster ids to a new column

	for cluster_id in range(len(np.unique(km.labels_))): # print some of the ids of submissions in this cluster
		print('Cluster %d ids' % cluster_id)
		print(list(df_init.loc[df_init['cluster']==cluster_id, ['id']].values)[:20])

	# get_stats(df_init, 'cluster', importances)	

''' Add tag information to features DataFrame
1) Load n tag-only/pair models
2) Predict all submissions using each model
3) Create n new columns in features dataframe containing predictions
'''

def add_tags(features_df):
	gen_tags = []
	tag_names = []
	for tag in tagging:
		fn = lambda x: 1 if x else 0
		if tag in ['implementation', 'graphs', 'greedy', 'dp', 'math', 'brute force']:
			model = pickle.load(open('models/%s_only_model.pickle'%tag, 'rb'))
			greedy_preds = [i !='other' for i in model.predict(features_df)]
			greedy_preds = [fn(i) for i in greedy_preds]
		else:
			model = pickle.load(open('models/%s_model.pickle'%tag, 'rb'))
			greedy_preds = model.predict(features_df)
			uniques, counts = np.unique(greedy_preds, return_counts=True)
			# print(pd.value_counts(greedy_preds))
			key_dict = {}
			for idx, val in enumerate(uniques):
				key_dict[val] = idx
			greedy_preds = [key_dict[val] for val in greedy_preds]
		tag_names.append(tag)	
		print(tag, Counter(greedy_preds))
		gen_tags.append(greedy_preds)

	for tag_name, tag_list in zip(tag_names, gen_tags):
		features_df[tag_name] = tag_list

	# tag_cols = [col for col in features_df.columns if 'tag' in col]
	# features_df = features_df.drop([col for col in features_df.columns if col not in tag_cols], axis=1)
	# print('After removing all non tag only cols', features_df.shape[1])
	return features_df

''' Removes duplicate submissions
'''
def remove_duplicates(df):
	print('Size before duplicate removal', df.shape)

	duplicates_df = pd.read_pickle(open('dataset/feats/features-unique-grading.pickle', 'rb'))
	df = df[df['id'].isin(duplicates_df['id'].values)]

	print('Size after duplicate removal', df.shape)
	return df

def select_tag(features_df, labels):
	# keep only submissions with specific tag
	features_df = features_df[features_df['tag_0']==0]
	labels = labels[labels.index.isin(features_df.index)]
	return features_df, labels

def generate_sample_problem(original_feats_df):
	df, _, _, _ = train_test_split(original_feats_df, original_feats_df['verdict'], \
		train_size=500, random_state=0, stratify=original_feats_df['verdict'])
	problem_id = df['problem_id'].values[0]
	contest = problem_id.split('/')[0]
	problem = problem_id.split('/')[1]
	result = df[['id', 'verdict']].sort_values(by='id', ascending=True)
	result.to_csv(open('data-grading/%s/%s-sample/%s-%s-samples-verdict.csv'%(contest, problem, contest, problem), 'w'),\
		index=False)
	result[['id']].to_csv(open('data-grading/%s/%s-sample/%s-%s-samples.csv'%(contest, problem, contest, problem), 'w'),\
	index=False)
	print(result[['id']])
	return df

def load_sample_problem(original_feats_df):
	sample = pd.read_csv(open('data-grading/579/579-D-samples-verdict.csv'))

	df = sample.merge(original_feats_df, left_on=['id'], right_on=['id'])
	df = df.drop('verdict_x', axis=1)
	df = df.rename(columns={'verdict_y':'verdict'})
	# print([col for col in df.columns])
	return df

if __name__ == "__main__":

	actual_file = open('out-grading.csv', 'a')
	f = csv.writer(actual_file)
	loc = 'dataset/feats/features-pandas-grading.pickle'
	problems = []
	# problems += ['909/B'] # MATH

	diffs = ['A', 'B', 'C', 'D', 'E']
	contests = ['909', '864', '900', '282', '812']
	diffs_dict = {k:diffs.copy() for k in contests}
	# diffs_dict['848'].remove('D')
	# diffs_dict['848'].remove('E')
	
	diffs_dict['909'].remove('E')
	diffs_dict['812'].remove('D')

	# diffs_dict['900'].remove('E')
	# diffs_dict['812'].remove('E')

	# problems += ['455/A', '899/A', '899/C', '911/E', '915/C', '113/B']
	# problems += ['848/%s'%s for s in diffs] # Div 1, poor performance
	# problems += ['909/%s'%s for s in diffs] # 909/E has limited exmaples
	# problems+= ['864/%s'%s for s in diffs]
	# problems+= ['900/%s'%s for s in diffs]
	# problems+= ['282/%s'%s for s in diffs]
	# problems += ['812/%s'%s for s in diffs]
	# problems+=['%s/%s' % (c, d) for c in contests for d in diffs_dict[c]]
	# problems+=['837/D', '579/D']
	problems+=['579/D']
	# problems+=['837/D']

	# problems += ['900/B']
	# problems+=['282/C']
	# problems+=['909/D']


	for train_size, problem, duplicate, sampling, var_drop, selecting, classifier, answer_mode in \
		product(train_ratios, problems, duplicates, samplings, var_drops, selectings, classifier_names, answer_modes):
		t1 = time.time()
		if not sampling:
			sampler = 'None'
		else:
			sampler = 'smote'

		print('TESTING PROBLEM', problem)
		original_feats_df = pd.read_pickle(open(loc, 'rb'))


		print('Before id duplicate', original_feats_df.shape)
		original_feats_df = original_feats_df.drop_duplicates('id')
		print('After id duplicate', original_feats_df.shape)

		original_feats_df = select_problem(original_feats_df, problem)
		original_feats_df = original_feats_df.loc[original_feats_df['lines'] > 4]

		if duplicate == 'remove':
			original_feats_df = remove_duplicates(original_feats_df)

		# original_feats_df = load_sample_problem(original_feats_df)
		# original_feats_df = mix_problem(original_feats_df, problem, '911/E')
		## Transform verdicts to binary
		cls = "OK" ## Class assigned to OK
		# original_feats_df = original_feats_df[original_feats_df['verdict'].isin(answer_mode)]
		original_feats_df['verdict'] = original_feats_df['verdict'].map(lambda x: 1 if x==cls else 0) # All other verdicts are 0


		# generate_sample_problem(original_feats_df)

		labels = original_feats_df['verdict']
		features_df = original_feats_df.drop(['verdict', 'problem_id', 'id'], axis=1)

		# Incorporate tag information (most predictions are other, not making much difference)
		features_df = add_tags(features_df)
		# features_df, labels = select_tag(features_df, labels)

		# Drop variable features
		if var_drop == 'vars':
			features_df = features_df.drop(['int', 'double', 'float', 'char', 'vector', 'll', 'point', 'arrays'], axis=1)
		elif var_drop == '-fns':
			features_df = features_df.drop(['min', 'max', 'sort', 'size', 'push_back', 'insert', \
				'erase', 'abs', 'clear', 'find', 'empty', 'lower_bound', 'pop', 'count'], axis=1)
			# features_df = features_df.drop([col for col in features_df.columns[5:]], axis=1)
		# Class distribution (accepted/rejected)
		value_counts = labels.value_counts()/labels.shape
		print('Class distribution\n',value_counts)

		reduced_df, reduced_labels = features_df, labels
		total_size = reduced_df.shape[0]
		print('Total shape', reduced_df.shape)

		if scale=='scale':
			scaler = StandardScaler()
			scaled_df = scaler.fit_transform(reduced_df)
			reduced_df = pd.DataFrame(scaled_df, index=reduced_df.index, columns=reduced_df.columns)

		# If train size is ratio, test size is inverse of ratio

		if type(train_size) == int:
			test_size = reduced_df.shape[0]-train_size
			train_size_write = train_size
		else:
			test_size=1-train_size
			train_size_write = int(total_size * train_size)

		cur_classifier = classifiers[classifier]
		
		# Choose between cross validation or standard train-test split
		if valid=='single':
			acc,f_value,roc, after_sampling, importances = single_run(cur_classifier, reduced_df, reduced_labels, sampling, selecting)
		elif valid =='cross':
			acc,f_value,roc, after_sampling, importances = cross_validate(cur_classifier, reduced_df, reduced_labels, sampling, selecting)
		elif valid == 'all':
			acc, f_value, roc, after_sampling, importances = \
			train(reduced_df, reduced_df, reduced_labels, reduced_labels, cur_classifier)

		print('TIme taken', time.time()-t1)
		if write:
			f.writerow([problem, classifier, sampling, sampler, selecting, stratifying, valid, \
				duplicate, "%4d"%total_size, split, train_size, "%4d"%train_size_write, "%4d"%after_sampling, \
				tag_mode, var_drop, cls, \
				"%.2f"%f_value, "%.2f"%acc, "%.2f"%roc, "%.2f"%value_counts.loc[1], "%.2f"%value_counts.loc[0], answer_mode])
		print('ENDING PROBLEM')

		get_stats(original_feats_df, 'verdict', importances)
		if clustering:
			cluster(original_feats_df, importances, accepted_only=False)
		actual_file.flush()

	if plot_roc:
		plt.plot([0, 1], [0, 1], 'k--')
		# plt.show()
		plt.savefig('roc.pdf')

	if write:
		f.writerow([])
# 
# 