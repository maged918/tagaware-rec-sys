import pandas as pd
from sklearn.svm import LinearSVC, SVC
from sklearn.naive_bayes import MultinomialNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import precision_score, recall_score, confusion_matrix, classification_report, precision_recall_fscore_support, f1_score

import imblearn
from imblearn.combine import SMOTEENN
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import NearMiss, RandomUnderSampler



loc = 'dataset/feats/features-pandas-grading.pickle'

features_df = pd.read_pickle(open(loc, 'rb'))

# dfs = [features_df[features_df['verdict']==i].sample(200, random_state=0, replace=False) for i in range(2)]
# features_df = dfs[0].append(dfs[1])

labels = features_df['verdict']
features_df = features_df.drop(['verdict', 'problem_id', 'id'], axis=1)

nm = NearMiss(ratio={0:100, 1:100}, random_state=0, version=2, n_jobs=-1)
# nm = RandomUnderSampler(ratio={0:100, 1:100}, random_state=0)
reduced_df, reduced_labels = nm.fit_sample(features_df, labels)

# reduced_df = pd.DataFrame(reduced_df)
# reduced_df.columns = features_df.columns

# print(len(set(features_df['id'].values) - set(reduced_df['id'].values)))

# reduced_df = reduced_df.loc[:,~reduced_df.columns.isin(['id'])]

# sm = SMOTEENN(random_state=0)

X_train, X_test, y_train, y_test = train_test_split(reduced_df, reduced_labels, test_size = 0.2, random_state=0)

# sm = SMOTE(random_state=0, ratio=1.0)
# X_train, y_train = sm.fit_sample(X_train, y_train)

# nm = NearMiss(ratio={0:200, 1:200}, random_state=0, version=3)
# nm = RandomUnderSampler(ratio={0:200, 1:200}, random_state=0)
# print(y_train.shape)
# X_train, y_train = nm.fit_sample(X_train, y_train)
# print(y_train.shape)

# rft = RandomForestClassifier(n_estimators=100, random_state=0)
rft = LogisticRegression(C=10)
# rft = LinearSVC(class_weight='balanced', C=1)
# rft = SVC(kernel='poly', degree=2, random_state=0, C=3)
# rft = MultinomialNB()

rft.fit(X_train, y_train)
print('After fitting')
preds = rft.predict(X_test)
print(rft.score(X_test, y_test), f1_score(y_test, preds))
print((precision_recall_fscore_support(y_test, preds)))
print(classification_report(y_test, preds))
print(confusion_matrix(y_test, preds))