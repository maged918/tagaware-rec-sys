'''
Created on Aug 1, 2015

@author: maged, tarek
'''

'''
Categories:
Graphs, DP, Strings, Data Structures, Maths, Geometry
Features, tags, problems
Feature-problems vector (numerical)
Tags-problems vector (boolean)
'''

'''
Feature 1: if inside while (binary search, kmp)
Feature 2: bag of words, {dp, mid, lo, hi, graph, query, update, solve, point, line} (binary search, graphs, segment trees)
Feature 3: return value from array inside if AND inside recursive method (dp)
Feature 4: Shifting, or'ing, and'ing (bitmask --> DP/Brute Force/Math)
Feature 5: Number of methods/ Creation of classes (data structures/graphs)
Feature 6: Recursion (dp, complete search, graphs)
Feature 7: Average number of parameters per method (data structures, graphs, dp)
Feature 8: Number of variables (geometry, graphs, binary search)


single loop
2 nested loops
3 nested loops
if in loop
return array inside if
recursion
3shift operator
or operator
and operator
no. of int vars
no. of double/float vars
no. of Strings vats
no. of lists/vectors vars
no. of params per method
names of variables classes and methods -> word clusters


'''

from collections import defaultdict
from lxml import etree

import requests
import sys
import os
import numpy as np



def extract_feats(file):

	# return [1,2,3]



data_dir = sys.argv[1]

feature_set = {}
for contest in next(os.walk(data_dir))[1]:
	for problem in next(os.walk(data_dir+"/"+contest))[1]:
		problem_features = []
		for submission in os.listdir(data_dir+"/"+contest+"/"+problem):
			if submission.endswith(".xml"):
				problem_features.append(extract_feats(submission))
		arr = np.asarray(problem_features)
		arr.astype(float)
		avg = np.average(arr, axis=0)
		feature_set[contest + "_" + problem] = avg

# etree = etree.parse(file)
# len(tree.xpath('.//for/block/if'))




