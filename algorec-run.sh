# Author: Tarek
# Date: 2.9.15
# Algorithm recognition pipeline
# assuming that source-code dir is there:


# constructs data dir
rm -rf data
python3 construct_dirs.py

# create xml files and clean them
bash srcml_and_clean.sh


# extract features to be saved in features.pickle
rm features.pickle
python3 features.py data

# start classification
python3 update_tags.py
python3 classifier.py