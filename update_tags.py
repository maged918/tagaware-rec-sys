import os.path
from collections import defaultdict
import config
import numpy as np
# from itertools import combinations_with_replacement, product
'''
author: tarek, maged
date: Aug 26th 2015
desc: parses Problems-tags.txt to produce a file with the problem path alongside its associated tags, to be fed later into the classification module
'''

categories = {
'math': ['matrices', 'probabilities', 'combinatorics', 'number theory', 'chinese remainder theorem', 'games', 'geometry'],
'graphs': ['dfs and similar', 'trees', 'shortest paths', 'graph matchings', 'flows'],
'': ['bitmasks', 'hashing', 'ternary search','meet-in-the-middle', 'divide and conquer', '2-sat','schedules'\
,'fft', 'two pointers', 'binary search', 'strings', 'expression parsing', 'string suffix structures'],
# 'strings':['expression parsing', 'string suffix structures'],
'implementation': [],
'greedy': ['constructive algorithms', 'sortings'],
'data structures': ['dsu']
}

cat_list = sorted(['dp', 'data structures', 'implementation', 'greedy', 'brute force', 'math', 'graphs'])

# categories[''] = categories['']+['implementation']
# categories[''] = categories['']+['brute force']

# print(categories[''])

algos = []
algos+=categories['math']
algos+=categories['graphs']

remove_algorithms = ['graph matchings', 'chinese remainder theorem']

single_sorting = ['implementation', 'brute force', 'sortings', 'greedy', 'math', 'dp', 'data structures', 'graphs', 'geometry', 'strings', 'binary search']
single_dict = {}

# pairs=['math', 'graphs']
# pairs = ['dp', 'brute force']
# pairs = ['dp', 'greedy']

pairs = [['math', 'graphs'], ['dp', 'brute force'], ['dp', 'greedy'], ['dp', 'dfs and similar'], ['data structures', 'graphs'], ['graphs', 'trees'], ['number theory', 'combinatorics']]

for i in range(len(single_sorting)):
	single_dict[single_sorting[i]] = i
single_dict = defaultdict(lambda: 0, single_dict)

to_category = {}
to_category = defaultdict(lambda: 0, to_category)

# feed tag rules in here
def update_tag(tag):
	for category in categories:
		if tag in categories[category]:
			tag = category
	return tag

def single_tag(tag_list):
	tag_so_far = ''
	idx = -1
	for tag in tag_list:
		if single_dict[tag] > idx:
			idx = single_dict[tag]
			tag_so_far = tag
	return tag_so_far

divs = config.get_div()
ds_dir = config.get_ds_dir()
tags_file = open('dataset/Tags-Counts.txt', 'w')
print(divs)

