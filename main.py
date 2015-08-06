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
users = dict(zip(range(len(handles)), handles))
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
  s = line.split(' ')
  if s[0] == 'Contest':
    contest += [int(s[2])]
  if s[0] == 'Index:':
    index += [s[1].rstrip()]
problems = [str(c) + i for c, i in zip(contest, index)]
problems = dict(zip(range(len(problems)), problems))
print(problems)
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
tags = dict(zip(range(len(tags)), map(lambda x: x.lstrip(), list(tags))))

print(tags)
f.close()

''''
Serialize all dicts, and then load them later to save computation time.
'''

'''
Parse Submissions.txt, for all submissions -> get user_id, problem_id, build adjacency list
Build user-problem graph.
'''

'''
Parse Submissions.txt, for all submissions -> get problem_id, tag_id -> build adjacency list.
Build problem-tag graph.
'''

'''
For each user, we loop over all problems. For each problem, we loop over all tags. We increment the count of this tag for this user.
At the end, we divide by the number of problems for this user.
'''
