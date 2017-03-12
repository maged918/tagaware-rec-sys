import pandas as pd
import pickle
import config
from joiner import build_tags, create_df
import matplotlib as mpl
mpl.use('pgf')
import numpy as np
can_visualize = True
try:
    import seaborn as sns
except ImportError:
    can_visualize = False

    # print(df.groupby['string'].value_counts())


def figsize(scale):
    fig_width_pt = 469.755                          # Get this from LaTeX using \the\textwidth
    inches_per_pt = 1.0/72.27                       # Convert pt to inch
    golden_mean = (np.sqrt(5.0)-1.0)/2.0            # Aesthetic ratio (you could change this)
    fig_width = fig_width_pt*inches_per_pt*scale    # width in inches
    fig_height = fig_width*golden_mean              # height in inches
    fig_size = [fig_width,fig_height]
    return fig_size

pgf_with_latex = {                      # setup matplotlib to use latex for output
    "pgf.texsystem": "pdflatex",        # change this if using xetex or lautex
    "text.usetex": True,                # use LaTeX to write all text
    "font.family": "serif",
    "font.serif": [],                   # blank entries should cause plots to inherit fonts from the document
    "font.sans-serif": [],
    "font.monospace": [],
    "axes.labelsize": 14,               # LaTeX default is 10pt font.
    "font.size": 12,
    "legend.fontsize": 12,               # Make the legend/label fonts a little smaller
    "xtick.labelsize": 12,
    "ytick.labelsize": 12,
    "figure.figsize": figsize(0.9),     # default fig size of 0.9 textwidth
    "pgf.preamble": [
        r"\usepackage[utf8x]{inputenc}",    # use utf8 fonts becasue your computer can handle it :)
        r"\usepackage[T1]{fontenc}",        # plots will be generated using this preamble
        ]
    }
mpl.rcParams.update(pgf_with_latex)

import matplotlib.pyplot as plt
def newfig(width):
    plt.clf()
    fig = plt.figure(figsize=figsize(width))
    ax = fig.add_subplot(111)
    return fig, ax

def savefig(filename):
    plt.savefig('{}.png'.format(filename))
    plt.savefig('{}.pdf'.format(filename))

def ema(y, a):
    s = []
    s.append(y[0])
    for t in range(1, len(y)):
        s.append(a * y[t] + (1-a) * s[t-1])
    return np.array(s)

def visualize(inst_feats):
    if can_visualize:

        # for col in ['string']:
        # for col in inst_feats.columns.difference(['id', 'problem_id', 'tags']):
        # for col in ['operations', 'variables']:
        for col in ['variables']:
            # plt.ylim(-10, 40)
            # sns.set(font_scale=1.75)
            if algo_mode == 'algos':
                inst_feats = inst_feats.loc[inst_feats['tags'].isin(['matrices', 'combinatorics', 'shortest paths', 'flows'])]
            fig, ax = newfig(1.2)
            sns.boxplot(y = col, x='tags', data = inst_feats, orient='v', showfliers=0, order=['matrices', 'combinatorics', 'shortest paths', 'flows'], ax=ax)
            plt.ylabel('num variables')
            # # y = [0]*200
            # # y.extend([20]*(1000-len(y)))
            # # s = ema(y, 0.01)
            # ax.plot(s)
            # plt.xticks(rotation=30)
            # plt.show()
            savefig('dataset/mcsf-variables')

ds_dir = config.get_ds_dir()
in_dir = ds_dir + 'DivAll'
algo_mode = config.get_algorithm_modes()[0]
tags_file = config.get_tags_file(in_dir, algo_mode)
inst_feats = pickle.load(open('features-pandas.pickle', 'rb'))
tags_list, delete_keys, inst_tags = build_tags(tags_file)
inst_feats, X, Y = create_df(inst_feats, inst_tags, delete_keys)
grouped = inst_feats.groupby('tags')
# print(grouped['operations'].describe())
visualize(inst_feats)
