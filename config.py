def get_div():
    # div = ['Div1']
    # div = ['Div2']
    # div = ['DivAll']
    # div = ['Div1', 'Div2', 'DivAll']
    div = ['grading']
    return div

def get_ds_dir():
    return 'dataset/'

def get_all_pairs():
    return ['dp_gr', 'dp_bf', 'gr_ma', 'dp_df', 'ds_gr', 'gr_tr']

def get_algorithm_modes():
    algorithm_modes = []
    # algorithm_modes = ['categ','graph', 'maths', 'algos', 'dp_gr', 'dp_bf', 'gr_ma', 'dp_df']
    # algorithm_modes = ['categ', 'graph', 'maths', 'algos', 'pairs']
    # algorithm_modes = ['categ', 'graph', 'maths', 'algos']
    algorithm_modes += ['categ']
    # algorithm_modes += ['algos']
    # algorithm_modes=['maths']
    # algorithm_modes=['graph']
    # algorithm_modes = ['dp_gr', 'dp_bf', 'gr_ma']
    # algorithm_modes += ['dp_gr']
    # algorithm_modes += ['dp_bf']
    # algorithm_modes += ['gr_ma']
    # algorithm_modes = ['dp_df']
    # algorithm_modes += ['ds_gr']
    # algorithm_modes += ['nt_cm']
    # algorithm_modes += ['gr_tr']
    # algorithm_modes += get_all_pairs()
    return algorithm_modes
def get_classifiers():
    classifiers = ['RFT']
    # classifiers=['SVM']
    # classifiers = ['SVM', 'RFT']
    # classifiers = ['SVM', 'RFT', 'ADA']
    # classifiers = ['LRC', 'KNN', 'ADA', 'SVM', 'DBT']
    # classifiers = ['ANN']
    # classifiers = ['DBT']
    # classifiers = ['MNB']
    # classifiers = ['ADA']
    # classifiers = ['LDA']
    return classifiers

def get_feat_prefix():
    return "dataset/feats/"

def get_row_modes():
    # return "submiss"
    # return "problem"
    # return ['pandas', 'pd_out']
    return ['pandas']
    # return ['pd_out']
    # return ['problem']

def get_tags_file(in_dir, algo_mode):
    tags_file_dict = {'categ': 'data-set-single.txt', 'graph':'data-set-graphs.txt', 'maths': 'data-set-maths.txt', \
                      'algos': 'data-set-algo.txt', 'pairs': 'data-set-pair.txt', \
                      'dp_gr':'data-set-dp_greedy.txt', 'dp_bf':'data-set-dp_brute force.txt', 'gr_ma':'data-set-math_graphs.txt',\
                      'dp_df': 'data-set-dp_dfs and similar.txt',\
                      'ds_gr':'data-set-data structures_graphs.txt',\
                      'gr_tr': 'data-set-graphs_trees.txt',\
                      'nt_cm': 'data-set-number theory_combinatorics.txt'}
    return in_dir + '-' + tags_file_dict[algo_mode]

def get_multi():
    # multi=True
    multi = False
    return multi

def get_feat_modes():
    # feat_modes = [['all_feats'], ['lines'], ['count_vars'], ['count_vars','operations'], \
    #                     ['count_vars', 'operations', 'constructs']]
    # feat_modes = [['lines']]
    feat_modes = [['all_feats', 'cyclo']]
    # feat_modes = [['all_feats']]
    # feat_modes = [['count_vars']]
    return feat_modes

def get_difficulties():
    # return [['A', 'B', 'C', 'D', 'E'],['A', 'B'], ['C', 'D', 'E']]
    # return [['A', 'B', 'C', 'D', 'E', 'F', 'G']]
    return [['A', 'B', 'C', 'D', 'E']]
    # return [['C', 'D', 'E']]
    # return [['A', 'B', 'C']]
    # return [['A', 'B']]
    # return [['C']]

def print_importances():
    return False
    # return True

def get_limits():
    # return [100, 200, 500, 1000, 2500, 5000, 45000]
    return [45000]
