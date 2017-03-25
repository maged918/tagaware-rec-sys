import pandas as pd
import numpy as np

def build_tags(tags_file, difficulties=['A', 'B', 'C', 'D', 'E']):
	tags_list = []
	delete_keys = set()
	inst_tags = {}
	with open(tags_file) as f:
		for line in f:
			if line != "\n":

				arr = line.split("\n")[0].split(":")
				key = arr[0]
				difficulty = key.split('/')[1]
				if difficulty not in difficulties:
					delete_keys.add(key)
					continue
				tags = arr[1].split(',')
				if arr[1]:
					inst_tags[key] = tags
					tags_list += tags
				else:
					# if key in inst_feats:
					delete_keys.add(key)
						# del inst_feats[key]

	tags_list = list(set(tags_list))
	return tags_list, delete_keys, inst_tags

def create_df(inst_feats, inst_tags, delete_keys, multi=False):
	inst_feats = inst_feats[inst_feats.problem_id.isin(list(delete_keys)) == False]
	inst_feats = inst_feats[inst_feats.problem_id.isin(list(inst_tags.keys()))]

	# print('456/B' in delete_keys)
	# X = inst_feats[inst_feats.columns.difference(['id', 'problem_id'])]
	X = inst_feats.copy().drop(['id', 'problem_id'], axis=1)
	Y = inst_feats['problem_id'].map(lambda x: inst_tags[x]).values
	if not multi:
		Y = np.hstack(Y)

	tags_df = pd.DataFrame.from_dict({x: y for x, y in enumerate(list(Y))}, orient='index')
	inst_feats = inst_feats.assign(tags=tags_df.loc[:,[0]])
	return inst_feats, X, Y
