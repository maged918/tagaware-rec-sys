'''
Created on Aug 23, 2015

@author: tarek
'''


import pickle
import numpy as np

from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.multiclass import OneVsRestClassifier
from sklearn import svm
from sklearn import metrics
from sklearn.neural_network import MLPClassifier

from collections import defaultdict
from collections import Counter

def prepare_data(feats_file,tags_file):

	f = open(feats_file, 'rb')
	inst_feats = pickle.load(f)


	inst_tags = {}
	global tags_list
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
					del inst_feats[key]

	tags_list = list(set(tags_list))

	X = []
	Y = []

	for instance in inst_feats:

		X.append(inst_feats[instance])
		Y.append(inst_tags[instance])


	X = np.array(X)
	Y = np.array(Y)

	# feature scaling
	for col in range(X.shape[1]):
		X[:,col] /= X.shape[1]


	Y = MultiLabelBinarizer().fit_transform(Y)
	return (X,Y)

def classify(train,gold,test, test_y,multi):

	if multi:
		# clf = OneVsRestClassifier(MLPClassifier())
		clf = OneVsRestClassifier(svm.SVC(kernel='linear', class_weight={0:0.1,1:0.9}))
	else:

		if np.sum(gold) <= 1:
			return np.zeros(test.shape[0])
		clf = svm.SVC()

	clf.fit(train, gold)
	# print(clf)
	preds = clf.predict(test)
	# print(np.sum(gold))
	# print(train.shape, gold.shape, test.shape, test_y.shape, preds.shape)
	# print(gold, test_y)
	# for i in range(len(preds)):
	# 	print(preds[i], test_y[i])
	print(metrics.classification_report(test_y,preds))
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
	results_dict['R'] = 2*(results_dict['TP'] / (results_dict['TP'] + results_dict['FN'])) if r_den > 0 else 0

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


def cross_validate(X,Y,cv_val, multi):


	print("Running " + str(cv_val) + " fold cross validation")

	labels = ['ACC','TP','TN','FN','FP','P','R','F1','ACC']

	total_micro = dict((element,0.0) for element in labels)
	total_macro = dict((element,0.0) for element in labels)

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


		# print(	"Dataset shapes:\n"+\
		# 		"Training X:\t" + str(X_train.shape) 	+ "\n" + \
		# 		"Training Y:\t" + str(Y_train.shape)	+ "\n" + \
		# 		"Testing X:\t" + str(X_test.shape)		+ "\n" + \
		# 		"Testing Y:\t" + str(Y_test.shape))

		print("Starting Classification...")

		if multi:
			pred = classify(X_train,Y_train,X_test,Y_test,True)
		else:

			pred = np.zeros(Y_test.shape)
			for i in range(Y_train.shape[1]):
				pred[:,i] = classify(X_train,Y_train[:,i],X_test,Y_test,False)


		print("Evaluating ...")
		eval_res = evaluate(pred, Y_test)

		total_micro = dict(Counter(total_micro) + Counter(eval_res[0]))
		total_macro = dict(Counter(total_macro) + Counter(eval_res[1]))

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
# str("%.2f" % avg_p) + "\n")

split = 0.8
kernel = 'poly'
feats_file = 'features.pickle'
tags_file = 'data-set.txt'
cross_valid = 5

data = prepare_data(feats_file, tags_file)
X = data[0]
Y = data[1]

print("X Shape: ", X.shape)
print("Y Shape: ", Y.shape)
print("No. of tags: ", len(tags_list))
cross_validate(X,Y,cross_valid, True)

# if not os.path.exists('preds.pickle'):
# 	pred = classify(X_train,Y_train,X_test,True)
# else:
# 	f = open('preds.pickle', 'rb')
# 	pred = pickle.load(f)
