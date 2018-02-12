import os
import time
import signal
import subprocess
import pandas as pd

class TimeoutException(Exception):   # Custom exception class
    pass

def timeout_handler(signum, frame):   # Custom signal handler
    raise TimeoutException

# Change the behavior of SIGALRM
signal.signal(signal.SIGALRM, timeout_handler)

tests = []
test_dir = 'tests/579D'
for f_name in sorted(os.listdir(test_dir)):
	if not f_name.endswith('.a'):
		tests.append(os.path.join(os.getcwd(), test_dir, f_name))

t1 = time.time()

answers = open('tests/579D/answers.txt')

ans_list = []

for line in answers:
	ans_list.append(int(line.strip()))

df = pd.read_csv('data-grading/579/579-D-samples-verdict.csv')
# df = df.head(99)
df = df.reset_index().set_index('id')
# df = df.loc[[13042105]]

problems = df.index.values.tolist()
# problems = [13039623]
print(problems)
d = {}
for idx, problem in list(enumerate(problems)):

	path = '/home/maged/Development/Research/Tag-Aware-RecSys/tagaware-rec-sys/data-grading/579/D-sample'

	comp = subprocess.Popen('g++ %s/%s.cpp -w -std=c++11 -o %s/test'%(path,problem, path), shell = True)
	comp.wait()
	all_true = True
	for test, ans in zip(tests, ans_list):		
		signal.alarm(2)
		try:
			p = subprocess.Popen('%s/test < %s' % (path,test), shell=True, \
			stdout = subprocess.PIPE)
			p.wait()
			out = p.stdout.read().strip()
			if out!=b'':
				all_true &= int(out)==ans
			else:
				all_true = False
			p.kill()
			if not all_true:
				signal.alarm(100)
				break
		except TimeoutException or SocketError:
			print('Couldnt run problem', problem)
			all_true=0
			p.kill()
			break
		except ValueError:
			all_true = 0
			p.kill()
			break
		else:
			signal.alarm(0)
	comp.kill()
	d[problem] = all_true
	print(idx, problem)
	print(df.loc[problem, 'verdict'] == all_true)

print('Total time for 100 problems', time.time()-t1)
out_df = pd.DataFrame.from_dict(d, orient='index').reset_index()

out_df.columns = ['id', 'verdict']
out_df = out_df.sort_values(by='id')
out_df = out_df.reset_index().set_index('id')
# df = df[df['id'].isin(problems)]

print(out_df['verdict'] == df['verdict'])
print(sum(out_df['verdict']==df['verdict']))
print(time.time() - t1)
