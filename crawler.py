from bs4 import *
import json
import requests
import urllib
import subprocess

subprocess.call(["touch", "Contests.txt"])
subprocess.call(["touch", "Problems-tags.txt"])
fi = open("Contests.txt" , "w")
fi2 = open("Problems-tags.txt" , "w")

def filter_Contests(contests):
 	filtered = []
 	for contest in contests:
 		if("Div. 2" in contest['name'] and contest['type'] == 'CF' and contest['phase'] == 'FINISHED'):
 			filtered.append(contest)
 	return filtered

def filter_Submissions(submissions,contestID):
 	requestParams = {'contestId':int(contestID), 'from':1, 'count':1}
	req = requests.get("http://codeforces.com/api/contest.standings", requestParams)
	problems = req.json()['result']['problems']

 	filtered = []
 	dictionary['A'] = []
 	dictionary['B'] = []
 	dictionary['C'] = []
 	dictionary['D'] = []
 	dictionary['E'] = []
 	
 	for submission in submissions:
 		if(submission['verdict'] == 'OK' and "Java" in submission['programmingLanguage']):
 			dictionary[submission['problem']['index']].append(submission)
	
	for problem in problems:
		if(len(dictionary[problem['index']]) >= 100):
			filtered.extend(sample(dictionary[problem['index']],100))
			fi2.write("Contest ID: " + str(contestID) + "\n")
			fi2.write("Index: " + str(problem['index']) + "\n")
			fi2.write("Name: " + str(problem['name']) + "\n")
			fi2.write("Tags: ")
			tags = problem['tags']
			fi2.write(toString(tags))
			fi2.write("\n\n\n")
	fi2.write("\n\n")	
 	return filtered

def create_Contest(status, name):
	
	for submission in status:
		fi.write("Contest ID: " + str(submission['contestId']) + "\n")
		fi.write("Index: " + str(submission['problem']['index']) + "\n")
		fi.write("Handle: " + str(submission['author']['members'][0]['handle']) + "\n")
		fi.write("Submission ID: " + str(submission['id']) + "\n")
		create_code(submission)
		fi.write("\n\n")
	

def toString(lists):
	tags = str(lists[0])
	for i in range(1,len(lists)):
		l = lists[i]
		tags = tags + ", " + str(l)
	return tags

def create_code(submission):
	url = "http://codeforces.com/contest/" + str(submission['contestId']) +"/submission/"+ str(submission['id'])
	handle = urllib.urlopen(url)
	html_gunk = handle.read()
	soup = BeautifulSoup(html_gunk,'html.parser')
	subprocess.call(["touch", str(submission['id']) + ".txt"])
	fi = open(str(submission['id']) + ".txt" , "w")
	fi.write("Language: " + str(submission['programmingLanguage']) + "\n\n\n")
	result = soup.pre.get_text().encode('utf-8')
	fi.write(result)
	fi.close()

# def getProblems(contestID, fi2):
# 	requestParams = {'contestId':int(contestID), 'from':1, 'count':1}
# 	req = requests.get("http://codeforces.com/api/contest.standings", requestParams)
# 	for problem in req.json()['result']['problems']:
# 			fi2.write("Contest ID: " + str(contestID) + "\n")
# 			fi2.write("Index: " + str(problem['index']) + "\n")
# 			fi2.write("Name: " + str(problem['name']) + "\n")
# 			fi2.write("Tags: ")
# 			tags = problem['tags']
# 			fi2.write(toString(tags))
# 			fi2.write("\n")
# 			fi2.write("\n\n")
# 	fi2.write("\n\n")

requestParams = {'gym':'false'}
r = requests.get("http://codeforces.com/api/contest.list", requestParams)
contests = r.json()
filtered = filter_Contests(contests['result'])


#for contest in filtered:
contest = filtered[0]
requestParams = {'contestId':contest['id']}
r2 = requests.get("http://codeforces.com/api/contest.status", requestParams)
status = r2.json()
filtered_submissions = filter_Submissions(status['result'],contest['id'])
# getProblems(contest['id'], fi2)
create_Contest(filtered_submissions,contest['name'] , fi)

fi.close()	
fi2.close()
