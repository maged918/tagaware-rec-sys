'''
Created on Aug 23, 2015

@author: tarek, maged
'''


import pickle
import numpy as np

from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.multiclass import OneVsRestClassifier, OneVsOneClassifier
from sklearn import svm
from sklearn import metrics
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.model_selection import StratifiedKFold, GroupKFold, KFold
from sklearn.naive_bayes import MultinomialNB, GaussianNB
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import SelectKBest, chi2, f_classif
from sklearn.tree import DecisionTreeClassifier

from collections import defaultdict
from collections import Counter
from itertools import product
import time

import config

import pandas as pd

from scipy.stats import chi2_contingency

# import seaborn as sns
import matplotlib.pyplot as plt
from joiner import build_tags, create_df

import csv

# from stats import visualize
col_names = []

def prepare_data(feats_file,tags_file, multi, row_mode, feat_mode, difficulties):

	f = open(feats_file, 'rb')
	inst_feats = pickle.load(f)

	# fig, (ax1, ax2) = plt.subplots(2)
	# sns.boxplot([inst_feats.variables, inst_feats.operations], orient='v', showfliers=False)
	# for col in inst_feats.columns:
	#	 print(inst_feats[col].value_counts())
	# print(type(inst_feats))

	global tags_list, classes, mlb, col_names

	tags_list, delete_keys, inst_tags = build_tags(tags_file, difficulties)

	X = []
	Y = []
	print(len(delete_keys))
	if 'pandas' in feats_file:

		inst_feats, X, Y = create_df(inst_feats, inst_tags, delete_keys, multi)
		print('prepare data', inst_feats.shape, X.shape, Y.shape)
		X = choose_columns(X, feat_mode)
		if 'tags' in X.columns:
			X = X.drop('tags', axis=1)
		# for col in X.columns:
		#	 print(col, X[col].isnull().any())
		col_names = X.columns

		# visualize(inst_feats)

		# conting = pd.crosstab(pd.DataFrame(X)['int'], np.array(Y).flatten())
		# print(chi2_contingency(conting))
	else:
		for key in delete_keys:
			del inst_feats[key]
		for instance in inst_feats:
			if instance in inst_feats and instance in inst_tags:
				if row_mode == 'problem':
					X.append(inst_feats[instance])
					Y.append(inst_tags[instance])
				elif row_mode == 'submiss':
					for submission in inst_feats[instance]:
						X.append(submission)
						Y.append(inst_tags[instance])

		X = np.array(X)

	Y = np.array(Y).ravel()
	print(Y)
	# feature scaling

	# X-=np.mean(X)
	# if np.std(X) > 0:
	#	 X/=np.std(X)
	#
	# pca = PCA(n_components = 2)
	# pca.fit(X)
	# X = pca.fit_transform(X)
	# print(pca.components_, '\n', pca.explained_variance_)

	# print(Y)
	if multi:
		mlb = MultiLabelBinarizer()
		lsts = []
		for lst in Y:
			lsts += lst
		values, counts = np.unique(lsts, return_counts=True)
		Y = mlb.fit_transform(Y)
		classes = mlb.classes_
		print(classes)
		# labels = mlb.labels_
		# print(classes, labels)
	else:
		Y = Y.flatten()
		values, counts = np.unique(Y, return_counts=True)
		classes = np.unique(Y)
	baseline = np.max(counts)/np.sum(counts)
	print('Baseline = ', baseline)
	return (X,Y, baseline)

def choose_columns(X, feat_mode):
	# for i in range(15,X.shape[1]-1):
	#	 X = np.delete(X, i, 1)
	# X = np.delete(X, [19,20,21,22,23], 1)
	# X = SelectKBest(f_classif, k = 20).fit_transform(X, y)



	feats = {'count_vars':['int', 'double', 'float', 'char', 'vector', 'll', 'point', 'arrays'],\
			'constructs': ['single_loop', 'double_loop', 'triple_loop', 'if_loop', 'ifs'],\
			'operations':['operations', 'plus', 'minus', 'times', 'divide', 'modulus'],\
			'lines': ['lines'],\
			'cyclo': ['cyclo']}

	if 'all_feats' in feat_mode and 'cyclo' not in feat_mode:
		# return X
		return X.drop(['cyclo'], axis=1)
	elif 'all_feats' in feat_mode:
		return X

	lst = []
	# lst+= ['triple_loop']
	# lst += ['int', 'double', 'float', 'char', 'vector', 'll', 'point', 'arrays']
	# lst += ['single_loop', 'double_loop', 'triple_loop', 'if_loop', 'ifs']
	# lst += ['operations', 'plus', 'minus', 'times', 'divide', 'modulus']
	#lst+=['lines']

	for feat in feat_mode:
		lst+=feats[feat]

	# lst+=['problem_id', 'id']
	X = X.loc[:,lst]
	print('Selecting feats', X.shape)
	return X

