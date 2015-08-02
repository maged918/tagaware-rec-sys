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

'''
Parse Problems-tags.txt, the unique problem name is ContestID + Index
generate dict of problem_name --> problem_id (0-based)
Length of dict is the number of problems
'''

'''
Parse Problems-tags.txt, generate dict of tag --> tag_id (0-based)
Length of dict is the number of tags
'''

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
