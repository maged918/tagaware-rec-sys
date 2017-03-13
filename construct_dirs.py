import os.path
import shutil
import config
'''
author: tarek
date: Aug 23rd 2015
desc: parses submissions.txt looking for contest number, then problems index to groups cpp submissions together in the data dir
'''

div = config.get_div()

if 'DivAll' in div:
	s_file = "DivAll-Submissions.txt"
	data_folder = 'data-all/'
elif 'Div1' in div:
	s_file = 'Div1-Submissions.txt'
	data_folder = 'data-div-1/'
else:
	s_file = "Div2-Submissions.txt"
	data_folder = 'data-div-2/'

s_file = 'dataset/pt_sub/' + s_file

if not os.path.exists(data_folder):
	os.makedirs(data_folder)

with open(s_file) as f:
	contest = ''
	index = ''
	for line in f:
		if line != "\n":
			arr_line = line.split("\n")[0].split(" ")
			if not contest:
				if arr_line[0].lower() == 'contest':
					contest = arr_line[2]
					if not os.path.exists(data_folder+contest):
						os.makedirs(data_folder+contest)

			if not index:
				if arr_line[0].lower() == "index:":
					index = arr_line[1]
					if not os.path.exists(data_folder+contest+"/"+index):
						os.makedirs(data_folder+contest+"/"+index)

			if arr_line[0].lower() == "submission" and arr_line[1].lower() == 'id:':
				file_id = arr_line[2] + ".cpp"
				shutil.copy("source-code/" + file_id, data_folder+contest+"/"+index+"/"+file_id)

		else:
			contest = ''
			index = ''
