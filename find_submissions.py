import pandas as pd
import pickle
import config
df = pickle.load(open(config.get_feat_prefix()+'features-pandas.pickle', 'rb'))
# print(df.head())

# problem = '353/B' # Combinatorics
problem = '225/C' #matrices, 4945842

problems = ['731/D', '731/E', '721/C', '721/D', '651/D', '651/E']
tags = ['greedy', 'dp', 'dp', 'greedy', 'dp', 'greedy']

for problem, tag in zip(problems, tags):
    df_problem = df.loc[df['problem_id']==problem]

    # print(df_problem.loc[df_problem['lines'] == df_problem.loc[:,'lines'].max()].loc[:,['lines', 'variables', 'id']])

    # print(df_problem.loc[:,['lines', 'variables', 'id']])
    print(problem, tag, '\n', df_problem.loc[:, ['single_loop']].describe())
