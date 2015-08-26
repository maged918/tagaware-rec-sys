import os.path

'''
author: tarek
date: Aug 23rd 2015
desc: parses submissions.txt looking for contest number, then problems index to groups cpp submissions together in the data dir
'''

# feed tag rules in here
def update_tag(tag):
	return tag

out_file = open("problems-tags-updated.txt",'w')

with open("Problems-tags.txt") as f:

	path = ''
	for line in f:
		if line != "\n":
			arr_line = line.split("\n")[0].split(" ")
			if arr_line[0].lower() == 'contest':
				path += arr_line[2] + "/"

			if arr_line[0].lower() == "index:":
				path += arr_line[1]

			if arr_line[0].lower() == "tags:":
				out_file.write(path +":")
				for i in arr_line[1:]:
					out_file.write(str(update_tag(i))+ ",")
				out_file.write("\n")
		else:
			path = ''
