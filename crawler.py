import os
import json
import signal
import urllib3
import requests
import subprocess

from bs4 import BeautifulSoup
from random import sample
from requests.auth import HTTPProxyAuth
from urllib3 import request
from urllib3 import util

from socket import error as SocketError

import time

flags = {
			'proxy': 0
		}

password = 'PASSWORD'

#subprocess.call(["touch", "Submissions.txt"])
#subprocess.call(["touch", "All-Submissions.txt"])
#subprocess.call(["touch", "Problems-tags.txt"])


class TimeoutException(Exception):   # Custom exception class
    pass

def timeout_handler(signum, frame):   # Custom signal handler
    raise TimeoutException

# Change the behavior of SIGALRM
signal.signal(signal.SIGALRM, timeout_handler)


def filter_Contests(contests):
	filtered = []
	Type = 'CF'
	div = 'Div. 2'
	for contest in contests:
		if(div in contest['name'] and contest['type'] == Type and contest['phase'] == 'FINISHED' \
			and (contest['id'] in contest_range) or contest['name'] in contest_names):
			filtered.append(contest)
	return filtered

def filter_Submissions(submissions, contestID, flag, mode):
	requestParams = {'contestId':int(contestID), 'from':1, 'count':1}
	req = requests.get("http://codeforces.com/api/contest.standings", params = requestParams,
					proxies = {}, auth = {})
	problems = req.json()['result']['problems']
	dictionary = {}
	filtered = []
	language = 'C++'
	# dictionary_problems = 'ABCDEFGHIJKL'
	dictionary_problems = 'ABCDEF'
	for i in range (0, len(dictionary_problems)):
		dictionary[dictionary_problems[i]] = []

	grading_verdicts = ['OK', 'WRONG_ANSWER', 'TIME_LIMIT_EXCEEDED', 'MEMORY_LIMIT_EXCEDED', 'RUNTIME_ERROR']

	for submission in submissions:
		if(submission['problem']['index'] in dictionary and language in submission['programmingLanguage']):
			# If mode is grading, append anyway
			# If mode is recognition, append only if verdict is okay
			if (mode=='grading' and submission['verdict'] in grading_verdicts) \
			or (mode == 'recognition' and submission['verdict'] == 'OK'):
				dictionary[submission['problem']['index']].append(submission)

	if(flag=='filter'):
		for problem in problems:
			if(problem['index'] in dictionary): 
				#and len(dictionary[problem['index']]) >= problem_limit):
				filtered.extend(sample(dictionary[problem['index']], min(problem_limit, len(dictionary[problem['index']]))))
				fi2.write("Contest ID: " + str(contestID) + "\n")
				fi2.write("Index: " + str(problem['index']) + "\n")
				fi2.write("Name: " + str(problem['name']) + "\n")
				fi2.write("Tags: ")
				tags = problem['tags']
				fi2.write(toString(tags))
				fi2.write("\n\n\n")
				fi2.flush()
				print(contestID, problem['index'])
		#fi2.write("\n\n")
		return filtered
	else:
		for problem in problems:
			filtered.extend(dictionary[problem['index']])
		return filtered

def create_Contest(status, name):
	for idx, submission in enumerate(status):
		signal.alarm(10)
		try:
			create_code(submission)
		except TimeoutException or SocketError:
			print('Couldnt get submission from url ' + str(submission['id']))
			continue
		else:
			signal.alarm(0)
		fi.write("Contest ID: " + str(submission['contestId']) + "\n")
		fi.write("Index: " + str(submission['problem']['index']) + "\n")
		fi.write("Handle: " + str(submission['author']['members'][0]['handle']) + "\n")
		fi.write("Submission ID: " + str(submission['id']) + "\n")
		fi.write("Submission Time: " + str(submission['creationTimeSeconds']) + "\n")
		fi_verdict.write('%d, %s\n' % (submission['id'], submission['verdict']))
		print(idx, submission['id'])
		fi.write("\n\n")
		fi.flush()
		fi_verdict.flush()

