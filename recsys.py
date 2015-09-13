'''
Created on Aug 1, 2015

@author: maged, hossam
'''

from math import exp, log, isnan
from scipy.spatial.distance import cosine
from scipy.stats import pearsonr
from sklearn.cluster import KMeans
import codecs
import datetime
import dateutil.relativedelta
import numpy as np
import time
from cmath import sqrt
from sklearn.cluster.spectral import SpectralClustering

users, problems, tags, users_problems, users_submissions, problems_tags, users_tags, \
        labels, current_date = (0,)*9

count_problems, count_users, count_tags = (0,)*3
flag_print = 0
half_life = 1 # The larger the half life value the slower the forgetting rate
alpha = 0 # This is the value multiplied by the collaborative score
#submissions_file = 'All-Submissions.txt'
minimum_user_problems = 5
number_of_recommendations = 20
submissions_file = 'Submissions.txt'

'''
Parse Submissions.txt, generate dict of user_handle --> user_id (0-based)
Length of dict is the number of users.
'''

def create_users():
    global users, count_users
    f = open(submissions_file, 'r')
    handles = set([line.split(' ')[1].rstrip()
                   for line in f if line.split(' ')[0] == 'Handle:'])
    users = dict(zip(list(handles), range(len(handles))))
    count_users = len(users)
    f.close()
    if(flag_print):
        print(users)

'''
Parse Problems-tags.txt, the unique problem name is ContestID + Index
generate dict of problem_name --> problem_id (0-based)
Length of dict is the number of problems
'''

def create_problems():
    global problems, count_problems
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
    count_problems = len(problems)
    f.close()
    if(flag_print):
        print(problems)

'''
Parse Problems-tags.txt, generate dict of tag --> tag_id (0-based)
Length of dict is the number of tags
'''

def create_tags():
    global tags, count_tags
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
    count_tags = len(tags)
    f.close()
    if(flag_print):
        print(tags)

'''
Parse Submissions.txt, for all submissions -> get user_id, problem_id, build adjacency list
Build user-problem graph.
'''

def create_users_problems():
    global users_problems, users_submissions
    f = open(submissions_file, 'r')
    contest_id = ''
    index = ''
    handle = ''
    time_stamp = ''
    users_problems = [set() for i in range(len(users))]
    users_submissions = [dict() for i in range(len(users))]
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
            #problem_id = problems[contest_id + index]
            problem_id = get_problem_id(contest_id+index)
            users_problems[user_id].add(problem_id)
            users_submissions[user_id][problem_id] = time_stamp
    f.close()
    if(flag_print):
        print(users_problems)

def get_problem_id(i):
    global problems
    if i not in problems:
        idx = count_problems
        problems[i] = idx
        return idx
    else:
        return problems[i]

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

def create_users_tags_matrix():
    global users_tags
    users_tags = [[0 for t in tags] for u in users]
    for handle in users:
        u = users[handle]
        for p in users_problems[u]:
            for t in problems_tags[p]:
                users_tags[u][t] += 1
#         for t in tags.values():
#             users_tags[u][t] /= (len(users_problems[u]) * 1.0)
    #print('Users Tags: ', users_tags)
'''
Calcultaing user similarity using Pearson's/ Cosine's Correlation
NOTE: If needed (if this is taking too much time), possible optimization:
    p(x,y) = p(y,x)
'''
def create_users_correlations(u1):
    correlation = [0] * len(users)
    id1 = users[u1]
    l1 = users_tags[id1]
    for u2 in users:
        id2 = users[u2]
        l2 = users_tags[id2]
        #correlation[id2] = pearsonr(l1, l2)[0]
        correlation[id2] = cosine(l1, l2)
    return correlation

'''
Calculating Temporal Weight between users and tags
'''

def create_temporal(u):
    temporal_values = [0] * len(tags)
    user_problems_in_tags = [0] * len(tags)
    uid = users[u]
    for pid in users_problems[uid]:
        time_stamp = users_submissions[uid][pid]
        current_problem_tags = problems_tags[pid]
        problem_date = datetime.datetime.fromtimestamp(int(time_stamp))
        date_diff = dateutil.relativedelta.relativedelta(
            current_date,
            problem_date)
        days = abs(date_diff.days)
        temporal_value = temporal_function(days)
        for t in current_problem_tags:
            temporal_values[t] += temporal_value
            user_problems_in_tags[t] += 1
    temporal_values = np.array(temporal_values)
    user_problems_in_tags = np.array(user_problems_in_tags)
    temporal_values = (temporal_values / user_problems_in_tags).tolist()
    return [val if not isnan(val) else 0 for val in temporal_values]