for div in divs:
	tags_file.write("#################################################\n" + div + '\n')
	pt_file = 'dataset/pt_sub/' + div + '-Problems-tags.txt'
	out_dir = ds_dir + div
	out_file = open(out_dir + "-data-set.txt",'w')
	single_file = open(out_dir + '-data-set-single.txt', 'w')
	graphs_file = open(out_dir + '-data-set-graphs.txt', 'w')
	maths_file = open(out_dir + '-data-set-maths.txt', 'w')
	algo_file = open(out_dir + '-data-set-algo.txt', 'w')
	# pair_file = open(out_dir + '-data-set-pair.txt', 'w')
	pair_files = []
	for pair in pairs:
		pair_files.append(open(out_dir+'-data-set-%s_%s.txt' % (pair[0], pair[1]), 'w'))

	only_files = []
	for category in cat_list:
		only_files.append(open(out_dir + '-data-set-only-%s.txt'%category, 'w'))

	files = [out_file, single_file, graphs_file, maths_file, algo_file]+pair_files + only_files

	count_tags = defaultdict()
	count_tags = defaultdict(lambda: 0, count_tags)

	count_pairs = defaultdict()
	count_pairs = defaultdict(lambda: 0, count_pairs)

	single_tags = defaultdict()
	single_tags = defaultdict(lambda: 0, single_tags)

	all_tags = defaultdict()
	all_tags = defaultdict(lambda:0, all_tags)

	with open(pt_file) as f:
		path = ''
		for line in f:
			if line != "\n":
				arr_line = line.split("\n")[0].split(" ")
				if arr_line[0].lower() == 'contest':
					path += arr_line[2] + "/"

				if arr_line[0].lower() == "index:":
					path += arr_line[1]

				if arr_line[0].lower() == "tags:":
					for ff in files:
						ff.write(path+":")
					string = ''
					tags = line.split(':')[1].strip()
					tags_list = [tag.strip() for tag in tags.split(',')]

					graphs_tag = ''
					maths_tag = ''
					algo_tag = ''
					pair_tags = [''] * len(pairs)
					only_tags = defaultdict(lambda: 'other')

					for i in tags_list:
						if i in categories['graphs'] and i not in remove_algorithms: #HANDLE IF MORE THAN ONE TAG
							graphs_tag = i
						if i in categories['math'] and i not in remove_algorithms:
							maths_tag = i
						if i in algos and i not in remove_algorithms:
							algo_tag = i
						for pair_idx in range(len(pairs)):
							first = pairs[pair_idx][0]
							second = pairs[pair_idx][1]
							if (i == first and second not in tags_list) or (i == second and first not in tags_list):
								pair_tags[pair_idx] = i

						if i in cat_list:
							only_tags[i] = i
						for cat, vals in categories.items():
							if i in vals:
								only_tags[cat] = cat

						all_tags[i]+=1

					# print(tags_list, only_tags)

					if len(tags_list) == 1:
						single_tags[tags_list[0]]+=1
					tags_list = [update_tag(tag) for tag in tags_list if update_tag(tag)!='']
					# print(tags_list)
					for i in tags_list:
						string += i + ","
						count_tags[i]+=1
					for pair in [(x,y) for x in tags_list for y in tags_list if x>y]:
						count_pairs[pair]+=1

					single = single_tag(tags_list)
					single_file.write(single + "\n")
					out_file.write(string[:-1] + "\n")
					graphs_file.write(graphs_tag + "\n")
					maths_file.write(maths_tag + "\n")
					algo_file.write(algo_tag + "\n")

					# greedy_file.write(only_tags['greedy'] + "\n")
					for idx in range(len(pairs)):
						pair_files[idx].write(pair_tags[idx] + "\n")
					for idx, category in enumerate(cat_list):
						# print(only_files[idx], category)
						only_files[idx].write(only_tags[category] + "\n")
			else:
				path = ''

	tags_file.write('################ All Tags ################\n')
	all_tag_count = np.sum(list(all_tags.values()))
	tags_file.write("%d\n" % (all_tag_count))
	for tag in sorted(all_tags.items(), key=lambda x: x[1], reverse=True):
		tags_file.write("%s, %s, %.2f%s" % (tag[0], tag[1], tag[1]/all_tag_count, '\n'))

	tags_file.write('################ Single Tags Occuring Alone ################\n')
	for tag in sorted(single_tags.items(), key = lambda x:x[1], reverse=True):
		tags_file.write("%s, %s%s" % (tag[0], tag[1], '\n'))

	tags_file.write('################ Output Tags ################\n')
	for tag in sorted(count_tags.items(), key=lambda x: x[1], reverse=True):
		tags_file.write("%s, %s%s" % (tag[0], tag[1], '\n'))

	tags_file.write('################ Output max pairs ################\n')
	for pair in sorted(count_pairs.items(), key=lambda x:x[1], reverse=True):
		if pair[1] > 20:
			tags_file.write("%s, %s%s" % (pair[0], pair[1], '\n'))

tags_file.close()
	# print(len(single_tags))
lst = [str.title(item[0]) for item in sorted(all_tags.items(), key=lambda x : x[1], reverse=True) if item[0]!='']
for i in range(0,len(lst),3):
	# print(lst[i:i+3])
	try:
		print(lst[i], '&', lst[i+1], '&', lst[i+2], '\\\\ \\midrule')
	except IndexError:
		print(lst[i], '&', lst[i+1], '\\\\ \\midrule')
# print(str(lst).replace('\'', ''))