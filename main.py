'''
Created on Aug 1, 2015

@author: maged
'''

import numpy as np
import scipy as scipy
import sklearn

from collections import defaultdict
from scipy.stats import pearsonr
from numpy import zeros 
from sklearn.cluster import KMeans
from sklearn import datasets

'''
Count number of unique users, problems, tags
Our graphs will be represented as adjacency list of sets
To compute cosine similarity, dot product = size of intersection, magnitude = sqrt(length of list)
'''

'''
Parse Submissions.txt, generate dict of user_handle --> user_id (0-based)
Length of dict is the number of users.
'''
f = open('Submissions.txt', 'r')
handles = set([line.split(' ')[1].rstrip()
              for line in f if line.split(' ')[0] == 'Handle:'])
users = dict(zip(list(handles), range(len(handles))))
# TO DO: Check the logic of this edit!
print(users)
f.close()

'''
Parse Problems-tags.txt, the unique problem name is ContestID + Index
generate dict of problem_name --> problem_id (0-based)
Length of dict is the number of problems
'''
f = open('Problems-tags.txt', 'r')
contest = []
index = []
for line in f:
  if line == '\n':
    continue
  s = line.split(' ')
  if s[0] == 'Contest':
    contest += [int(s[2])]
  if s[0] == 'Index:':
    index += [s[1].rstrip()]
problems = [str(c) + i for c, i in zip(contest, index)]
problems = dict(zip(problems, range(len(problems))))
print(problems)
f.close()

'''
Parse Problems-tags.txt, generate dict of tag --> tag_id (0-based)
Length of dict is the number of tags
'''
f = open('Problems-tags.txt', 'r')
tags = set()
for line in f:
  if line == '\n':
    continue
  s = line.split(' ')
  if s[0] == 'Tags:':
    tags |= set(line.split(' ', 1)[1:][0].rstrip().split(','))
tags = set(map(lambda x: x.lstrip(), tags))
tags = dict(zip(list(tags), range(len(tags))))
print(tags)
f.close()

users_count = len(users)
problems_count = len(problems)
tags_count = len(tags)
print('User count = ' + str(users_count))
print('Problem count = ' + str(problems_count))
print('Tag count = ' + str(tags_count))

'''
TODO:
Serialize all dicts, and then load them later to save computation time.
'''

'''
Parse Submissions.txt, for all submissions -> get user_id, problem_id, build adjacency list
Build user-problem graph.
'''
f = open('Submissions.txt', 'r')
contest_id = ''
index = ''
handle = ''
users_problems = []
for u in users:
  users_problems.append([])

for l in f:
  if l == '\n':
    continue
  arr = l.split(' ')
  if arr[0] == 'Contest':
    contest_id = arr[2].rstrip()
  if arr[0] == 'Index:':
    index = arr[1].rstrip()
  if arr[0] == 'Handle:':
    handle = arr[1].rstrip()
    user_id = users[handle]
    problem_id = problems[contest_id + index]
    # print(contest_id + index + ' : ' + handle)
    # print(user_id, problem_id)
    users_problems[user_id].append(problem_id)
print(users_problems)
f.close()

'''
Parse Submissions.txt, for all submissions -> get problem_id, tag_id -> build adjacency list.
Build problem-tag graph.
Build tag-problem graph.
'''
f = open('Problems-tags.txt', 'r')
contest_id = ''
index = ''
current_tags = ''
problems_tags = []
for p in problems:
  problems_tags.append([])
for l in f:
  arr = l.split(' ')
  if arr[0] == 'Contest':
    contest_id = arr[2].rstrip()
  if arr[0] == 'Index:':
    index = arr[1].rstrip()
  if arr[0] == 'Tags:':
    current_tags = l.split(':')[1][1:].rstrip()
    current_tags = list(map(lambda x: x.rstrip(), current_tags.split(',')))
    current_tags = list(map(lambda x: x.lstrip(), current_tags))
    tags_ids = [tags[tag] for tag in current_tags]
    problem_id = problems[contest_id + index]
    problems_tags[problem_id] += tags_ids
print(problems_tags)
f.close()

'''
For each user, we loop over all problems. For each problem, we loop over all tags. We increment the count of this tag for this user.
At the end, we divide by the number of problems for this user.

NOTE: Might need to add all tags in user-tag graph even if with zero weights.
NOTE: Might need to use PrettyPrint/better printing for defaultdict
'''
users_tags = []
for u in users:
  users_tags.append(defaultdict(int))
