'''
Created on Aug 1, 2015

@author: maged
'''

from collections import defaultdict
from math import exp, log
from numpy import zeros
from scipy.spatial.distance import cosine
from scipy.stats import pearsonr
from sklearn import datasets
from sklearn.cluster import KMeans, AgglomerativeClustering
import codecs
import datetime
import dateutil.relativedelta
import numpy as np
import time

users, problems, tags, users_problems, problems_tags, users_tags, correlation, temporal_values, users_problems_temporal_score = (0,)*9
flag_print = 1

'''
Parse Submissions.txt, generate dict of user_handle --> user_id (0-based)
Length of dict is the number of users.
'''
  
def create_users():
    global users
    f = open('Submissions.txt', 'r')
    handles = set([line.split(' ')[1].rstrip()
                   for line in f if line.split(' ')[0] == 'Handle:'])
    users = dict(zip(list(handles), range(len(handles))))
    f.close()
    if(flag_print):
        print(users)

'''
Parse Problems-tags.txt, the unique problem name is ContestID + Index
generate dict of problem_name --> problem_id (0-based)
Length of dict is the number of problems
'''

def create_problems():
    global problems
    f = codecs.open('Problems-tags.txt', 'r', 'utf-8')
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
    f.close()
    if(flag_print):
        print(problems)

'''
Parse Problems-tags.txt, generate dict of tag --> tag_id (0-based)
Length of dict is the number of tags
'''

def create_tags():
    global tags
    f = codecs.open('Problems-tags.txt', 'r', 'utf-8')
    tags = set()
    for line in f:
        if line == '\n':
            continue
        s = line.split(' ')
        if s[0] == 'Tags:':
            tags |= set(line.split(' ', 1)[1:][0].rstrip().split(','))
    tags = set(map(lambda x: x.lstrip(), tags))
    tags = dict(zip(list(tags), range(len(tags))))
    f.close()
    if(flag_print):
        print(tags)

'''
TODO:
Serialize all dicts, and then load them later to save computation time.
'''

'''
Parse Submissions.txt, for all submissions -> get user_id, problem_id, build adjacency list
Build user-problem graph.
'''

def create_users_problems():
    global users_problems
    f = open('Submissions.txt', 'r')
    contest_id = ''
    index = ''
    handle = ''
    users_problems = []
    for _ in users:
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
            users_problems[user_id].append(problem_id)
    f.close()
    if(flag_print):
        print(users_problems)

'''
Parse Submissions.txt, for all submissions -> get problem_id, tag_id -> build adjacency list.
Build problem-tag graph.
Build tag-problem graph.
'''

def create_problems_tags():
    global problems_tags
    f = codecs.open('Problems-tags.txt', 'r', 'utf-8')
    contest_id = ''
    index = ''
    current_tags = ''
    problems_tags = []
    for _ in problems:
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
    f.close()
    if(flag_print):
        print(problems_tags)

'''
For each user, we loop over all problems. For each problem, we loop over all tags. We increment the count of this tag for this user.
At the end, we divide by the number of problems for this user.

NOTE: Might need to add all tags in user-tag graph even if with zero weights.
NOTE: Might need to use PrettyPrint/better printing for defaultdict
'''
def create_users_tags():
    global users_tags
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
                for t in users_tags[u]:
                    users_tags[u][t] /= (len(users_problems[u]) * 1.0)
    print('Users Tags: ', users_tags)
'''
Calcultaing user similarity using Pearson's Correlation
NOTE: If needed (if this is taking too much time), possible optimization:
    p(x,y) = p(y,x)
'''
def create_users_correlations():
    global correlation
    correlation = [dict()] * len(users)
    for u1 in users:
        for u2 in users:
            id1 = users[u1]
            id2 = users[u2]
            l1 = [0] * len(tags)
            l2 = [0] * len(tags)
            for k1 in users_tags[id1]:
                l1[k1] = users_tags[id1][k1]
            for k2 in users_tags[id2]:
                l2[k2] = users_tags[id2][k2]
            if id1 == id2:
                correlation[id1][id2] = 1
            if np.sum(l1) == 0 or np.sum(l2) == 0:
                continue
            #correlation[id1][id2] = pearsonr(l1, l2)[0]
            correlation[id1][id2] = cosine(l1, l2)
            #print(np.dot(l1,l2))
            #print(np.linalg.norm(l1), np.linalg.norm(l2))
            #input()

'''
Calculating Temporal Weight between users and tags
'''

def create_temporal():
    global temporal_values
    temporal_values = [[0] * len(tags)] * len(users)
    users_problems_in_tags = [[0] * len(tags)] * len(users)
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
            date_diff = dateutil.relativedelta.relativedelta(
                current_date,
                problem_date)
            days = abs(date_diff.days)
            temporal_value = exp(-log(2) * days / half_life)
            for t in current_problem_tags:
                temporal_values[user_id][t] += temporal_value
                users_problems_in_tags[user_id][t] += 1
    temporal_values = np.matrix(temporal_values)
    users_problems_in_tags = np.matrix(users_problems_in_tags)
    temporal_values = (temporal_values / users_problems_in_tags).tolist()