def classify(train,gold,test, test_y,multi, classifier):

	svm_dict = {'random_state':0, 'class_weight':'balanced', 'C':1, 'dual':False}
	# svm_dict = {}
	clf_dict = {'SVM': svm.LinearSVC(**svm_dict), 'RFT': RandomForestClassifier(n_estimators=100, n_jobs = 6),\
						 'ADA': AdaBoostClassifier(n_estimators = 100),\
						'KNN': KNeighborsClassifier(n_neighbors = 20, weights='distance'), 'LRC': LogisticRegression(), \
						'ANN': MLPClassifier(hidden_layer_sizes=(50, 50)), 'DBT':DecisionTreeClassifier(), 'MNB': MultinomialNB(alpha = 1000),\
						'GNB': GaussianNB()}
	clf = classifier
	if multi and clf == 'RFT':
		clf_dict['RFT'] = RandomForestClassifier(n_estimators=100, n_jobs=6, class_weight={0:1, 1:100})
		print(clf)
	clf = OneVsRestClassifier(clf_dict[clf], n_jobs=6)
	clf.fit(train, gold)
	preds = clf.predict(test)
	print(metrics.classification_report(test_y,preds, target_names = classes))
	prfs = metrics.precision_recall_fscore_support(test_y, preds, average='micro')
	acc = metrics.accuracy_score(test_y, preds)

	# if classifier == 'RFT':
		# print(clf.feature_importances_)
		# importances = pd.DataFrame({'feature':train.columns, 'importance': clf.feature_importances_})
		# importances = importances.sort_values('importance', ascending=False).set_index('feature')
		# print(importances)
	# auc = metrics.roc_auc_score(test_y, preds)
	# print('Area Under Curve', auc)
	# print(prfs, acc)
	for i in range(3):
		scores[i]+=prfs[i]
	scores[3]+=acc
	return preds

def get_baseline(lst, Y):
	preds = [lst] * len(Y)
	# print(mlb.classes_)
	preds = mlb.transform(preds)
	print(metrics.precision_recall_fscore_support(Y, preds, average='micro'))

def get_measurements(a,b):
	a = np.array(a)
	b = np.array(b)

	result = defaultdict(float)

	result['ACC'] = np.sum(a == b) / len(a)
	result['TP'] = np.sum(a + b == 2)
	result['TN'] = np.sum(a + b == 0)
	result['FN'] = np.sum(np.logical_and(a==0,b==1))
	result['FP'] = np.sum(np.logical_and(a==1,b==0))

	return result

def get_eval_metrics(results_dict):

	p_den = results_dict['TP'] + results_dict['FP']
	results_dict['P'] = results_dict['TP'] / (results_dict['TP'] + results_dict['FP']) if p_den > 0 else 0

	r_den = results_dict['TP'] + results_dict['FN']
	# results_dict['R'] = 2*(results_dict['TP'] / (results_dict['TP'] + results_dict['FN'])) if r_den > 0 else 0
	results_dict['R'] = results_dict['TP'] / (results_dict['TP'] + results_dict['FN']) if r_den > 0 else 0

	f_den = results_dict['P'] + results_dict['R']
	results_dict['F1'] = 2  * ((results_dict['P'] * results_dict['R'])  / (results_dict['P'] + results_dict['R'])) if f_den > 0 else 0

	return results_dict

