import pandas as pd
import pickle
import config
from joiner import build_tags, create_df
import matplotlib as mpl
from matplotlib import rc
# mpl.use('pgf')
# mpl.use('pdf')
import numpy as np
import config
import textwrap

can_visualize = True
try:
    import seaborn as sns
except ImportError:
    can_visualize = False
from itertools import product
    # print(df.groupby['string'].value_counts())
from scipy import stats

def figsize(scale):
    fig_width_pt = 469.755                          # Get this from LaTeX using \the\textwidth
    inches_per_pt = 1.0/72.27                       # Convert pt to inch
    golden_mean = (np.sqrt(5.0)-1.0)/2.0            # Aesthetic ratio (you could change this)
    fig_width = fig_width_pt*inches_per_pt*scale    # width in inches
    fig_height = fig_width*golden_mean              # height in inches
    fig_size = [fig_width,fig_height]
    return fig_size

# pgf_with_latex = {                      # setup matplotlib to use latex for output
#     "pgf.texsystem": "pdflatex",        # change this if using xetex or lautex
#     "text.usetex": True,                # use LaTeX to write all text
#     "font.family": "serif",
#     "font.serif": [],                   # blank entries should cause plots to inherit fonts from the document
#     "font.sans-serif": [],
#     "font.monospace": [],
#     "axes.labelsize": 14,               # LaTeX default is 10pt font.
#     "font.size": 12,
#     "legend.fontsize": 12,               # Make the legend/label fonts a little smaller
#     "xtick.labelsize": 12,
#     "ytick.labelsize": 12,
#     "figure.figsize": figsize(0.9),     # default fig size of 0.9 textwidth
#     "pgf.preamble": [
#         r"\usepackage[utf8x]{inputenc}",    # use utf8 fonts becasue your computer can handle it :)
#         r"\usepackage[T1]{fontenc}",        # plots will be generated using this preamble
#         ]
#     }
# # mpl.rcParams.update(pgf_with_latex)

import matplotlib.pyplot as plt

def settings():

    rc('font', family='serif')
    sns.set(style="whitegrid")

    # Config
    linewidth = 6
    legend_size = 18
    labelsize_major = 20
    labelsize_minor = 16

    flatui = ['#1075a1','#24b476','#e94d5b','#7D48DA','#faa44f','#1fb0e7','#64E717']

    # x = np.arange(0,10,1)

    # m1, = plt.plot(x, x ** 2, '-', color=flatui[0],
    #                label='some-label-1', lw = linewidth)
    # m2, = plt.plot(x, x ** 3, '-', color=flatui[1],
    #                label='some-label-2', lw = linewidth)

    plt.xlabel('x-label', fontsize=labelsize_major)
    plt.ylabel('y-label', fontsize=labelsize_major)

    plt.tick_params(axis='both', which='major', labelsize=labelsize_minor)
    plt.tick_params(axis='both', which='minor', labelsize=labelsize_minor)
    plt.tight_layout()

def newfig(width):
    plt.clf()
    fig = plt.figure(figsize=figsize(width))
    ax = fig.add_subplot(111)
    return fig, ax

def savefig(filename):
    plt.savefig('{}.png'.format(filename))
    # plt.savefig('{}.pdf'.format(filename))

def ema(y, a):
    s = []
    s.append(y[0])
    for t in range(1, len(y)):
        s.append(a * y[t] + (1-a) * s[t-1])
    return np.array(s)