'''
Incorporating Diversity
1. Clustering tags
'''
def create_clusters():
    
    #cluster_graph = inverse_graph(problems_tags, len(tags))
    #cluster_vecs = to_vector(cluster_graph, len(problems))
    
    cluster_graph = inverse_graph(users_tags, len(tags))
    cluster_vecs = to_vector(cluster_graph, len(users))

    k = 5
    '''
    engine = AgglomerativeClustering(n_clusters=k, affinity='cosine', linkage='average')
    labels = engine.fit(cluster_vecs).labels_
    '''
    engine = KMeans(n_clusters=k)
    labels = engine.fit(cluster_vecs).labels_
    
    print("Tag labels: ", labels)
    inverse_tags = dict()
    
    for tag in tags:
        inverse_tags[tags[tag]] = tag
    
    for i in range(k):
        print("Cluster ", i)
        for tag_idx in range(len(labels)):
            if labels[tag_idx] == i:
                print(inverse_tags[tag_idx])

def inverse_graph(graph, n):
    inverse_graph = []
    
    for _ in range(n):
        inverse_graph.append(set())
    
    for idx in range(len(graph)):
        for node in graph[idx]:
            inverse_graph[node].add(idx)
    #print("Tag-problem graph: ", inverse_graph)
    return inverse_graph

def to_vector(graph, n):
    vectors=[]
    for _ in graph:
        vectors.append(np.zeros(n))
    
    for idx in range(len(graph)):
        for node in graph[idx]:
            vectors[idx][node] = 1
        vectors[idx] = vectors[idx].tolist()    
    return vectors
'''
Calculating the final scores
user_problem_collaborative_score is a list of dictionaries with dimensions users_count * problem_count
user_problem_collaborative_score[u][p] is the score given to problem p for user u

user_problem_collaborative_score = [dict()] * len(users)
# collaborative filtering scores
for u in users:
  uid = users[u]
  for p in problems:
    pid = problems[p]
    sum = 0
    users_solved_p = 0
    for u2 in users:
      if u == u2:
        continue
      u2id = users[u2]
      sum += correlation[uid][u2id] * (pid in users_problems[u2id])
      if pid in users_problems[u2id]:
        users_solved_p += 1
#<<<<<<<<<<<<<<<<<what should I do if a problem is not solved by anyone so users_solved_p is equal to zero
#<<<<<<<<<<<<<<<<<I would say set it to zero
    if users_solved_p == 0:
      user_problem_collaborative_score[uid][pid] = 0
    else:
      user_problem_collaborative_score[uid][pid] = sum / users_solved_p

print(user_problem_collaborative_score[0])
'''


def compute_temporal_score():
    #<<<<<<<<<<<<<<<<< what should I do to problems solved by the user?
    global users_problems_temporal_score
    users_problems_temporal_score = [dict()] * len(users)
    for u in users:
        uid = users[u]
        for p in problems:
            pid = problems[p]
            user_tag = temporal_values[uid]
            problem_tag = [0] * len(tags)
            for t in problems_tags[pid]:
                problem_tag[t] = 1
            users_problems_temporal_score[uid][pid] = pearsonr(user_tag, problem_tag)[0]

'''
# final scores
alpha = 0.7
user_problem_final_score = [dict()] * len(users)
for u in users:
  uid = users[u]
  for p in problems:
    pid = problems[p]
    user_problem_final_score[uid][pid] = alpha * user_problem_collaborative_score[
        uid][pid] + (1 - alpha) * users_problems_temporal_score[uid][pid]
print(user_problem_final_score[0])
'''

def testing():
    '''
    to_vector works correctly
    '''
    #print(to_vector(testing_graph(), 6))
    #print(inverse_graph(testing_graph(),6))
    

def testing_graph():
    set1 = {1,2,3}
    set2 = {2,3,5}
    set3 = {1,3,4,5}
    graph = [set1, set2, set3]
    return graph
 

if __name__ == '__main__':
    start_time = time.time()
    create_users()
    print("create users --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_problems()
    print("create problems --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_tags()
    print("create tags --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_users_problems()
    print("create users problems --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_problems_tags()
    print("create problems tags --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_users_tags()
    print("create users tags --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_users_correlations()
    print("correlations --- %s seconds ---" % (time.time() - start_time))

    start_time = time.time()
    create_temporal()
    print("create temporal --- %s seconds ---" % (time.time() - start_time))
    #create_clusters()
    start_time = time.time()
    compute_temporal_score()
    print("compute temporal score --- %s seconds ---" % (time.time() - start_time))
    create_clusters()
    
   

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