def evaluate(pred,test):

	macro_scores = dict(zip(tags_list,[defaultdict(float)] * len(tags_list)))

	labels = ['ACC','TP','TN','FN','FP','P','R','F1','ACC']
	micro_scores = dict((element,0) for element in labels)
	macro_average = dict((element,0) for element in labels)

	for tag_idx,tag in enumerate(tags_list):
		curr_results = get_measurements(pred[:,tag_idx],test[:,tag_idx])

		macro_scores[tag] = curr_results
		macro_scores[tag] = get_eval_metrics(macro_scores[tag])

	print("Macro Scores:\nTag\tP\tR\tF1\tAcc")


	for tag in macro_scores:

		macro_average = dict(Counter(macro_average) + Counter(macro_scores[tag]))
		# print(Counter(macro_scores[tag]))
		# print(	str(tag[:5])							+"..\t"+\
		#		 str("%.2f" % macro_scores[tag]['P'])	+"\t"+	\
		#		 str("%.2f" % macro_scores[tag]['R'])	+"\t"+	\
		#		 str("%.2f" % macro_scores[tag]['F1'])	+"\t"+	\
		#		 str("%.2f" % macro_scores[tag]['ACC']))

	print(	"Averaged Macro Scores:\nP\tR\tF1\tAcc"				+"\n"+\
			str("%.2f" % (macro_average['P']/len(tags_list)))	+"\t"+\
			str("%.2f" % (macro_average['R']/len(tags_list)))	+"\t"+\
			str("%.2f" % (macro_average['F1']/len(tags_list)))	+"\t"+\
			str("%.2f" % (macro_average['ACC']/len(tags_list))))


	for instance_idx in range(len(pred)):
		curr_results = get_measurements(pred[instance_idx],test[instance_idx])
		micro_scores = dict(Counter(micro_scores) + Counter(curr_results))

	micro_scores = get_eval_metrics(micro_scores)
	micro_scores['ACC'] = micro_scores['ACC'] / pred.shape[0]

	print(	"Micro Scores:\nP\tR\tF1\tAcc"		+"\n"+	\
			str("%.2f" % micro_scores['P'])		+"\t"+	\
			str("%.2f" % micro_scores['R'])		+"\t"+	 \
			str("%.2f" % micro_scores['F1'])	+"\t"+	 \
			str("%.2f" % micro_scores['ACC']))

	for key in macro_average:
		macro_average[key] /= len(tags_list)
	return(micro_scores,macro_average)

def cross_validate(X,Y,cv_val, multi, classifier):


	print("Running " + str(cv_val) + " fold cross validation with classifier = " + classifier)

	labels = ['ACC','TP','TN','FN','FP','P','R','F1','ACC']

	total_micro = dict((element,0.0) for element in labels)
	total_macro = dict((element,0.0) for element in labels)

	if multi:
		# for i in range(cv_val):
		#
		#	 print("########################### Starting run no. " + str(i+1) + " ##############################")
		#	 print("Splitting datasets")
		#
		#	 X_splits = np.array_split(X,cv_val)
		#	 Y_splits = np.array_split(Y,cv_val)
		#
		#	 X_test = X_splits[i]
		#	 Y_test = Y_splits[i]
		#
		#	 del(X_splits[i])
		#	 del(Y_splits[i])
		#
		#	 X_train = np.concatenate(X_splits)
		#	 Y_train = np.concatenate(Y_splits)
		gkf = KFold(n_splits = cv_val, shuffle=True, random_state=0)
		for train_idx, test_idx in gkf.split(X, Y):
			if row_mode == "pandas" or row_mode == 'pd_out':
				X_train, X_test = X.iloc[train_idx], X.iloc[test_idx]
			else:
				X_train, X_test = X[train_idx], X[test_idx]
			Y_train, Y_test = Y[train_idx], Y[test_idx]
			print("Building model for multi cross val, shapes = %s, %s, %s, %s" %(X_train.shape, X_test.shape, Y_train.shape, Y_test.shape))
			pred = classify(X_train,Y_train,X_test,Y_test,True, classifier)
			print("Evaluating ...")
			eval_res = evaluate(pred, Y_test)
			#
			total_micro = dict(Counter(total_micro) + Counter(eval_res[0]))
			total_macro = dict(Counter(total_macro) + Counter(eval_res[1]))

	else:

		skf = StratifiedKFold(n_splits=cv_val, shuffle=True, random_state=0)
		print(skf)
		for train_idx, test_idx in skf.split(X, Y):
			if row_mode == "pandas" or row_mode == 'pd_out':
				X_train, X_test = X.iloc[train_idx], X.iloc[test_idx]
			else:
				X_train, X_test = X[train_idx], X[test_idx]
			Y_train, Y_test = Y[train_idx], Y[test_idx]

			# print(	"Dataset shapes:\n"+\
			#		 "Training X:\t" + str(X_train.shape)	 + "\n" + \
			#		 "Training Y:\t" + str(Y_train.shape)	+ "\n" + \
			#		 "Testing X:\t" + str(X_test.shape)		+ "\n" + \
			#		 "Testing Y:\t" + str(Y_test.shape))

			print("Starting Classification...")
			print(Y.shape)
			pred = classify(X_train, Y_train, X_test, Y_test, False, classifier)
			# pred = np.zeros(Y_test.shape)
			# for i in range(Y_train.shape[1]):
			#	 pred[:,i] = classify(X_train,Y_train[:,i],X_test,Y_test[:,i],False)

	print("#############################################################################")


	print(	"Final Averaged Results"					+"\n"+	\
			"P\tR\tF1\tAcc"							 +"\n"+	\
			"Averaged Micro Scores\n"+							\
			str("%.2f" % (total_micro['P']/cv_val))		+"\t"+	\
			str("%.2f" % (total_micro['R']/cv_val))		+"\t"+	\
			str("%.2f" % (total_micro['F1']/cv_val))	+"\t"+	\
			str("%.2f" % (total_micro['ACC']/cv_val))	+"\n"+	\
			"Averaged Macro Scores"					 +"\n"+	\
			str("%.2f" % (total_macro['P']/cv_val))		+"\t"+	\
			str("%.2f" % (total_macro['R']/cv_val))		+"\t"+	\
			str("%.2f" % (total_macro['F1']/cv_val))	+"\t"+	 \
			str("%.2f" % (total_macro['ACC']/cv_val)))

	print(["%.2f"%(score/cv_val) for score in scores])


