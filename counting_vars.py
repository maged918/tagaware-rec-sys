from lxml import etree

import requests
import sys
import os
import numpy as np

types = {'int':0, 'double':1, 'string':2, 'char':3, 'vector':4}
cnt_types = [0 for i in range(len(types))]

print(cnt_types)
'''
for key in types:
  print(key, types[key])
'''

tree1 = etree.parse('data/567/D/12370177.cpp.xml')

tree = etree.parse('data/570/D/12506489.cpp.xml')

decl = tree.xpath('.//decl_stmt')
var_names = tree.xpath('.//decl_stmt/decl/name')

print('Count declarations = ', len(decl))

'''
Counts int definitions, parameters, arrays, but not return types
24
'''

cnt_vars = 0
cnt_vectors = 0
for elem in decl:
  tmp = elem.xpath('./decl')
  cnt_vars += len(tmp)
  #print('Length of name in decl', len(tmp))
  if(len(tmp) > 0):
    for key in types:
      if tmp[0].xpath('./type/name')[0].text == key:
        cnt_types[types[key]] += len(tmp)

    query_vectors = tmp[0].xpath('./type/name/name')
    if(len(query_vectors)>0):
      if query_vectors[0].text == 'vector':
        cnt_vectors+=len(tmp)

cnt_types[types['vector']] = cnt_vectors

print('Count names in for loop ', cnt_vars)
print('Count of each type of var ', cnt_types)
print('Count vectors ', cnt_vectors)

'''
#Prints all variable names
for elem in var_names:
  print('Variable name = ', elem.text)
'''

