import pickle
import numpy as np


from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.multiclass import OneVsRestClassifier
from sklearn.svm import SVC

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

	Y = MultiLabelBinarizer().fit_transform(Y)
	return (X,Y)

def classify(train,gold,test, multi):

	if multi:
		clf = OneVsRestClassifier(SVC(kernel='poly'))
	else:
		clf = SVC(kernel='poly')

	clf.fit(train, gold)
	preds = clf.predict(test)
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

	metrics = ['ACC','TP','TN','FN','FP']
	micro_scores = dict((element,0.0) for element in metrics)
	print(micro_scores)

	for tag_idx,tag in enumerate(tags_list):
		curr_results = get_measurements(pred[:,tag_idx],test[:,tag_idx])

		macro_scores[tag] = curr_results
		macro_scores[tag] = get_eval_metrics(macro_scores[tag])

	print("Macro Scores:\nTag\tP\tR\tF1\tAcc")
	p=0
	r=0
	f=0
	a=0
	for tag in macro_scores:
		p += macro_scores[tag]['P']
		r += macro_scores[tag]['R']
		f += macro_scores[tag]['F1']
		a += macro_scores[tag]['ACC']

		print(	str(tag[:5])							+"..\t"+	\
				str("%.2f" % macro_scores[tag]['P'])	+"\t"+	\
				str("%.2f" % macro_scores[tag]['R'])	+"\t"+	\
				str("%.2f" % macro_scores[tag]['F1'])	+"\t"+	\
				str("%.2f" % macro_scores[tag]['ACC']))


	print(	"Averaged Macro Scores:\nP\tR\tF1\tAcc"	+"\n"+	\
			str("%.2f" % (p/len(tags_list)))		+"\t"+	\
			str("%.2f" % (r/len(tags_list)))		+"\t"+ 	\
			str("%.2f" % (f/len(tags_list)))		+"\t"+ 	\
			str("%.2f" % (a/len(tags_list))))


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




# str("%.2f" % avg_p) + "\n")

global kernel
global split
global cross_valid


split = 0.8
kernel = 'poly'
feats_file = 'features.pickle'
tags_file = 'data-set.txt'
cross_valid = 10

data = prepare_data(feats_file, tags_file)
X = data[0]
Y = data[1]


xsplit = int(split * len(X))
ysplit = int(split * len(Y))

X_train = X[xsplit:]
X_test = X[:xsplit]

Y_train = Y[ysplit:]
Y_test = Y[:ysplit]



pred = classify(X_train,Y_train,X_test,True)

evaluate(pred, Y_test)

# if not os.path.exists('preds.pickle'):
# 	pred = classify(X_train,Y_train,X_test,True)
# else:
# 	f = open('preds.pickle', 'rb')
# 	pred = pickle.load(f)