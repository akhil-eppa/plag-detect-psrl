# -*- coding: utf-8 -*-
"""
Created on Mon Jun 29 15:33:51 2020

@author: Akhil
"""

from sklearn.metrics import confusion_matrix,classification_report
from sklearn import preprocessing
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn import svm
import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
from matplotlib import pyplot
from sklearn.inspection import permutation_importance
import pickle
from sklearn.calibration import CalibratedClassifierCV

labels = preprocessing.LabelEncoder()
dataset_before = "../../extraction/result_test/Before/features.csv"
dataset_after = "../../extraction/result_test/After/features.csv"
x_before = pd.read_csv(dataset_before)
x_after = pd.read_csv(dataset_after)
X_before = x_before.iloc[:, 1:-1]
mm_scaler = preprocessing.MinMaxScaler()
X_before = mm_scaler.fit_transform(X_before)
Y_before = x_before.iloc[:, -1:]
X_after = x_after.iloc[:, 1:-1]
X_after = mm_scaler.fit_transform(X_after)
Y_after = x_after.iloc[:, -1:]
# print(X)
# print(Y)
y_before = labels.fit_transform(Y_before)
y_after = labels.fit_transform(Y_after)
# print(Y)
comp = 30
pca = PCA(n_components=comp)
cols = list()
for i in range(comp):
    cols.append("principal_comp_" + str(i + 1))

X_before_pca = pca.fit_transform(X_before)
X_after_pca = pca.fit_transform(X_after)
# Y=pd.DataFrame(Y)
X_before = pd.DataFrame(data=X_before_pca, columns=cols)
X_after = pd.DataFrame(data=X_after_pca, columns=cols)
grid = pickle.load(open("../pickled models/svm_pca_prob.pkl", "rb"))
y_prob2=grid.predict_proba(X_before_pca)
count=0
for i in range(len(y_prob2)):
    if y_before[i]==0:
        print(y_prob2[i],y_before[i])
    if y_before[i]==0 and y_prob2[i][1]<0.5:
        count+=1
    elif y_before[i]==1 and y_prob2[i][1]>=0.5:
        count+=1
acc=(count/len(y_before))*100
print("Accuracy = ",acc)