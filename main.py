'''
Created on Aug 1, 2015

@author: maged
'''


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
handles = [line.split(' ')[1].rstrip()
           for line in f if line.split(' ')[0] == 'Handle:']
users = dict(zip(handles, range(len(handles))))
#print(users)
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
  s = line.split(' ')
  if s[0] == 'Contest':
    contest += [int(s[2])]
  if s[0] == 'Index:':
    index += [s[1].rstrip()]
problems = [str(c) + i for c, i in zip(contest, index)]
problems = dict(zip(problems, range(len(problems))))
#print(problems)
f.close()

'''
Parse Problems-tags.txt, generate dict of tag --> tag_id (0-based)
Length of dict is the number of tags
'''
f = open('Problems-tags.txt', 'r')
tags = set()
for line in f:
  s = line.split(' ')
  if s[0] == 'Tags:':
    tags |= set(line.split(' ', 1)[1:][0].rstrip().split(','))
tags = dict(zip(map(lambda x: x.lstrip(), list(tags)), range(len(tags))))
#print(tags)
f.close()

''''
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
  arr = l.split(' ')
  if arr[0] == 'Contest':
    contest_id = arr[2].rstrip()
  if arr[0] == 'Index:':
    index = arr[1].rstrip()
  if arr[0] == 'Handle:':
    handle = arr[1].rstrip()
    user_id = users[handle]
    problem_id = problems[contest_id + index]
    users_problems[user_id].append([problem_id])
    #print(contest_id + index + ' : ' + handle)
    #print(user_id, problem_id)
#print(users_problems)
f.close()

'''
Parse Submissions.txt, for all submissions -> get problem_id, tag_id -> build adjacency list.
Build problem-tag graph.
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
    #print(tags_ids)
#print(problems_tags)
f.close()


'''
For each user, we loop over all problems. For each problem, we loop over all tags. We increment the count of this tag for this user.
At the end, we divide by the number of problems for this user.
'''
