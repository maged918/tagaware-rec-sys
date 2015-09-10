import os.path

'''
author: tarek
date: Aug 26th 2015
desc: parses Problems-tags.txt to produce a file with the problem path alongside its associated tags, to be fed later into the classification module
'''

# feed tag rules in here
def update_tag(tag):
	return tag

out_file = open("data-set.txt",'w')

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
				string = ''
				tags = line.split(':')[1].strip()
				tags_list = tags.split(',')
				for i in tags_list:
					string += str(update_tag(i.strip())) + ","
				out_file.write(string[:-1] + "\n")
		else:
			path = ''
