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
from sklearn.model_selection import StratifiedKFold
from sklearn.naive_bayes import MultinomialNB
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import SelectKBest, chi2, f_classif

from collections import defaultdict
from collections import Counter
from itertools import product
import time

import config

def prepare_data(feats_file,tags_file, multi, row_mode):

	f = open(feats_file, 'rb')
	inst_feats = pickle.load(f)

	# print(type(inst_feats))

	inst_tags = {}
	global tags_list, classes, mlb
	tags_list = []

	with open(tags_file) as f:
		for line in f:
			if line != "\n":

				arr = line.split("\n")[0].split(":")
				key = arr[0]
				tags = arr[1].split(',')
				if arr[1]:
					inst_tags[key] = tags
					tags_list += tags
				else:
					if key in inst_feats:
						del inst_feats[key]

	tags_list = list(set(tags_list))

	X = []
	Y = []

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
	Y = np.array(Y)

	X = choose_columns(X, Y)

	print(X.shape)
	# feature scaling

	# X-=np.mean(X)
	# if np.std(X) > 0:
	# 	X/=np.std(X)
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

def choose_columns(X, y):
	# for i in range(15,X.shape[1]-1):
	# 	X = np.delete(X, i, 1)
	# X = np.delete(X, [19,20,21,22,23], 1)
	# X = SelectKBest(f_classif, k = 20).fit_transform(X, y)
	return X

def classify(train,gold,test, test_y,multi, classifier):

	svm_dict = {'random_state':0, 'class_weight':{0:2,1:8}, 'C':1, 'dual':False}
	# svm_dict = {}
	clf_dict = {'SVM': svm.LinearSVC(**svm_dict), 'RFT': RandomForestClassifier(n_estimators=50), 'ADA': AdaBoostClassifier(n_estimators = 50),\
						'KNN': KNeighborsClassifier(n_neighbors = 20, weights='distance'), 'LRC': LogisticRegression()}
	clf = classifier

	clf = OneVsRestClassifier(clf_dict[clf])
	# clf = OneVsRestClassifier(MLPClassifier(random_state=0, hidden_layer_sizes=(100,100)))
	# print(clf)
	clf.fit(train, gold)
	preds = clf.predict(test)
	# print(metrics.classification_report(test_y,preds, target_names = classes))
	prfs = metrics.precision_recall_fscore_support(test_y, preds, average='weighted')
	acc = metrics.accuracy_score(test_y, preds)
	# print(prfs, acc)
	for i in range(3):
		scores[i]+=prfs[i]
	scores[3]+=acc
	return preds

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
		# 		str("%.2f" % macro_scores[tag]['P'])	+"\t"+	\
		# 		str("%.2f" % macro_scores[tag]['R'])	+"\t"+	\
		# 		str("%.2f" % macro_scores[tag]['F1'])	+"\t"+	\
		# 		str("%.2f" % macro_scores[tag]['ACC']))

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
			str("%.2f" % micro_scores['R'])		+"\t"+ 	\
			str("%.2f" % micro_scores['F1'])	+"\t"+ 	\
			str("%.2f" % micro_scores['ACC']))

	for key in macro_average:
		macro_average[key] /= len(tags_list)
	return(micro_scores,macro_average)


