# -*- coding: utf-8 -*-
"""
Created on Mon Jun 29 15:33:51 2020

@author: Akhil
"""

import pickle

import numpy as np
import pandas as pd
from matplotlib import pyplot
from sklearn import metrics, preprocessing, svm
from sklearn.calibration import CalibratedClassifierCV
from sklearn.decomposition import PCA
from sklearn.inspection import permutation_importance
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split

labels = preprocessing.LabelEncoder()
# dataset_before = "../../extraction/result_test/Before/features.csv"
# dataset_after = "../../extraction/result_test/After/features.csv"
dataset = "../../extraction/result_test/features.csv"
# x_before = pd.read_csv(dataset_before)
# x_after = pd.read_csv(dataset_after)
# X_before = x_before.iloc[:, 1:-1]
X = pd.read_csv(dataset).iloc[:, 1:-1]
mm_scaler = preprocessing.MinMaxScaler()
# X_before = mm_scaler.fit_transform(X_before)
# Y_before = x_before.iloc[:, -1:]
# X_after = x_after.iloc[:, 1:-1]
# X_after = mm_scaler.fit_transform(X_after)
# Y_after = x_after.iloc[:, -1:]
X = mm_scaler.fit_transform(X)
Y = pd.read_csv(dataset).iloc[:, -1:]
# print(X)
# print(Y)
# y_before = labels.fit_transform(Y_before)
# y_after = labels.fit_transform(Y_after)
y = labels.fit_transform(Y)
# print(Y)
comp = 30
pca = PCA(n_components=comp)
cols = list()
for i in range(comp):
    cols.append("principal_comp_" + str(i + 1))

# X_before_pca = pca.fit_transform(X_before)
# X_after_pca = pca.fit_transform(X_after)
X_pca = pca.fit_transform(X)
# Y=pd.DataFrame(Y)
# X_before = pd.DataFrame(data=X_before_pca, columns=cols)
# X_after = pd.DataFrame(data=X_after_pca, columns=cols)
X = pd.DataFrame(data=X_pca, columns=cols)
grid = pickle.load(open("../pickled models/svm_pca_prob.pkl", "rb"))
# y_prob2=grid.predict_proba(X_before_pca)
y_prob2 = grid.predict_proba(X_pca)
count = 0
for i in range(len(y_prob2)):
    # print(y_prob2[i],y_before[i])
    print(y_prob2[i], y[i])
    # if y_before[i]==0 and y_prob2[i][1]<0.5:
    if y[i] == 0 and y_prob2[i][1] < 0.5:
        count += 1
    # elif y_before[i]==1 and y_prob2[i][1]>=0.5:
    elif y[i] == 1 and y_prob2[i][1] >= 0.5:
        count += 1
# acc=(count/len(y_before))*100
acc = (count / len(y)) * 100
print("Accuracy = ", acc)
