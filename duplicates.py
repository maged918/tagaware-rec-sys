import pandas as pd
import pickle
import config
import time
from collections import defaultdict

t1 = time.time()

f = open('Submissions-grading.txt', 'r')
verdicts = pd.read_csv(open('Verdicts-grading.csv', 'r'), names=['id', 'verdict'])
verdicts = verdicts.set_index('id')
verdicts = verdicts.to_dict(orient='index')

verdicts = {str(k):v for k,v in verdicts.items()}

lines = f.readlines()

df_list = []

def parse(s):
	return s.split(': ')[1].strip()

cnt_users = defaultdict(lambda: set())
cnt_submissions = defaultdict(lambda: set())

user_problem_verdict = defaultdict(lambda: set())

for i in range(0,len(lines),7):
	contest = parse(lines[i])
	index = parse(lines[i+1])
	key = '%s/%s'%(contest,index)
	handle = parse(lines[i+2])
	submission_id = parse(lines[i+3])
	verdict = verdicts[submission_id]['verdict'].strip()
	cnt_users[key].add(handle)
	cnt_submissions[key].add(submission_id)
	df_list.append({'user':handle, 'problem_id':key, 'id':submission_id, 'verdict':verdict})

	user_problem_verdict[(handle, key)].add(verdict)

for key in sorted(cnt_users.keys()):
	print('# submissions and # users', len(cnt_submissions[key]), len(cnt_users[key]))

df = pd.DataFrame(df_list)
print(df.shape)
# dup_removed = df.drop_duplicates(['user', 'problem_id', 'verdict'])
remove_indexes = []
for user_problem, verdict in user_problem_verdict.items():
	if 'OK' in verdict and len(verdict) > 1:
		# df = df.loc[~((df['verdict']!='OK') & (df['user']==user_problem[0]) & (df['problem_id']==user_problem[1]))]
		remove_df = df.loc[((df['verdict']!='OK') & (df['user']==user_problem[0]) & (df['problem_id']==user_problem[1]))]
		remove_indexes+= remove_df.index.values.tolist()

print('Done with filter loop')
df = df.drop(remove_indexes, axis=0)
# dup_removed = df
dup_removed = df.drop_duplicates(['user', 'problem_id', 'verdict'])
print(dup_removed.shape)
pd.to_pickle(dup_removed.loc[:,~dup_removed.columns.isin(['user', 'problem_id'])], \
	open('dataset/feats/features-unique-grading.pickle','wb'))

print('Time taken', time.time()-t1)