def visualize_totals(inst_feats):
    # for col in inst_feats.columns.difference(['id', 'problem_id', 'tags']):
    #     sns.boxplot(y=col, data =inst_feats, showfliers=1)
    #     plt.show()
    print(inst_feats['point'].value_counts())
    # print(inst_feats.get_group('math')['vector'])
    # sns.distplot(inst_feats.get_group('math')['operations'], norm_hist=True, kde=False)

    fig, axes = plt.subplots(ncols=2, sharey=False)

    # ops = inst_feats.get_group('dp')['minus']
    # sns.countplot(list(ops[ops<30]), ax = ax1)
    # print(list(ops))
    # plt.show()
    # sns.distplot(inst_feats.get_group('graphs')['operations'], norm_hist=True, kde=False)
    # ops = inst_feats.get_group('brute force')['minus']
    # print(list(ops))
    # sns.countplot(list(ops[ops<30]), ax = ax2)

    for idx, tag in enumerate(list(inst_feats.groups.keys())):
        ops = inst_feats.get_group(tag)['ll']
        axes[idx].set_title(tag)
        sns.countplot(list(ops[ops<40]), ax = axes[idx])

    plt.show()

def visualize(inst_feats):
    if can_visualize:

        # for col in ['string']:
        # # inst_feats.dropna(inplace=True)
        # print(inst_feats.loc[inst_feats['tags']=='graphs'].shape)
        # print(inst_feats.loc[inst_feats['tags']=='math'].shape)
        # print(inst_feats.loc[pd.isnull(inst_feats['tags'])].shape)

        print(inst_feats.loc[inst_feats['tags']=='graphs', 'variables'].describe())
        print(inst_feats.loc[inst_feats['tags']=='math', 'variables'].describe())

        order = inst_feats.loc[:, 'tags'].unique()
        # for col in inst_feats.columns.difference(['id', 'problem_id', 'tags']):
        # for col in ['operations', 'variables']:
        for col in ['variables']:
        # for col in ['modulus']:
        # for col in ['arrays']:
            # plt.ylim(-10, 40)
            # sns.set(font_scale=1.75)
            if algo_mode == 'algos':
                inst_feats = inst_feats.loc[inst_feats['tags'].isin(['matrices', 'combinatorics', 'shortest paths', 'flows'])]
                order = ['matrices', 'combinatorics', 'shortest paths', 'flows']
            fig, ax = newfig(1.2)
            sns.boxplot(y = col, x='tags', data = inst_feats, orient='v', showfliers=0, order=order, ax=ax)
            plt.ylabel(col)
            # # y = [0]*200
            # # y.extend([20]*(1000-len(y)))
            # # s = ema(y, 0.01)
            # ax.plot(s)
            # plt.xticks(rotation=30)
            plt.show()
            savefig('dataset/%s/%s' % (algo_mode, col))

def visualize_pairs(inst_feats):
    ''' Takes as an input a features dataframe (including tags)
    Plots scatterplot of two variables on the same plot for the present tags (from config)
    If using col: draw separate plots for each tag but on the same scale
    '''
    lm = sns.lmplot(y='single_loop', x='ifs', hue='tags', col ='tags', data=inst_feats, fit_reg=True, x_jitter=0)
    axes = lm.axes
    axes[0][0].set_xlim(0,100)
    axes[0][0].set_ylim(0,150)
    plt.show()

def get_properties():
    out = pd.read_csv('out-classifier.csv', header=0, sep=',')
    diffs = config.get_difficulties()
    diffs = [':'.join(diff) for diff in diffs]
    for diff in diffs:
        print('--------------------------------------------')
        print(out.loc[(out['difficulties']==diff) & (out['algo_mode']=='dp_bf')])

def load_output(out):
    # algos_df = out.loc[list(range(287,302)),:] #algorithms
    # algos_df = out.iloc[list(range(302,319)),:] #categories
    # algos_df = out.iloc[list(range(804-2, 824-1)),:] #dp greedy
    # algos_df = out.iloc[list(range(825-2,845-1))] #new cats
    algos_df = out.iloc[list(range(918-2,932-1))] # new algos
    print(algos_df['algo_mode'].value_counts())
    print("& SVM  & RFT  & ADA  \\\\ \hline")
    svm = algos_df.loc[algos_df['classifier']=='SVM',['acc', 'feat_types']]
    rft = algos_df.loc[algos_df['classifier']=='RFT',['acc', 'feat_types']]
    ada = algos_df.loc[algos_df['classifier']=='ADA',['acc', 'feat_types']]
    print(svm)
    for word, feat_type in zip(\
        ['all\\_feats', 'count\\_vars', 'count\\_vars + operations', 'count\\_vars + operations + constructs', 'lines'],\
        ['all_feats', 'count_vars', 'count_vars:operations' , 'count_vars:operations:constructs', 'lines']):
        #Simply renaming the features for printing
        print('%s & %.2f & %.2f & %.2f \\\\ \midrule' % (word, svm.loc[svm['feat_types']==feat_type, 'acc'],\
            rft.loc[rft['feat_types']==feat_type, 'acc'], ada.loc[ada['feat_types']==feat_type, 'acc']))

