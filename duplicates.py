import pandas as pd
import pickle
import config

data_pre = config.get_feat_prefix()

df = pickle.load(open(data_pre + 'features-pandas.pickle', 'rb'))
df = df.drop_duplicates(subset = ['id'])
print(df.head()['id'])
print(df.shape)
