def get_div():
    # div = ['Div1']
    # div = ['Div2']
    div = ['DivAll']
    # div = ['Div1', 'Div2', 'DivAll']
    return div

def get_ds_dir():
    return 'dataset/'

def get_algorithm_modes():
    # algorithm_modes = ['categ', 'graph', 'maths', 'algos', 'pairs']
    # algorithm_modes = ['categ']
    algorithm_modes = ['pairs']
    # algorithm_modes=['algos']
    # algorithm_modes=['maths']
    # algorithm_modes=['graph']
    return algorithm_modes
def get_classifiers():
    classifiers = ['RFT']
    # classifiers = ['SVM', 'RFT', 'ADA']
    # classifiers = ['ADA', 'LRC', 'KNN']
    # classifiers = ['ANN']
    # classifiers=['SVM']
    # classifiers = ['DBT']
    # classifiers = ['MNB']
    # classifiers = ['ADA']
    return classifiers

def get_feat_prefix():
    return "dataset/feats/"

def get_row_mode():
    # return "submiss"
    # return "problem"
    return "pandas"

def get_tags_file(in_dir, algo_mode):
    tags_file_dict = {'categ': 'data-set-single.txt', 'graph':'data-set-graphs.txt', 'maths': 'data-set-maths.txt', 'algos': 'data-set-algo.txt', 'pairs': 'data-set-pair.txt'}
    return in_dir + '-' + tags_file_dict[algo_mode]

def get_multi():
    multi=False
    return multi

def get_feat_modes():
    # feat_modes = [['cyclo'], ['all_feats'], ['all_feats', 'cyclo'],     ['lines'], ['count_vars'], ['count_vars','operations'], ['count_vars', 'operations', 'constructs']]
    feat_modes = [['lines']]
    # feat_modes = [['all_feats', 'cyclo']]
    # feat_modes = [['all_feats']]
    return feat_modes