# all\_feats& 0.85 & 0.89 & 0.88 \\ \hline
# count\_vars& 0.70 & 0.81 & 0.82 \\ \hline
# count\_vars + operations& 0.80 & 0.87 & 0.86 \\ \hline
# count\_vars + operations + constructs & 0.84  & 0.88 & 0.87 \\ \hline
# lines& 0.70 & 0.73 & 0.73

def remove_outliers(inst_feats):
    grouped = inst_feats.groupby('problem_id')
    result = pd.DataFrame(columns=inst_feats.columns)
    # result = []
    i = 0
    for df in grouped:
        # df = grouped.get_group('560/C').drop(['id', 'tags', 'problem_id'], axis=1)
        # print(df[(np.abs(stats.zscore(df))<1).all(axis=1)])
        # df = df[1].drop(['id', 'tags', 'problem_id'], axis=1)
        df = df[1]
        result = result.append(df[df[df.columns.difference(['id', 'tags', 'problem_id', 'arrays_double'])]\
                     .apply(lambda x: np.abs(x - x.mean()) / (x.std() if x.std()!= 0 else 1) < 3).all(axis=1)])
        if i % 100 == 0:
            print(i)
        i+=1
    print(result.shape)
    pickle.dump(result, open(config.get_feat_prefix() + 'features-pandas-no-outliers.pickle', 'wb'))
    # print(df[np.abs(df-df.mean())<=(10*df.std())])
    # print(grouped.describe())
    # print(df.mean())

def plot_pairs_baseline(out):
    print(out.shape)
    pairs = out.iloc[773-2:777-1]
    pairs = pairs.assign(hue = ['no-outliers']*5)
    baseline = pairs
    # baseline.loc['acc'] = baseline['baseline']
    baseline = baseline.assign(acc=baseline['baseline'])
    baseline = baseline.assign(hue=['baseline']*5)
    pairs = pairs.append(baseline)

    pairs_pandas = out.iloc[778-2:782-1]
    pairs_pandas = pairs_pandas.assign(hue=['with-outliers']*5)
    pairs = pairs.append(pairs_pandas)

    ax = sns.barplot(y='acc', x='algo_mode', hue='hue', \
        hue_order = ['baseline', 'with-outliers', 'no-outliers'], data=pairs)
    # plt.xticks(rotation=30)
    ax.set(xticklabels=['dp vs. greedy','dp vs. brute-force','graphs vs. maths','dp vs. dfs','data-structures vs. graphs'])
    ax.set_xticklabels([textwrap.fill(t.get_text(), 10)  for t in ax.get_xticklabels()])
    ax.set_xlabel('Classification Mode')
    ax.set_ylabel('Accuracy')
    # plt.legend(
    #         handles = [ax],
    #         borderaxespad=0.2,
    #         bbox_to_anchor=(0., 1.02, 1., .102),
    #         fontsize=18, ncol=2,
    #         mode="expand"
    #       )

    # rc('legend', fontsize=18, handlelength=2)
    plt.legend(loc=2,prop={'size':12})

    plt.savefig('dataset/pairs-acc.png', bbox_inches='tight', dpi=200)
    plt.show()


