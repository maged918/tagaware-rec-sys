#!/bin/bash
# Author: Tarek, Maged
# Date: 2.9.15
# Algorithm recognition pipeline
# assuming that source-code dir (crawler.py output) is there:

create_xmls=0
create_features=0
classify=0
div=0
while getopts ":cfd12a" opt; do
  case $opt in
    d)
      echo "-d was triggered!" >&2
      create_xmls=1
      ;;
    f)
      create_features=1
      echo "-f triggered" >&2
      ;;
    c)
      classify=1
      echo "-c triggered" >&2
      ;;
    1)
      div='data-div-1/'
      ;;
    2)
      div='data-div-2/'
      ;;
    a)
      div='data-all/'
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

# constructs data dir
if [ $create_xmls -eq 1 ]
then
  # rm -rf $div
  python3 construct_dirs.py
  # create xml files and clean them
  bash srcml_and_clean.sh $div
fi
# extract features to be saved in features.pickle
if [ $create_features -eq 1 ]
then
  # rm features.pickle
  python3 features.py
fi
# start classification
if [ $classify -eq 1 ]
then
  echo "Classify"
  python3 update_tags.py
  python3 classifier.py
fi
