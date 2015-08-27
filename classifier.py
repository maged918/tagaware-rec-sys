import pickle
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.multiclass import OneVsRestClassifier
from sklearn.svm import SVC

f = open('features.pickle', 'rb')
features = pickle.load(f)


labelled_tags = {}
tags_list = []

with open("train-tags.txt") as f:
	for line in f:
		if line != "\n":

			arr = line.split("\n")[0].split(":")
			labelled_tags[arr[0]] = arr[1].split(',')
			tags_list += arr[1].split(',')

tags_list = list(set(tags_list))

X_train=[]
Y_train=[]

for instance in features:
	X_train.append(features[instance])
	tags = []
	for tag in labelled_tags[instance]:
		tags.append(tags_list.index(tag))
	Y_train.append(tags)

Y_train = MultiLabelBinarizer().fit_transform(Y_train)

clf = OneVsRestClassifier(SVC(kernel='poly'))
clf.fit(X_train, Y_train)
y = clf.predict(X_train)