def plot_best_model(out):
    best_pairs = out.iloc[1148-2:1207-1]
    # print(best_pairs)
    for g_name, g in best_pairs.groupby('algo_mode'):
        acc = best_pairs.loc[best_pairs['algo_mode']==g_name, 'baseline'].iloc[0]
        best_pairs = best_pairs.append(\
            {'classifier':'baseline', 'algo_mode':g_name, 'acc':acc, 'feat_types':'all_feats'}, \
            ignore_index=True)
    best_pairs = best_pairs.loc[best_pairs['feat_types']=='all_feats']
    
    # fig, ax = newfig(1.2)

    ax = sns.barplot(data=best_pairs, x='algo_mode', y='acc', hue='classifier')
    ax.set(xticklabels=['dp vs. greedy \n(17509 submissions)','dp vs. brute-force \n(16051 submissions)',\
        'graphs vs. maths \n(13493 submissions)', 'graphs vs. trees \n(5787 submissions)'])
    plt.setp(ax.get_xticklabels(), fontsize=18)
    ax.set_ylabel('Accuracy', fontsize=18)
    ax.set_xlabel('Classification Mode', fontsize=18)
    legend = plt.legend(title='Classifier', ncol=2)
    legend.get_title().set_fontsize('20')
    plt.setp(plt.gca().get_legend().get_texts(), fontsize='20')
    
    fig = plt.gcf()
    fig.subplots_adjust(bottom=0.15)
    
    plt.show()

def plot_feat_modes(out):
    best_pairs = out.iloc[1148-2:1207-1]

    best_pairs = best_pairs.loc[best_pairs['classifier']=='RFT']
    best_pairs = best_pairs.loc[best_pairs['algo_mode'].isin(['dp_gr', 'gr_ma','gr_tr'])]

    for g_name in np.unique(best_pairs['algo_mode']):
        acc = best_pairs.loc[best_pairs['algo_mode']==g_name, 'baseline'].iloc[0]
        best_pairs = best_pairs.append(\
            {'feat_types':'baseline', 'algo_mode': g_name, 'acc':acc}, ignore_index=True)

    h = np.unique(best_pairs['feat_types'])
    order = [5, 1, 2,3,4,0]
    h = [h[i] for i in order]
    
    fig, ax = newfig(1.2)
    ax  = sns.barplot(data=best_pairs, x='algo_mode', y='acc', hue='feat_types', hue_order=h, ax = ax)

    labels = ['all features', 'lines',  '#vars', '#vars + #ops', \
    '#vars + #ops + #consts', 'baseline']
    labels = [labels[i] for i in order]
    
    plt.legend((ax.get_legend_handles_labels()[0]), (labels), ncol=2)
    
    plt.setp(ax.get_legend().get_texts(), fontsize='20')
    ax.set_xticklabels(['dp vs. greedy', 'graphs vs. maths', 'graphs vs. trees'])
    ax.set_xlabel('Classification Mode')
    ax.set_ylabel('Accuracy')
    plt.show()
    
settings()
ds_dir = config.get_ds_dir()
in_dir = ds_dir + 'DivAll'
algo_mode = config.get_algorithm_modes()[0]
# algo_mode = 'dp_gr'
tags_file = config.get_tags_file(in_dir, algo_mode)

inst_feats = pd.read_pickle(open( config.get_feat_prefix() + 'features-pandas.pickle', 'rb'))
print(len(inst_feats.columns)-2)
tags_list, delete_keys, inst_tags = build_tags(tags_file)
inst_feats, X, Y = create_df(inst_feats, inst_tags, delete_keys)
# print(inst_feats.iloc[30:50], '\n', Y[30:50])
# grouped = inst_feats.groupby('tags')
# print(len(grouped))

# print(grouped['operations'].describe())
# visualize(inst_feats)
# visualize_pairs(inst_feats)
# remove_outliers(inst_feats)

# visualize_totals(grouped)
out = pd.read_csv('out-classifier.csv', header=0, sep=',')
# load_output(out)
# get_properties()

# plot_pairs_baseline(out)

plot_best_model(out)
# plot_feat_modes(out)
