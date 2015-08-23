# author: tarek
# desc: takes in data dir path, produces xml files by srcml and cleans unnecessary namespaces
# assuming that srcml command is working, http://www.srcml.org/downloads.html

cd $1
for contest in $(ls); do
	echo "processing $contest"
	cd $contest
	for index in $(ls); do
		cd $index
		echo "in $index"
		for file in $(ls); do srcml $file -o $file.xml --in-order; done
		sed -i -e 's/xmlns=\"http:\/\/www.srcML.org\/srcML\/src\"//g' *.xml 
		sed -i -e 's/xmlns:cpp=\"http:\/\/www.srcML.org\/srcML\/cpp\"//g' *.xml
		sed -i -e 's/cpp://g' *.xml		
		rm *.xml-e
		cd ..
	done
	cd ..
done
