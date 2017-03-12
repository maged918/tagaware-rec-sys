import pandas as pd

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
'''
1. single loop
2. 2 nested loops
3. 3 nested loops
4. if in loop
5. recursion
6. shift operator
7. or operator
8. and operator
10. no. of int vars
11. no. of double/float vars
12. no. of Strings vars
13. no. of vectors vars
14. no. of lls
15. no. of points
no. of arrays
16. no. of declarations
17. no. of variables
18. no. of params per method (avg)
19. no. of functions
20-25. no. of arithmetic operations
'''

from collections import defaultdict
from lxml import etree

import sys
import os
import numpy as np
import pickle
import config
import lizard


cols = ['id', 'problem_id', 'single_loop', 'double_loop', 'triple_loop', 'if_loop',\
			  'recursion', 'shift', 'or', 'and', 'int', 'double', 'float', 'string', 'char', 'vector',\
			  'll', 'point', 'arrays', 'declarations', 'variables', 'avg_params', 'functions',\
			  'operations', 'plus', 'minus', 'times', 'divide', 'modulus', 'lines', 'ifs', 'cyclo']

def evalute(tree,*args):
	query = './'
	for arg in args:
		query += arg
	return len(tree.xpath(query[:-1	]))


def extract_feats(file):

	curr_feats = []
	curr_df ={k:0 for k in cols}
	tree = etree.parse(file)

	# features 1,2 and 3
	double_loop = 0
	triple_loop = 0
	single_loop = evalute(tree,WHILE) + evalute(tree,FOR)
	if single_loop > 0:
		double_loop = evalute(tree,WHILE,FOR) + evalute(tree,FOR,WHILE) + evalute(tree,FOR,FOR) + evalute(tree,WHILE,WHILE)
		if double_loop != 0:
			triple_loop = evalute(tree,WHILE,WHILE,WHILE) + evalute(tree,WHILE,WHILE,FOR) + evalute(tree,WHILE,FOR,WHILE) + evalute(tree,WHILE,FOR,FOR) + evalute(tree,FOR,WHILE,WHILE) + evalute(tree,FOR,WHILE,FOR) + evalute(tree,FOR,FOR,WHILE) + evalute(tree,FOR,FOR,FOR)

	curr_feats += [single_loop,double_loop,triple_loop]

	curr_df['single_loop'] = single_loop
	curr_df['double_loop'] = double_loop
	curr_df['triple_loop'] = triple_loop
	# feature 4
	f4 = evalute(tree,FOR,IF) + evalute(tree,WHILE,IF)
	curr_feats.append(f4)
	curr_df['if_loop'] = f4

	# feature 5
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
	curr_df['recursion'] = rec

	# feature 6: could be in a declared statement, or an expression (cin and cout should be excluded)
	for expr in tree.xpath(".//expr"):
		if len(expr.getchildren()) != 0:
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
	if shifts < 0:
		shifts = 0
	curr_feats.append(shifts)
	curr_df['shift'] = shifts

	# feature 7
	ands = len(tree.xpath(".//operator[text()='&']"))
	curr_feats.append(ands)
	curr_df['and'] = ands

	# feature 8
	ors = len(tree.xpath(".//operator[text()='|']"))
	curr_df['or'] = ors

	decl = tree.xpath('.//decl_stmt')
	var_names = tree.xpath('.//decl_stmt/decl/name')

	#features  9-15
	types = {'int':0, 'double':1, 'string':2, 'char':3, 'vector':4, 'll':5, 'point':6, 'float':7}
	cnt_types = [0 for i in range(len(types))]
	cnt_vars = 0
	cnt_vectors = 0
	cnt_arrs = len(tree.xpath('.//decl_stmt/decl/name/index[1]'))
	names = 0
	for elem in decl:
		tmp = elem.xpath('./decl')
		cnt_vars += len(tmp)
		if(len(tmp) > 0):
			for key in types:
				try:
					if tmp[0].xpath('./type/name')[0].text.lower() == key:
						cnt_types[types[key]] += len(tmp)
				except AttributeError:
					pass
				except IndexError:
					pass

			query_vectors = tmp[0].xpath('./type/name/name')
			if(len(query_vectors)>0):
				if query_vectors[0].text == 'vector':
					cnt_vectors+=len(tmp)
			cnt_types[types['vector']] = cnt_vectors

	curr_feats += cnt_types
	curr_feats.append(cnt_arrs)
	for t in types:
		curr_df[t] = cnt_types[types[t]]
	curr_df['arrays'] = cnt_arrs

	# print(cnt_types[types['float']], cnt_types[types['double']])

	#feature 17
	decls = len(decl)
	curr_feats.append(decls)
	curr_df['declarations'] = decls

	#feature 18
	curr_feats.append(cnt_vars)
	curr_df['variables'] = cnt_vars

	# feature 19
	avg_params = 0
	if len(tree.xpath(".//function")) != 0:
		avg_params = len(tree.xpath(".//parameter_list/parameter"))/len(tree.xpath(".//function"))
	curr_feats.append(avg_params)
	curr_df['avg_params'] = avg_params

	# feature 20, number of methods excluding main
	functions = len(tree.xpath(".//function/name[text()!='main']"))
	curr_feats.append(functions)
	curr_df['functions'] = functions

	# feature 21 - 25
	cnt_opts = {k:0 for k in ['plus', 'minus', 'times', 'divide', 'modulus']}
	ops = 0
	for op in tree.xpath(".//operator"):
		opt = op.text
		if opt in operations:
			ops += 1
			for s_opt in op_dict:
				if opt in op_dict[s_opt]:
					cnt_opts[s_opt]+=1
	curr_feats.append(ops)
	curr_df['operations'] = ops
	for t in cnt_opts:
		curr_df[t] = cnt_opts[t]
		curr_feats.append(cnt_opts[t])

	with open(file.strip('.xml')) as foo:
		lines = len(foo.readlines())

	#feature 26, length of original code
	curr_feats.append(lines)
	curr_df['lines'] = lines

	#feature 27, number of if conditions
	ifs = evalute(tree, IF)
	curr_feats.append(ifs)
	curr_df['ifs'] = ifs

	#feature 28, cyclomatic_complexity
	liz = lizard.analyze_file(file.strip('.xml'))
	try:
		cyclo = liz.function_list[0].__dict__['cyclomatic_complexity']
	except IndexError:
		cyclo = 0
	curr_df['cyclo'] = cyclo
	curr_feats.append(cyclo)

	# print('Number of ifs', ifs)
	# print(len(curr_feats))
	# print(curr_df['ll'])
	return curr_feats, curr_df

