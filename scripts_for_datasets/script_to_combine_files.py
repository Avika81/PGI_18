from os import listdir
from os.path import isfile, join
mypath = "/home/avi_kadria/Desktop/src"
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
newfile = open("/home/avi_kadria/Desktop/dst/txt.txt", "w")
for f in onlyfiles:
	oldfile = open("/home/avi_kadria/Desktop/src/"+f, "r")
	for line in oldfile:
		newfile.write(line)
