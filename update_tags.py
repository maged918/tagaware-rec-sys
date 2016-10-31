import os.path
from collections import defaultdict
# from itertools import combinations_with_replacement, product
'''
author: tarek, maged
date: Aug 26th 2015
desc: parses Problems-tags.txt to produce a file with the problem path alongside its associated tags, to be fed later into the classification module
'''

to_math = ['matrices', 'probabilities', 'combinatorics', 'number theory', 'chinese remainder theorem', 'games']
to_graphs = ['dfs and similar', 'trees', 'shortest paths', 'graph matchings', 'flows']
to_remove = ['bitmasks', 'dsu', 'hashing', 'ternary search','meet-in-the-middle', 'divide and conquer', '2-sat','schedules'\
,'fft', 'two pointers', 'sortings', 'greedy', 'constructive algorithms', 'binary search', 'brute force']
# to_remove = []
to_strings = ['expression parsing', 'string suffix structures']
to_implementation = []

single_sorting = ['implementation', 'sortings', 'brute force', 'greedy', 'math', 'dp', 'data structures', 'graphs', 'geometry', 'strings', 'binary search']
single_dict = {}
for i in range(len(single_sorting)):
	single_dict[single_sorting[i]] = i

# feed tag rules in here
def update_tag(tag):
	if tag in to_math:
		tag = 'math'
	elif tag in to_graphs:
		tag = 'graphs'
	elif tag in to_strings:
		tag = 'strings'
	elif tag in to_implementation:
		tag = 'implementation'
	elif tag in to_remove:
		tag = ''
	return tag

def single_tag(tag_list):
	tag_so_far = ''
	idx = -1
	for tag in tag_list:
		if single_dict[tag] > idx:
			idx = single_dict[tag]
			tag_so_far = tag
	return tag_so_far

out_file = open("data-set.txt",'w')
single_file = open('data-set-single.txt', 'w')

count_tags = defaultdict()
count_tags = defaultdict(lambda: 0, count_tags)

count_pairs = defaultdict()
count_pairs = defaultdict(lambda: 0, count_pairs)

single_tags = defaultdict()
single_tags = defaultdict(lambda: 0, single_tags)



with open("Problems-tags.txt") as f:

	path = ''
	for line in f:
		if line != "\n":
			arr_line = line.split("\n")[0].split(" ")
			if arr_line[0].lower() == 'contest':
				path += arr_line[2] + "/"

			if arr_line[0].lower() == "index:":
				path += arr_line[1]

			if arr_line[0].lower() == "tags:":
				out_file.write(path +":")
				single_file.write(path +":")
				string = ''
				tags = line.split(':')[1].strip()
				tags_list = tags.split(',')
				tags_list = [update_tag(tag.strip()) for tag in tags_list if update_tag(tag.strip())!='']
				for i in tags_list:
					string += i + ","
					count_tags[i]+=1
				for pair in [(x,y) for x in tags_list for y in tags_list if x>y]:
					# print(pair)
					count_pairs[pair]+=1
				if len(tags_list) == 1:
					single_tags[tags_list[0]]+=1
				# if '' not in tags_list:
				out_file.write(string[:-1] + "\n")
				single = single_tag(tags_list)
				single_file.write(single + "\n")
		else:
			path = ''

for tag in sorted(count_tags.items(), key=lambda x: x[1], reverse=True):
	print(tag[0], tag[1])

for pair in sorted(count_pairs.items(), key=lambda x:x[1], reverse=True):
	if pair[1] > 20:
		print(pair[0], pair[1])

for tag in sorted(single_tags.items(), key = lambda x:x[1], reverse=True):
	print(tag[0], tag[1])

print(len(single_tags))
