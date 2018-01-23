import pandas as pd
from sklearn.svm import LinearSVC, SVC
from sklearn.naive_bayes import MultinomialNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import chi2, SelectKBest
from sklearn.metrics import precision_recall_fscore_support, f1_score, roc_auc_score
from sklearn.model_selection import train_test_split, StratifiedKFold, StratifiedShuffleSplit
from sklearn.metrics import precision_score, recall_score, confusion_matrix, classification_report

import imblearn
from imblearn.combine import SMOTEENN
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import NearMiss, RandomUnderSampler

us_ratio={0:200, 1:200}

def sample(features_df, labels):

	# nm = NearMiss(ratio='majority', random_state=0, version=2, n_jobs=-1)
	# nm = RandomUnderSampler(ratio=us_ratio, random_state=0)
	# nm = SMOTEENN(random_state=0)
	nm = SMOTE(random_state=0)
	reduced_df, reduced_labels = nm.fit_sample(features_df, labels)

	reduced_df = pd.DataFrame(reduced_df)
	reduced_df.columns = features_df.columns
	return reduced_df, reduced_labels


def single_run():
	X_train, X_test, y_train, y_test = train_test_split(reduced_df, reduced_labels, train_size = 200,  test_size= reduced_df.shape[0] - 200, \
		stratify=None, random_state=0)
	train(X_train, X_test, y_train, y_test)


def train(X_train, X_test, y_train, y_test, sample_flag=True, select_flag = True):
	
	if sample_flag:
		print('Before undersampling shape', X_train.shape)
		X_train, y_train = sample(X_train, y_train)
		print('After undersampling shape', X_train.shape)

	# sm = SMOTEENN(random_state=0)
	if select_flag:
		print('Before select shape', X_train.shape)
		selector = SelectKBest(chi2, k=10)
		X_train = selector.fit_transform(X_train, y_train)
		X_test = selector.transform(X_test)
		print('After select shape', X_train.shape)

	# rft = RandomForestClassifier(n_estimators=100, random_state=0)
	rft = LogisticRegression(C=5, class_weight='balanced')
	# rft = LinearSVC(class_weight='balanced', C=1, dual=False)
	# rft = SVC(kernel='poly', degree=2, random_state=0, C=3)
	# rft = MultinomialNB()

	rft.fit(X_train, y_train)
	print('After fitting')
	preds = rft.predict(X_test)
	print(rft.score(X_test, y_test), f1_score(y_test, preds), roc_auc_score(y_test, preds))
	# print(rft.score(reduced_df, reduced_labels), f1_score(y_test, preds))
	# print((precision_recall_fscore_support(y_test, preds)))
	print(classification_report(y_test, preds))
	print(confusion_matrix(y_test, preds))
	return f1_score(y_test, preds)

def cross_validate():
	n_splits=10
	# skf = StratifiedKFold(n_splits=n_splits, shuffle=True, random_state=0)	
	skf = StratifiedShuffleSplit(n_splits=n_splits, train_size=200, test_size= reduced_df.shape[0] - 200, random_state=0)
	total_f_score = 0
	for train_idx, test_idx in skf.split(reduced_df, reduced_labels):
		X_train, y_train = reduced_df.iloc[train_idx], reduced_labels.iloc[train_idx]
		X_test, y_test = reduced_df.iloc[test_idx], reduced_labels.iloc[test_idx]
		f_score = train(X_train, X_test, y_train, y_test, sample_flag=False, select_flag=False)
		total_f_score+=f_score
	print(total_f_score/n_splits)


''' Select a single problem from the features DataFrame
Format: Contest/ProblemDifficulty
'''
def select_problem(df, problem):
	return df[df['problem_id']==problem]

''' Mix 2 problems, positive class will be accepted submissions of one problem, negative class will be accepted submissions of another problem 
'''
def mix_problem(original_df, problem_1, problem_2):
	df1 = select_problem(original_df, problem_1)
	df2 = select_problem(original_df, problem_2)

	df1 = df1[df1['verdict']=='OK']
	df2 = df2[df2['verdict']=='OK']
	df2['verdict'] = ['OK2'] * df2.shape[0] ## Change label of second problem to OK2 to have 2 classes
	return df1.append(df2)

loc = 'dataset/feats/features-pandas-grading.pickle'


problems = ['455/A', '899/A', '899/C']

for problem in problems:
	print('TESTING PROBLEM', problem)
	original_feats_df = pd.read_pickle(open(loc, 'rb'))
	original_feats_df = select_problem(original_feats_df, problem)
	print('Total shape', original_feats_df.shape)

	# original_feats_df = mix_problem(original_feats_df, '455/A', '899/C')

	## Transform verdicts to binary
	cls = 1 ## Class assigned to OK
	original_feats_df = original_feats_df[original_feats_df['verdict'].isin(['OK', 'WRONG_ANSWER', 'OK2'])]
	original_feats_df['verdict'] = original_feats_df['verdict'].map(lambda x: cls if x=='OK' else 1-cls) # All other verdicts are 0

	# Select subsample from each class
	# dfs = [original_feats_df[original_feats_df['verdict']==i].sample(200, random_state=0, replace=False) for i in range(2)]
	# original_feats_df = dfs[0].append(dfs[1])

	labels = original_feats_df['verdict']
	features_df = original_feats_df.drop(['verdict', 'problem_id', 'id'], axis=1)

	print('Class distribution',labels.value_counts()/labels.shape)

	reduced_df, reduced_labels = features_df, labels

	# Split into training and testing first, then undersample training data

	# cross_validate()

	single_run()

	print('ENDING PROBLEM')

def merge():
	merged = pd.merge(original_feats_df, reduced_df, on=['%', '*', '*=', '+', '++', '+=', '-', '--', '-=', '/', '/=', 'and',
	       'arrays', 'arrays_double', 'avg_params', 'char', 'cnt_pointers',
	       'cyclo', 'declarations', 'divide', 'double', 'double_loop', 'float',
	       'functions', 'if_loop', 'ifs', 'int', 'lines', 'll', 'minus', 'modulus',
	       'operations', 'or', 'plus', 'point', 'recursion', 'shift',
	       'single_loop', 'string', 'times', 'triple_loop', 'variables', 'vector'])
	print(reduced_df.shape, original_feats_df.shape)
	# print(merged['id'])
	test_df = original_feats_df.loc[~original_feats_df['id'].isin(merged['id'].values)]
	# print(test_df.shape)
	test_labels = test_df['verdict']
	test_df = test_df.drop(['verdict', 'problem_id', 'id'],axis=1)

	preds = rft.predict(test_df)
	print(rft.score(test_df, test_labels), f1_score(test_labels,preds))