def create_all_submissions(status, name):
	for submission in status:
		fi1.write("Contest ID: " + str(submission['contestId']) + "\n")
		fi1.write("Index: " + str(submission['problem']['index']) + "\n")
		fi1.write("Handle: " + str(submission['author']['members'][0]['handle']) + "\n")
		fi1.write("Submission ID: " + str(submission['id']) + "\n")
		fi1.write("Submission Time: " + str(submission['creationTimeSeconds']))
		fi1.write("\n\n")
		fi1.flush()

def toString(lists):
	tags = ""
	if(len(lists) >= 1):
		tags = str(lists[0])

	for i in range(1, len(lists)):
		l = lists[i]
		tags = tags + ", " + str(l)

	return tags

def create_code(submission):
	t1 = time.time()
	url = "http://codeforces.com/contest/" + str(submission['contestId']) + "/submission/" + str(submission['id'])

	handle = requests.get(url)

	html_gunk = handle.content
	#print(html_gunk)
	print('Time to get submission = ', time.time() -t1)
	soup = BeautifulSoup(html_gunk, 'html.parser')
	fi3 = open( src_dir + '/' + str(submission['id']) + ".cpp" , "w")
	fi3.write("//Language: " + str(submission['programmingLanguage']) + "\n\n\n")
	try:
		result = soup.pre.get_text().encode('utf-8', errors='replace').decode('utf-8')
	except AttributeError:
		result = bs4_error_text
	except UnicodeDecodeError:
		result = '<CHAR>'
	except UnicodeEncodeError:
		result = '<CHAR>'
	fi3.write(result)
	fi3.close()


'''
MAIN
'''

if __name__ =='__main__':

	# mode = 'grading'
	mode='grading'

	if mode == 'recognition':
		src_dir = './source-code'
		problem_limit=20

	elif mode=='grading':
		src_dir = './source-code-grading'
		problem_limit = 3000

	fi = open("Submissions-%s.txt"%mode , "a")
	fi2 = open("Problems-tags-%s.txt"%mode , "a")
	fi_verdict = open('Verdicts-%s.csv'%mode, 'a')

	if not os.path.exists(src_dir):
		os.makedirs(src_dir)

	total_limit = 100
	bs4_error_text = '<ERROR>'
	# contest_range = range(725, 730+1)
	contest_range = range(915, 915)
	# contest_names = ['Codeforces Round #260 (Div. 1)']
	# contest_names = ['Codeforces Round #452 (Div. 2)']
	# contest_names = ['Educational Codeforces Round 35 (Rated for Div. 2)'] # 911
	# contest_names = ['Educational Codeforces Round 36 (Rated for Div. 2)'] 
	# contest_names = ['Codeforces Round #455 (Div. 2)']
	# contest_names = ['Codeforces Round #436 (Div. 2)']
	contest_names = ['Codeforces Round #450 (Div. 2)'] # 900
	requestParams = {'gym':'false'}
	r = requests.get("http://www.codeforces.com/api/contest.list", params=requestParams, proxies = {}, auth = {})
	contests = r.json()
	filtered = filter_Contests(contests['result'])
	print('Number of filtered contests', len(filtered))
	print(filtered[0]['name'])

	for contest in filtered:
		# contest = filtered[0]
		requestParams = {'contestId':contest['id']}
		print('Requesting submissions of contest id', contest['id'])
		r2 = requests.get("http://codeforces.com/api/contest.status", params = requestParams,
						proxies = {}, auth = {})
		status = r2.json()
		# all_submissions = filter_Submissions(status['result'], contest['id'], 'all')
		# create_all_submissions(all_submissions, contest['name'])

		filtered_submissions = filter_Submissions(status['result'], contest['id'], 'filter', mode=mode)
		create_Contest(filtered_submissions, contest['name'])



	fi.close()
	fi2.close()
