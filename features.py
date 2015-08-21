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
'''

from collections import defaultdict
from lxml import etree

import requests
import sys


file = sys.argv[1]
tree = etree.parse(file)

features = defaultdict()

#Feature 1: if inside while (binary search, kmp)
features['IF_IN_WHILE'] = tree.xpath('.//loop/if')

##################################################

#Feature 2: bag of words, {dp, mid, lo, hi, graph, query, update, solve, point, line} (binary search, graphs, segment trees)
methods = tree.xpath('.//method')
variables = tree.xpath('.//local-variable')

common_names = ['dp', 'mid', 'lo', 'hi', 'graph', 'query', 'update', 'solve', 'point', 'line','dfs','bfs','dijkstra']

features.update(dict(zip(common_names,[0]*len(common_names))))

# class name
class_name = dict(tree.xpath('.//class')[0].items())['name']
if class_name in common_names: features[class_name.upper] += 1

# methods
for method in methods:
	name = dict(method.items())['name'].lower()
	if name in common_names: features[name.upper()] += 1

# vars
for var in variables:
	name = dict(var.items())['name'].lower()
	if name in common_names: features[name.upper()] += 1
##################################################


