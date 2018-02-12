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
unique_user_problem = defaultdict(lambda: (None, None))

for i in range(0,len(lines),7):
	contest = parse(lines[i])
	index = parse(lines[i+1])
	key = '%s/%s'%(contest,index)
	handle = parse(lines[i+2])
	submission_id = parse(lines[i+3])
	try:
		verdict = verdicts[submission_id]['verdict'].strip()
	except KeyError:
		print(key, submission_id, 'error')
		continue
	cnt_users[key].add(handle)
	cnt_submissions[key].add(submission_id)

	user_key = (handle,key)

	user_problem_verdict[user_key].add(verdict)
	df_list.append({'user':handle, 'problem_id':key, 'id':submission_id, 'verdict':verdict})
	
	if unique_user_problem[user_key][0] != 'OK':
		unique_user_problem[user_key] = (verdict, submission_id)

for key in sorted(cnt_users.keys()):
	print('# submissions and # users', len(cnt_submissions[key]), len(cnt_users[key]))


def from_dict():
	unique_list = []
	for (handle,key), (verdict, submission_id) in unique_user_problem.items():
		unique_list.append({'user':handle, 'problem_id':key, 'id':submission_id, 'verdict':verdict})
	df = pd.DataFrame(unique_list)
	# print('DF Shape before dups', df.shape)
	df = df.drop_duplicates(['user', 'problem_id', 'verdict'])
	# print('DF Shape after dups --should be the same', df.shape)

	return df

df = from_dict()

def from_pandas():
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
	dup_removed = df
	dup_removed = df.drop_duplicates(['user', 'problem_id', 'verdict'])
	print(dup_removed.shape)
	return dup_removed

pd.to_pickle(df.loc[:,~df.columns.isin(['user', 'problem_id'])], \
	open('dataset/feats/features-unique-grading.pickle','wb'))

print('Time taken', time.time()-t1) # 480 seconds, 82010 subs