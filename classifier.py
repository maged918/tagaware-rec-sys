import pickle
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.multiclass import OneVsRestClassifier
from sklearn.svm import SVC


def prepare_data(feats_file,tags_file,multi):

	f = open(feats_file, 'rb')
	features = pickle.load(f)


	labelled_tags = {}
	tags_list = []

	with open(tags_file) as f:
		for line in f:
			if line != "\n":

				arr = line.split("\n")[0].split(":")
				labelled_tags[arr[0]] = arr[1].split(',')
				tags_list += arr[1].split(',')

	tags_list = list(set(tags_list))

	X=[]
	Y=[]


	for instance in features:
		X.append(features[instance])
		tags = []
		for tag in labelled_tags[instance]:
			tags.append(tags_list.index(tag))
		Y.append(tags)

	if multi:
		Y = MultiLabelBinarizer().fit_transform(Y)

	X_train = X[:split]
	X_test = X[split:]

	Y_train = Y[:split]
	Y_test = Y[split:]

	return (X_train,X_test,Y_train,Y_test)


def classify(train,test, multi):

	if multi:
		clf = OneVsRestClassifier(SVC(kernel='poly'))
	else:
		clf = SVC(kernel='poly')

	clf.fit(train, test)
	preds = clf.predict(test)
	return preds


def evaluate(tags_list,pred,test):

	tags_eval = dict(zip(tags_list,[defaultdict(float)] * len(tags_list)))

	# for micro f1
	metrics = ['TN','TP','FP','FN','P','R','F1']
	micro = dict(zip(metrics,[0.0] * len(metrics)))


	for instance_idx in len(Y_pred):

		curr_pred = pred[instance_idx]
		curr_gold = test[instance_idx]

		for tag_idx in len(curr_pred):
			tag = tags_list[tag_idx]

			if curr_pred[tag_idx] == 1:
				if curr_res[tag_idx] == 1:
					tags_eval[tag]['TP']+= 1
					micro['TP'] += 1
				else:
					tags_eval[tag]['FP']+= 1
					macrp['FP'] += 1
			else:
				if curr_res[tag_idx] == 1:
					tags_eval[tag]['FN']+= 1
					micro['FN'] += 1
				else:
					tags_eval[tag]['TN']+= 1
					micro['TN'] += 1

	#micro

	for tag in tags_eval:
		tags_eval[tag]['P'] = tags_eval[tag]['TP'] / (tags_eval[tag]['TP'] + tags_eval[tag]['FP'])
		tags_eval[tag]['R'] = tags_eval[tag]['TP'] / (tags_eval[tag]['TP'] + tags_eval[tag]['FN'])
		tags_eval[tag]['F1'] = 2 * tags_eval[tag]['P'] * tags_eval[tag]['R']  / tags_eval[tag]['P'] + tags_eval[tag]['R']

	#micro
	micro['P'] = micro['TP'] / (micro['TP'] + micro['FP'])
	micro['R'] = micro['TP'] / (micro['TP'] + micro['FN'])
	micro['F1'] = 2 * micro['P'] * micro['R']  / micro['P'] + micro['R']



global split = 0.8
global kernel = 'poly'
feats_file = 'features.pickle'
tags_file = 'data-set.txt'


date = prepare_data(features, tags_file, True)