def temporal_function(days):
    # This 2 is given by the paper containing the formula
    return exp(-log(2) * days / half_life)

def compute_temporal_score(u, user_tags_temporal_score):
    user_problems_temporal_score = [0] * len(problems)
    uid = users[u]
    for p in problems:
        pid = problems[p]
        problem_tag = [0] * len(tags)
        for t in problems_tags[pid]:
            problem_tag[t] = 1
        #user_problems_temporal_score[pid] = pearsonr(user_tags_temporal_score, problem_tag)[0]
        user_problems_temporal_score[pid] = cosine(user_tags_temporal_score, problem_tag)
    return user_problems_temporal_score


'''
Incorporating Diversity
1. Clustering tags
'''

from sklearn.metrics.pairwise import cosine_similarity as cosine_similarity            
def new_euclidean_distances(X, Y=None, Y_norm_squared=None, squared=False): 
    return cosine_similarity(X,Y)

# monkey patch (ensure cosine dist function is used)
'''
from sklearn.cluster import k_means_
from sklearn.cluster.k_means_ import euclidean_distances
k_means_.euclidean_distances = new_euclidean_distances
'''

def create_clusters():
    global labels    
    cluster_vecs = [list(x) for x in zip(*users_tags)]
    mat = [[0 for i in range(count_tags)] for j in range(count_tags)]
    for i in range(len(cluster_vecs)):
        for j in range(len(cluster_vecs)):
            mat[i][j] = cosine(cluster_vecs[i], cluster_vecs[j])

    print(mat)
    '''MADE SURE OF EXISTENCE OF VALUES IN cluster_vecs
    for u in range(count_users):
        print(cluster_vecs[0][u], cluster_vecs[1][u])

    for t in range(count_tags):
        print(np.sum(cluster_vecs[t]))
    '''
    #print('-----------------')
    #print(cosine(cluster_vecs[0], cluster_vecs[1]))

    #print(cluster_vecs[tags['implementation']][users['shalaboka']])
    #for v in cluster_vecs:
    #    print (v[users['moathwafeeq']])

    k = 5
    '''
    engine = KMeans(n_clusters=k)
    labels = engine.fit(cluster_vecs).labels_
    '''

    engine = SpectralClustering(n_clusters=k, affinity='precomputed')
    labels = engine.fit(mat).labels_
    #labels = engine.fit(cluster_vecs).labels_

    print("Tag labels: ", labels)
    inverse_tags = dict()

    for tag in tags:
        inverse_tags[tags[tag]] = tag

    for i in range(k):
        print("Cluster ", i)
        for tag_idx in range(len(labels)):
            if labels[tag_idx] == i:
                print(inverse_tags[tag_idx])

def compute_diversity_score(user):
    # Some function on labels, problems in each tag, return score
    return 

def compute_user_collaborative_score(u, correlation):
    user_problem_collaborative_score = [0] * len(problems)
    # collaborative filtering scores
    #change here to use only max correlation <<<
    uid = users[u]
    for p in problems:
        pid = problems[p]
        score_sum = 0
        users_solved_p = 0
        for u2 in users:
            if u == u2:
                continue
            u2id = users[u2]
            score_sum += correlation[u2id] * (pid in users_problems[u2id])
            if pid in users_problems[u2id]:
                users_solved_p += 1
        if users_solved_p == 0:
            user_problem_collaborative_score[pid] = 0
        else:
            user_problem_collaborative_score[pid] = score_sum / users_solved_p
    return user_problem_collaborative_score

# final scores
def compute_final_score(u):
    user_final_score = [0] * len(problems)
    uid = users[u]
    correlation = create_users_correlations(u)
    user_problem_collaborative_score = compute_user_collaborative_score(u, correlation)
    users_tags_temporal_score = create_temporal(u)
    user_problem_temporal_score = compute_temporal_score(u, users_tags_temporal_score)
    user_final_score= [alpha * c + (1 - alpha) * t for c, t in zip(user_problem_collaborative_score, user_problem_temporal_score)]
    return user_final_score

