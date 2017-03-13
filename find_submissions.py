import pandas as pd
import pickle

df = pickle.load(open('features-pandas.pickle', 'rb'))
# print(df.head())

# problem = '353/B' # Combinatorics
problem = '225/C' #matrices, 4945842 
df_problem = df.loc[df['problem_id']==problem]

# print(df_problem.loc[df_problem['lines'] == df_problem.loc[:,'lines'].max()].loc[:,['lines', 'variables', 'id']])

print(df_problem.loc[:,['lines', 'variables', 'id']])
