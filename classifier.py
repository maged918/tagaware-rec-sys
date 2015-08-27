import pickle


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