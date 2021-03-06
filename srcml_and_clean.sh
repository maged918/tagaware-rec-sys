# author: tarek
# date: Aug 23rd 2015
# desc: takes in data dir path, produces xml files by srcml and cleans unnecessary namespaces
# assuming that srcml command is working, http://www.srcml.org/downloads.html

#!/bin/bash

cd $1
echo $(ls)
for contest in $(ls); do
	echo "processing $contest"
	cd $contest
	for index in $(ls); do
		cd $index
		echo "in $index"
		for file in $(find . -type f -name "*.cpp"); do 
			# echo "$file.xml"
			if [ -f "$file.xml" ]; then
				continue
			fi
			srcml $file -o $file.xml --in-order;
			echo "$file done" 
		done
		sed -i -e 's/xmlns=\"http:\/\/www.srcML.org\/srcML\/src\"//g' *.xml
		sed -i -e 's/xmlns:cpp=\"http:\/\/www.srcML.org\/srcML\/cpp\"//g' *.xml
		sed -i -e 's/cpp://g' *.xml
		rm -f *.xml-e
		cd ..
	done
	cd ..
done