for handle in users:
  u = users[handle]
  for p in users_problems[u]:
    for t in problems_tags[p]:
      users_tags[u][t] += 1
for handle in users:
  u = users[handle]
  # print(len(users_problems[u]))
  for t in users_tags[u]:
    users_tags[u][t] /= (len(users_problems[u]) * 1.0)
print(users_tags)
# print(tags["geometry"], tags["implementation"], tags["sortings"])

'''
Calcultaing user similarity using Pearson's Correlation
NOTE: If needed (if this is taking too much time), possible optimization:
    p(x,yاسيوط) = p(y,x)
'''
correlation = []
for i1, u1 in zip(range(len(users)), users):
  correlation.append([])
  for u2 in users:
    id1 = users[u1]
    id2 = users[u2]
    l1 = [0] * len(tags)
    l2 = [0] * len(tags)
    for k in users_tags[id1]:
      l1[k] = users_tags[id1][k]
    for k in users_tags[id2]:
      l2[k] = users_tags[id2][k]
    correlation[i1].append(pearsonr(l1, l2)[0])
  print(correlation[i1])

for user in correlation:
  for other_user in user:
    print(other_user, end=' ')
  print()

'''
Calculating Temporal Weight between users and tags
'''

import datetime
import dateutil.relativedelta
from math import exp, log
temporal_values = [[0] * len(tags)] * len(users)
f = open('Submissions.txt', 'r')
contest_id = ''
index = ''
handle = ''
time_stamp = ''
current_date = datetime.datetime.now()
half_life = 2
for l in f:
  if l == '\n':
    continue
  arr = l.split(' ')
  if arr[0] == 'Contest':
    contest_id = arr[2].rstrip()
  if arr[0] == 'Index:':
    index = arr[1].rstrip()
  if arr[0] == 'Handle:':
    handle = arr[1].rstrip()
  if arr[1] == 'Time:':
    time_stamp = arr[2].rstrip()
    user_id = users[handle]
    problem_id = problems[contest_id + index]
    current_problem_tags = problems_tags[problem_id]
    problem_date = datetime.datetime.fromtimestamp(int(time_stamp))
    date_diff = dateutil.relativedelta.relativedelta (current_date, problem_date)
    days = abs(date_diff.days)
    temporal_value = exp(-log(2) * days / half_life)
    for t in current_problem_tags:
      temporal_values[user_id][t] += temporal_value
print(temporal_values)


'''
Incorporating Diversity
1. Clustering tags
'''

tags_problems = []

for t in tags:
  tags_problems.append(set())

for idx in range(len(problems_tags)):
  for t in problems_tags[idx]:
    tags_problems[t].add(idx)
  
print("Tag-problem graph: ", tags_problems)

tag_vectors = []
for t in tags:
  tag_vectors.append(np.zeros(problems_count))

for idx in range(len(tags_problems)):
  for p in tags_problems[idx]:
    tag_vectors[idx][p]=1
  tag_vectors[idx] = tag_vectors[idx].tolist()
  
print("Tag-vectors: ", tag_vectors)    

k = 10
engine = KMeans(n_clusters=k)
labels = engine.fit(tag_vectors).labels_

print("Tag labels: ", labels)

inverse_tags= dict()

for tag in tags:
  inverse_tags[tags[tag]] = tag

for i in range(k):
  print("Cluster ", i)
  for tag_idx in range(len(labels)):
    if labels[tag_idx] == i:
      print(inverse_tags[tag_idx])


'''
Introduction:
1. Start by introducing the importance of the problem, i.e: competitive programming. Include Stats
2. Current status of competitive programming systems. Online judges. Problems. Interests diversify.
3. Current status of recommender systems algorithms. Don't incorporate both diversity and temporality
in tag-aware systems. How will diversity and temporality affect users.
4. List of contributions of this paper.

Background:
DO NOT list papers.
Goal: We did our homework. Nothing in literature exactly covers what we do. Critical eye.

Disclaimer:
PLAGIARISM
Copying word-for-word. Paraphrasing. Read your papers, close them, then write using your own
language.

List of authors:
Ethical restrictions. People who had contributions in the contributions.
'''

'''
Java to XML: Java ML
CPP to XML: Src ML
XML Queries: XPATH
'''

'''
Must write justification for each feature. Something numerical or something referencable. Or use
correlation.
'''