def cross_validate(X,Y,cv_val, multi, classifier):


	print("Running " + str(cv_val) + " fold cross validation with classifier = " + classifier)

	labels = ['ACC','TP','TN','FN','FP','P','R','F1','ACC']

	total_micro = dict((element,0.0) for element in labels)
	total_macro = dict((element,0.0) for element in labels)

	skf = StratifiedKFold(n_splits=cv_val, random_state=0)
	print(skf)

	if multi:
		for i in range(cv_val):

			print("########################### Starting run no. " + str(i+1) + " ##############################")
			print("Splitting datasets")

			X_splits = np.array_split(X,cv_val)
			Y_splits = np.array_split(Y,cv_val)

			X_test = X_splits[i]
			Y_test = Y_splits[i]

			del(X_splits[i])
			del(Y_splits[i])

			X_train = np.concatenate(X_splits)
			Y_train = np.concatenate(Y_splits)
			print("Building model")
			pred = classify(X_train,Y_train,X_test,Y_test,True, classifier)
			print("Evaluating ...")
			eval_res = evaluate(pred, Y_test)
			#
			total_micro = dict(Counter(total_micro) + Counter(eval_res[0]))
			total_macro = dict(Counter(total_macro) + Counter(eval_res[1]))

	else:
		for train_idx, test_idx in skf.split(X, Y):

			X_train, X_test = X[train_idx], X[test_idx]
			Y_train, Y_test = Y[train_idx], Y[test_idx]

			# print(	"Dataset shapes:\n"+\
			# 		"Training X:\t" + str(X_train.shape) 	+ "\n" + \
			# 		"Training Y:\t" + str(Y_train.shape)	+ "\n" + \
			# 		"Testing X:\t" + str(X_test.shape)		+ "\n" + \
			# 		"Testing Y:\t" + str(Y_test.shape))

			print("Starting Classification...")

			pred = classify(X_train, Y_train, X_test, Y_test, False, classifier)
			# pred = np.zeros(Y_test.shape)
			# for i in range(Y_train.shape[1]):
			# 	pred[:,i] = classify(X_train,Y_train[:,i],X_test,Y_test[:,i],False)

	print("#############################################################################")


	print(	"Final Averaged Results"					+"\n"+	\
			"P\tR\tF1\tAcc" 							+"\n"+	\
			"Averaged Micro Scores\n"+							\
			str("%.2f" % (total_micro['P']/cv_val))		+"\t"+	\
			str("%.2f" % (total_micro['R']/cv_val))		+"\t"+	\
			str("%.2f" % (total_micro['F1']/cv_val))	+"\t"+	\
			str("%.2f" % (total_micro['ACC']/cv_val))	+"\n"+	\
			"Averaged Macro Scores" 					+"\n"+	\
			str("%.2f" % (total_macro['P']/cv_val))		+"\t"+	\
			str("%.2f" % (total_macro['R']/cv_val))		+"\t"+	\
			str("%.2f" % (total_macro['F1']/cv_val))	+"\t"+ 	\
			str("%.2f" % (total_macro['ACC']/cv_val)))

	print(["%.2f"%(score/cv_val) for score in scores])
# str("%.2f" % avg_p) + "\n")

np.set_printoptions(precision=3, suppress = True)
split = 0.8
kernel = 'poly'
cross_valid = 3
# algorithm_modes = ['categ', 'graph', 'maths', 'algos', 'pairs']
algorithm_modes = ['pairs']
# algorithm_modes = ['categ']
# classifiers = ['RFT']
classifiers = ['SVM', 'RFT']
# classifiers = ['ADA']
multi=True

row_mode = 'submiss'
if row_mode == 'submiss':
	feats_file = 'features-submissions.pickle'
elif row_mode == 'problem':
	feats_file = 'features.pickle'

print("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", row_mode)

classes = []
mlb = None
divs = config.get_div()
ds_dir = config.get_ds_dir()
tags_file_dict = {'categ': 'data-set-single.txt', 'graph':'data-set-graphs.txt', 'maths': 'data-set-maths.txt', 'algos': 'data-set-algo.txt', 'pairs': 'data-set-pair.txt'}
# print(algorithm_mode, multi, row_mode)

out_file = open('out-classifier.csv', 'a')
for div, algo_mode, classifier in product(divs, algorithm_modes, classifiers):
	if algo_mode != 'categ':
		multi = False
	print("\n\n\n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", div)
	in_dir = ds_dir + div
	if multi:
		tags_file = in_dir + '-data-set.txt'
	else:
		tags_file = in_dir + '-' + tags_file_dict[algo_mode]

	data = prepare_data(feats_file, tags_file, multi, row_mode)
	X = data[0]
	Y = data[1]
	baseline = data[2]

	print("X Shape: ", X.shape)
	print("Y Shape: ", Y.shape)
	print(Y)
	print("No. of tags: ", len(tags_list), tags_list)
	print("Algo:", algo_mode)
	scores = [0] * 4
	cross_validate(X,Y,cross_valid, multi, classifier)

	scores = ["%.2f"%(score/cross_valid) for score in scores]

	print(classes)

	timestamp = time.strftime("%Y/%m/%d %H:%M:%S")
	out_file.write( '%s, %s, %d, %s, %s, %s, %s, %s, %s, %.2f, %s, %s\n' \
			% (row_mode, algo_mode, multi, div, classifier, scores[0], scores[1], scores[2], scores[3], baseline, timestamp, ':'.join(classes)))

	out_file.flush()
out_file.close()
# if not os.path.exists('preds.pickle'):
# 	pred = classify(X_train,Y_train,X_test,True)
# else:
# 	f = open('preds.pickle', 'rb')
# 	pred = pickle.load(f)