np.set_printoptions(precision=3, suppress = True)
split = 0.8
kernel = 'poly'
cross_valid = 3

row_mode = config.get_row_mode()
feat_prefix = config.get_feat_prefix()

feats_files = {'submiss':'features-submissions.pickle', 'problem':'features.pickle', 'pandas':'features-pandas.pickle', \
				'pd_out':'features-pandas-no-outliers.pickle'}

feats_file = feats_files[row_mode]

feats_file = feat_prefix + feats_file

print("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", row_mode)

classes = []
mlb = None
divs = config.get_div()
ds_dir = config.get_ds_dir()
feat_modes = config.get_feat_modes()
classifiers = config.get_classifiers()
multi = config.get_multi()
algorithm_modes = config.get_algorithm_modes()
difficulties = config.get_difficulties()
# print(algorithm_mode, multi, row_mode)

out_file = open('out-classifier.csv', 'a')
for div, algo_mode, classifier, feat_mode, difficulty in product(divs, algorithm_modes, classifiers, feat_modes, difficulties):
	if algo_mode != 'categ':
		multi = False
	print("\n\n\n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", div)
	in_dir = ds_dir + div
	if multi:
		tags_file = in_dir + '-data-set.txt'
	else:
		tags_file = config.get_tags_file(in_dir, algo_mode)

	data = prepare_data(feats_file, tags_file, multi, row_mode, feat_mode, difficulty)
	X = data[0]
	Y = data[1]
	baseline = data[2]

	print("X Shape: ", X.shape)
	print("Y Shape: ", Y.shape)
	print(Y)
	print("No. of tags: ", len(tags_list), tags_list)
	print("Algo:", algo_mode)

	if multi:
		# get_baseline(['math', 'implementation', 'greedy', 'dp'], Y)
		get_baseline(['math', 'greedy', 'dp'], Y)
	scores = [0] * 4
	cross_validate(X,Y,cross_valid, multi, classifier)


	scores = ["%.2f"%(score/cross_valid) for score in scores]

	print(classes)

	timestamp = time.strftime("%Y/%m/%d %H:%M:%S")
	# out_file.write( '%s, %s, %d, %s, %s, %s, %s, %s, %s, %.2f, %s, %s, %s, %s, %s\n' \
	# 		% (row_mode, algo_mode, multi, div, classifier, scores[0], scores[1], scores[2], scores[3], baseline, timestamp, \
	# 		#':'.join(classes), ':'.join(col_names),
	#
	# 		':'.join(feat_mode), ':'.join(difficulty)))

	csv_file = open('test_csv.csv', 'a',  newline='')
	writer = csv.writer(csv_file, delimiter=',', quoting = csv.QUOTE_NONE)
	multi = 1 if multi else 0
	writer.writerow([row_mode, algo_mode, multi, div, classifier] + scores[0:3] +
	[format(baseline, '.2f'), timestamp,\
	 #':'.join(classes), ':'.join(col_names), \
	 ' ', ' ',
	 ':'.join(feat_mode), ':'.join(difficulty), X.shape[0]])
	csv_file.flush()
	out_file.flush()
out_file.close()
# if not os.path.exists('preds.pickle'):
#	 pred = classify(X_train,Y_train,X_test,True)
# else:
#	 f = open('preds.pickle', 'rb')
#	 pred = pickle.load(f)