operations = ['+','-','*','/','%','+=','-=','*=','/=','++','--', '%']
op_dict ={'plus':['+', '+=', '++'], 'minus': ['-', '-=', '--'], 'times': ['*', '*='], 'divide':['/', '/='], 'modulus':['%']}


pluses = ['+', '+=', '++']
minuses = ['-', '-=', '--']
times = ['*', '*=']
divides = ['/', '/=']
FOR='/for/block/'
WHILE='/while/block/'
IF='/if/'
FUNCTION='/function'
NAME='/name'
RETURN='/block/return'

divs = config.get_div()
if 'DivAll' in divs:
	data_dir = 'data-all/'
elif 'Div1' in divs:
	data_dir = 'data-div-1/'
elif 'Div2' in divs:
	data_dir = 'data-div-2/'


# data_dir = 'data-all/'

def all_submissions():
	df = pd.DataFrame(columns = cols)
	print(len(df.columns))
	feature_set = {}
	submission_set = {}
	idx = 1
	for contest in next(os.walk(data_dir))[1]:
		for problem in next(os.walk(data_dir+"/"+contest))[1]:
			problem_features =  []
			for count,submission in enumerate(os.listdir(data_dir+"/"+contest+"/"+problem)):
				path = data_dir+"/"+contest+"/"+problem+ "/" + submission
				problem_id = contest+"/"+problem
				if submission.endswith(".xml"):
					# print(path)
					feats = extract_feats(path)
					curr_df = feats[1]
					curr_df['id'] = submission
					curr_df['problem_id'] = problem_id
					df = df.append(curr_df, ignore_index=True)
					# print(df.tail())
					problem_features.append(feats[0])
			arr = np.asarray(problem_features)
			arr.astype(float)
			avg = np.average(arr, axis=0)
			feature_set[problem_id] = avg
			submission_set[problem_id] = arr
		print("#", idx, "Contest:", contest)
		idx+=1



	print("Done feature extraction for: " + str(len(feature_set)) + " problems")
	f = open('features.pickle', 'wb')
	pickle.dump(feature_set, f)
	f.close()

	f = open('features-submissions.pickle', 'wb')
	pickle.dump(submission_set, f)
	f.close()

	f= open('features-pandas.pickle', 'wb')
	pickle.dump(df, f)
	f.close()


def test_submission(path):
	return extract_feats(path)

all_submissions()
# print(test_submission('data-all/101/A/12700023.cpp.xml')[1]['string'])
