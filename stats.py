import pandas as pd
import pickle
import config
from joiner import build_tags, create_df

can_visualize = True
try:
    import seaborn as sns
except ImportError:
    can_visualize = False

    # print(df.groupby['string'].value_counts())

def visualize(inst_feats):
    if can_visualize:

        # for col in ['string']:
        # for col in inst_feats.columns.difference(['id', 'problem_id', 'tags']):
        for col in ['operations', 'variables']:
            # plt.ylim(-10, 40)
            sns.boxplot(y = col, x='tags', data = inst_feats, orient='v', showfliers=0)
            sns.plt.show()

ds_dir = config.get_ds_dir()
in_dir = ds_dir + 'DivAll'
tags_file = in_dir +  '-' + 'data-set-single.txt'
inst_feats = pickle.load(open('features-pandas.pickle', 'rb'))
tags_list, delete_keys, inst_tags = build_tags(tags_file)
inst_feats, X, Y = create_df(inst_feats, inst_tags, delete_keys)
visualize(inst_feats)
