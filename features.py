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
16. names of variables classes and methods -> word clusters (LATERZZ)

'''

from collections import defaultdict
from lxml import etree

import sys
import os
import numpy as np


def evalute(tree,*args):
	query = './'
	for arg in args:
		query += arg
	return len(tree.xpath(query[:-1]))


def extract_feats(file):

	curr_feats = []

	tree = etree.parse(file)

	# features 1,2 and 3
	single_loop = evalute(tree,WHILE) + evalute(tree,FOR)
	if single_loop > 0:
		double_loop = evalute(tree,WHILE,FOR) + evalute(tree,FOR,WHILE) + evalute(tree,FOR,FOR) + evalute(tree,WHILE,WHILE)
		if double_loop == 0:
			curr_feats += [single_loop,0,0]

		else:
			triple_loop = evalute(tree,WHILE,WHILE,WHILE) + evalute(tree,WHILE,WHILE,FOR) + evalute(tree,WHILE,FOR,WHILE) + evalute(tree,WHILE,FOR,FOR) + evalute(tree,FOR,WHILE,WHILE) + evalute(tree,FOR,WHILE,FOR) + evalute(tree,FOR,FOR,WHILE) + evalute(tree,FOR,FOR,FOR)
			if triple_loop == 0:
				curr_feats += [0,double_loop,0]
			else:
				curr_feats += [0,0,triple_loop]
	else:
		curr_feats += [0,0,0]

	# feature 4
	curr_feats.append(evalute(tree,FOR,IF) + evalute(tree,WHILE,IF))

	# feature 5

	# feature 6
	rec = 0
	functions = tree.xpath(".//function")
	for f in functions:
		name = f.xpath(".//name")[1].text
		calls = f.xpath(".//call/name")

		for c in calls:
			if c.text == name:
				rec += 1
	# print "recursion", rec
	curr_feats.append(rec)

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
	if shifts > 0:
		curr_feats.append(shifts)
	else:
		curr_feats.append(0)

	# feature 8
	curr_feats.append(len(tree.xpath(".//operator[text()='&']")))

	# feature 9
	curr_feats.append(len(tree.xpath(".//operator[text()='|']")))

	decl = tree.xpath('.//decl_stmt')
	var_names = tree.xpath('.//decl_stmt/decl/name')



	#features  10-13
	types = {'int':0, 'double':1, 'string':2, 'char':3, 'vector':4}
	cnt_types = [0 for i in range(len(types))]
	cnt_vars = 0
	cnt_vectors = 0
	for elem in decl:
		tmp = elem.xpath('./decl')
		cnt_vars += len(tmp)
		if(len(tmp) > 0):
			for key in types:
				if tmp[0].xpath('./type/name') and tmp[0].xpath('./type/name')[0].text == key:
					cnt_types[types[key]] += len(tmp)

			query_vectors = tmp[0].xpath('./type/name/name')
			if(len(query_vectors)>0):
				if query_vectors[0].text == 'vector':
					cnt_vectors+=len(tmp)


	cnt_types[types['vector']] = cnt_vectors
	curr_feats.append(len(decl))
	curr_feats.append(cnt_vars)
	curr_feats += cnt_types
	curr_feats.append(cnt_vectors)

	# feature 14
	curr_feats.append(len(tree.xpath(".//parameter_list/parameter"))/len(tree.xpath(".//function")))

	# feature 15, number of methods excluding main
	curr_feats.append(len(tree.xpath(".//function/name[text()!='main']")))

	ops = 0
	for op in tree.xpath(".//operator"):
		if op.text in operations:
			ops += 1
	curr_feats.append(ops)

	return curr_feats

operations = ['+','-','*','/','%','+=','-=','*=','/=','++','--']
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
		for count,submission in enumerate(os.listdir(data_dir+"/"+contest+"/"+problem)):
			path = data_dir+"/"+contest+"/"+problem+ "/" + submission
			if submission.endswith(".xml"):
				print(path)
				problem_features.append(extract_feats(path))
		arr = np.asarray(problem_features)
		arr.astype(float)
		avg = np.average(arr, axis=0)
		feature_set[contest + "_" + problem] = avg



print(len(feature_set))


