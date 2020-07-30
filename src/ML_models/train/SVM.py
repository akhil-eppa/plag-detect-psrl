# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 11:31:22 2020

@author: Akhil
"""

import pickle

import numpy as np
import pandas as pd
from matplotlib import pyplot
from sklearn import metrics, preprocessing, svm
from sklearn.inspection import permutation_importance
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import GridSearchCV, train_test_split

"""
LabelEncoder is used to label as 0 or 1 or 2 based on category
"""
labels = preprocessing.LabelEncoder()
dataset_name = "feat_v1.csv"
x = pd.read_csv(dataset_name)
"""
Shuffling the order of rows in file
"""
# x = x.sample(frac=1).reset_index(drop=True)
# print(x.shape)
"""
Labels are the last column
Features are all the remaining columns
"""
X = x.iloc[:, 1:-1]
mm_scaler = preprocessing.MinMaxScaler()
X = mm_scaler.fit_transform(X)
Y = x.iloc[:, -1:]
# print(X)
# print(Y)
# Y=labels.fit_transform(Y)
# print(Y)
"""
20% data is test data
"""
X_train, X_test, y_train, y_test = train_test_split(
    X, np.ravel(Y), test_size=0.2, random_state=101
)
print(X_train.shape)
print(y_train.shape)
print(X_test.shape)
print(y_test.shape)
# print(X_train)
# print(y_test)
"""
Number of neighbors considered=7
weights are not uniform but nearer elements will have more weight
like cosine similarity
algorithm is set as suto
"""
"""
model=svm.SVC(kernel='rbf')
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print(y_test)
print(y_pred)
"""
"""
Print accuracy and the confusion matrix
"""
"""
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))
print(confusion_matrix(y_test,y_pred))
print(classification_report(y_test,y_pred))
"""

"""
The above model is without using GridSearchCV for tuning the hyperparameters
We can optimize hyperparameters by using GridSearchCV
Using GridSearchCV to tune svm hyperparameters
"""


# param_grid = {'C': [0.1,1, 10, 100], 'gamma': [1,0.1,0.01,0.001],'kernel': ['rbf', 'poly', 'sigmoid']}
param_grid = {
    "C": [0.1, 1, 10, 100],
    "gamma": [1, 0.1, 0.01, 0.001],
    "kernel": ["rbf", "sigmoid"],
}
grid = GridSearchCV(svm.SVC(), param_grid, refit=True, verbose=2)
grid.fit(X_train, y_train)
print(grid.best_estimator_)
grid_pred = grid.predict(X_test)
print(confusion_matrix(y_test, grid_pred))
print(classification_report(y_test, grid_pred))

"""
Print accuracy and the confusion matrix
"""

print("Accuracy:", metrics.accuracy_score(y_test, grid_pred))
print(confusion_matrix(y_test, grid_pred))
print(classification_report(y_test, grid_pred))
# results = permutation_importance(grid, X_train, y_train, scoring='accuracy')
# # get importance
# importance = results.importances_mean
# # summarize feature importance
# for i,v in enumerate(importance):
# 	print('Feature: %0d, Score: %.5f' % (i,v))
# # plot feature importance
# pyplot.bar([x for x in range(len(importance))], importance)
# pyplot.show()
pkl_filename = "model_svm.pkl"
with open(pkl_filename, 'wb') as file:
    pickle.dump(grid, file)