def test_users_tags():
    for i in range(len(users_tags)):
        print(users_tags[i][0])

def get_problem_name(pid):
    for p in problems:
        if problems[p] == pid:
            return p

def get_tag_name(tid):
    for t in tags:
        if tags[t] ==  tid:
            return t

def get_key(d, val):
    for key in d:
        if d[key] == val:
            return key

def evaluate(u):
    uid = users[u]
    if len(users_problems[uid]) == minimum_user_problems:
        print('Can not evaluate on the user ', u)
        return None

    submissions = users_submissions[uid]
    submission_times = sorted(list(map(lambda x: int(x), list(submissions.values()))))
    solved_problems_in_order = [get_key(submissions, str(t)) for t in submission_times]
    train_problems = set(solved_problems_in_order[:int(0.8 * len(solved_problems_in_order))])
    test_problems = set(solved_problems_in_order[int(0.8 * len(solved_problems_in_order)):])
    users_problems[uid] = train_problems

    t = compute_final_score(u)
    count_matches = 0
    for j in range(number_of_recommendations):
        index = np.argmax(t)
        t[index] = -1
        if index in test_problems:
            count_matches += 1
    accuracy = 100 * count_matches / len(test_problems) 
    users_problems[uid] = set(solved_problems_in_order)
    return accuracy

def calculate_accuracy():
    accuracies = [evaluate(u) for u in users]
    none_count = accuracies.count(None)
    print('#########', none_count, end = '######## \n')
    return sum(filter(None, accuracies)) / (len(users) - none_count)

def test():
    global alpha, half_life
    alpha = 0.5
    from collections import defaultdict
    #u = 'VastoLorde95'
    u = 'vjudge5'
    uid = users[u]
    d = defaultdict(int)
    print('---------------------------------------')
    print('Probelms the user solved')
    for pid in users_problems[uid]:
        print(get_problem_name(pid), end = ' ')
        p_tags = problems_tags[pid]
        for tid in p_tags:
            d[tid] += 1
            print(get_tag_name(tid), end=' ')
        print()
    print('---------------------------------------')
    print('sum of tags the user solved in')
    for t in tags:
        if d[tags[t]] == 0:
            continue
        print(t, d[tags[t]])
    print('---------------------------------------')
    t = compute_final_score(u)
    for j in range(20):
        index = np.argmax(t)
        t[index] = -1
        print(get_problem_name(index), end = ' ')
        for i in problems_tags[index]:
            print(get_tag_name(i), end = ', ')
        print()
    half_life = 2000
    print('---------------------------------------')
    print('half_life changed to 2000 so slower forgetting rate')
    t = compute_final_score(u)
    for j in range(20):
        index = np.argmax(t)
        t[index] = -1
        print(get_problem_name(index), end = ' ')
        for i in problems_tags[index]:
            print(get_tag_name(i), end = ', ')
        print()
    print('---------------------------------------')
    print('Evaluating Accuracy')
    accuracy = evaluate(u)
    print('Accuracy: ', accuracy)


if __name__ == '__main__':
    current_date = datetime.datetime.now()
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

    print("There are %i users, %i problems and %i tags" % (count_users, count_problems, count_tags))
    #print(users_problems[users['moathwafeeq']])

    create_problems_tags()
    print("create problems tags --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    create_users_tags_matrix()
    print("create users tags --- %s seconds ---" % (time.time() - start_time))


    test()

    #start_time = time.time()
    #evaluate('SkyDec')
    #print("Evaluating a user --- %s seconds ---" % (time.time() - start_time))
   
    #start_time = time.time()
    #print(calculate_accuracy())
    #print("Overall accuracy --- %s seconds ---" % (time.time() - start_time))
   
    #test_users_tags()

    #start_time = time.time()
    #create_users_correlations('yeti')
    #print("correlations --- %s seconds ---" % (time.time() - start_time))

    #start_time = time.time()
    #temporal_values = create_temporal('yeti')
    #print("create temporal --- %s seconds ---" % (time.time() - start_time))

    #create_clusters() #Gives error!



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
