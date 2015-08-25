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


1. single loop
2. 2 nested loops
3. 3 nested loops
4. if in loop
5. return array inside if
6. recursion
7. shift operator
8. or operator
9. and operator
10. no. of int vars
11. no. of double/float vars
12. no. of Strings vars
13. no. of lists/vectors vars
14. no. of params per method (avg)
15. no. of functions
16. no. of arithmetic operations
16. names of variables classes and methods -> word clusters


'''

from collections import defaultdict
from lxml import etree

import requests
import sys
import os
import numpy as np


def evalute(*args):
	query = './'
	for arg in args:
		query += arg
	return len(tree.xpath(query))


def extract_feats(file):

	curr_feats = []

	tree = etree.parse(file)

	# features 1,2 and 3
	single_loop = evalute(WHILE) + evalute(FOR)
	if single_loop > 0:
		double_loop = evalute(WHILE,FOR) + evalute(FOR,WHILE) + evalute(FOR,FOR) + evalute(WHILE,WHILE)
		if double_loop == 0:
			curr_feats += [single_loop,0,0]

		else:
			triple_loop =	evalute(WHILE,WHILE,WHILE) 	+ evalute(WHILE,WHILE,FOR) + evalute(WHILE,FOR,WHILE) + evalute(WHILE,FOR,FOR) +
							evalute(FOR,WHILE,WHILE)	+ evalute(FOR,WHILE,FOR) + evalute(FOR,FOR,WHILE) + evalute(FOR,FOR,FOR)
			if triple_loop == 0:
				curr_feats += [0,double_loop,0]
			else:
				curr_feats += [0,0,triple_loop]


	# feature 4
	curr_feats.append(evalute(FOR,IF) + evalute(WHILE,IF))

	# feature 5

	# feature 6

	# feature 7: could be in a declared statement, or an expression (cin and cout should be excluded)
	for expr in tree.xpath(".//expr"):
		right_shifts = 0
		if expr.getchildren()[0].text =="cin":
			for child in expr.getchildren():
				if child.text == ">>":
					right_shifts += 1

		left_shifts = 0
		if expr.getchildren()[0].text =="cout":
			for child in expr.getchildren():
				if child.text == "<<":
					left_shifts += 1

	shifts = len(tree.xpath(".//operator[text()='>>']"))  + len(tree.xpath(".//operator[text()='<<']")) - left_shifts - right_shifts
	curr_feats.append(shifts | shifts > 0)
	if shifts > 0:
		curr_feats.append(shifts)
	else:
		curr_feats.append(0)

	# feature 8
	curr_feats.append(len(tree.xpath(".//operator[text()='&']")))

	# feature 9
	curr_feats.append(len(tree.xpath(".//operator[text()='|']")))


FOR='/for/block/'
WHILE='/while/block/'
IF='/if/block'
FUNCTION='/function'
NAME='/name'
RETURN='/block/return'

data_dir = sys.argv[1]

feature_set = {}
for contest in next(os.walk(data_dir))[1]:
	for problem in next(os.walk(data_dir+"/"+contest))[1]:
		problem_features =  []
		for submission in os.listdir(data_dir+"/"+contest+"/"+problem):
			if submission.endswith(".xml"):
				problem_features.append(extract_feats(submission))
		arr = np.asarray(problem_features)
		arr.astype(float)
		avg = np.average(arr, axis=0)
		feature_set[contest + "_" + problem] = avg





