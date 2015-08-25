import os.path
import shutil

'''
author: tarek
date: Aug 23rd 2015
desc: parses submissions.txt looking for contest number, then problems index to groups cpp submissions together in the data dir
'''

if not os.path.exists('data'):
	os.makedirs('data')

with open("Submissions.txt") as f:
	contest = ''
	index = ''
	for line in f:
		if line != "\n":
			arr_line = line.split("\n")[0].split(" ")
			if not contest:
				if arr_line[0].lower() == 'contest':
					contest = arr_line[2]
					if not os.path.exists("data/"+contest):
						os.makedirs("data/"+contest)

			if not index:
				if arr_line[0].lower() == "index:":
					index = arr_line[1]
					if not os.path.exists("data/"+contest+"/"+index):
						os.makedirs("data/"+contest+"/"+index)

			if arr_line[0].lower() == "submission" and arr_line[1].lower() == 'id:':
				file_id = arr_line[2] + ".cpp"
				shutil.copy("source-code/" + file_id, "data/"+contest+"/"+index+"/"+file_id)

 		else:
			contest = ''
			index = ''
