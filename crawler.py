import requests
import subprocess
import json
import requests
import urllib3
import os

from bs4 import BeautifulSoup
from random import sample
from requests.auth import HTTPProxyAuth
from urllib3 import request
from urllib3 import util

flags = {
			'proxy': 0
		}

password = 'PASSWORD'

#subprocess.call(["touch", "Submissions.txt"])
#subprocess.call(["touch", "All-Submissions.txt"])
#subprocess.call(["touch", "Problems-tags.txt"])
fi = open("Div1-Submissions.txt" , "a")
fi1 = open("All-Submissions.txt" , "a")
fi2 = open("Div1-Problems-tags.txt" , "a")

if not os.path.exists('./source-code'):
	os.makedirs('./source-code')

if flags['proxy'] == 1:
	proxyDict = {
	          'http'  : 'http://50.0.0.5:8080',
	          'https' : 'http://50.0.0.5:8080'
	        }
	auth = HTTPProxyAuth('maged.shalaby', password)
else:
	proxyDict = {}
	auth = {}

problem_limit = 10
total_limit = 100
bs4_error_text = '<ERROR>'
contest_range = range(1, 250)

def filter_Contests(contests):
	filtered = []
	Type = 'CF'
	div = 'Div. 1'
	for contest in contests:
		if(div in contest['name'] and contest['type'] == Type and contest['phase'] == 'FINISHED' and contest['id'] in contest_range):
			filtered.append(contest)
	return filtered

def filter_Submissions(submissions, contestID, flag):
	requestParams = {'contestId':int(contestID), 'from':1, 'count':1}
	req = requests.get("http://codeforces.com/api/contest.standings", params = requestParams,
					proxies = proxyDict, auth = auth)
	problems = req.json()['result']['problems']
	dictionary = {}
	filtered = []
	language = 'C++'
	dictionary_problems = 'ABCDEFGHIJKL'

	for i in range (0, len(dictionary_problems)):
		dictionary[dictionary_problems[i]] = []

	for submission in submissions:
		if(submission['problem']['index'] in dictionary and submission['verdict'] == 'OK' and language in submission['programmingLanguage']):
			dictionary[submission['problem']['index']].append(submission)

	if(flag=='filter'):
		for problem in problems:
			if(problem['index'] in dictionary and len(dictionary[problem['index']]) >= problem_limit):
				filtered.extend(sample(dictionary[problem['index']], problem_limit))
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
	for submission in status:
		fi.write("Contest ID: " + str(submission['contestId']) + "\n")
		fi.write("Index: " + str(submission['problem']['index']) + "\n")
		fi.write("Handle: " + str(submission['author']['members'][0]['handle']) + "\n")
		fi.write("Submission ID: " + str(submission['id']) + "\n")
		fi.write("Submission Time: " + str(submission['creationTimeSeconds']))
		print(submission['id'])
		create_code(submission)
		fi.write("\n\n")
		fi.flush()

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
	url = "http://codeforces.com/contest/" + str(submission['contestId']) + "/submission/" + str(submission['id'])
	if(flags['proxy']==1):
		http = urllib3.proxy_from_url(proxyDict['http'])
	else:
		http = urllib3.connection_from_url(url)
	handle = http.request('GET',url)
	html_gunk = handle.data
	#print(html_gunk)
	soup = BeautifulSoup(html_gunk, 'html.parser')
	#subprocess.call(["touch", './source-code/' + str(submission['id']) + ".cpp"])
	fi3 = open('./source-code/' + str(submission['id']) + ".cpp" , "w")
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


requestParams = {'gym':'false'}
r = requests.get("http://www.codeforces.com/api/contest.list", params=requestParams, proxies = proxyDict, auth = auth)
contests = r.json()
filtered = filter_Contests(contests['result'])
print('Number of filtered contests', len(filtered))

for contest in filtered:
	# contest = filtered[0]
	requestParams = {'contestId':contest['id']}
	print('Requesting submissions of contest id', contest['id'])
	r2 = requests.get("http://codeforces.com/api/contest.status", params = requestParams,
					proxies = proxyDict, auth = auth)
	status = r2.json()
	# all_submissions = filter_Submissions(status['result'], contest['id'], 'all')
	# create_all_submissions(all_submissions, contest['name'])
	filtered_submissions = filter_Submissions(status['result'], contest['id'], 'filter')
	create_Contest(filtered_submissions, contest['name'])



fi.close()
fi2.close()
