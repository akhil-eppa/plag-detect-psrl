# -*- coding: utf-8 -*-
"""
Created on Mon Jun 29 15:33:51 2020

@author: Akhil
"""

import pickle

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn import metrics, preprocessing, svm
from sklearn.calibration import CalibratedClassifierCV
from sklearn.decomposition import PCA
from sklearn.inspection import permutation_importance
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split

a_var_name_change = (6, 15, 24, 33, 42, 51, 60, 69, 78, 87, 96, 105, 114, 123)
n_var_name_change = (305, 311, 321, 327, 329, 339, 342)
a_redundant = (3, 12, 21, 30, 39, 48, 57, 66, 75, 84, 93, 102, 111, 120)
n_redundant = (301, 310, 317, 323, 326, 331, 335, 338, 341)
a_reorder_lines = (8, 17, 26, 35, 44, 53, 62, 71, 80, 89, 98, 107, 116, 125)
n_reorder_lines = (302, 314, 316, 319, 324, 328, 333, 337)
a_type_change = (2, 11, 20, 29, 38, 47, 56)
n_type_change = (303, 309, 315, 320, 325, 330, 334, 343)
a_loop_change = (9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126)
n_loop_change = (306, 313, 318, 336, 340, 345)
a_reorder_block = (7, 16, 25, 34, 43, 52, 61, 70, 79, 88, 97, 106, 115, 124)
n_reorder_block = (312,)

var_indices = list(b-1 for b in a_var_name_change + tuple(i + 458 for i in n_var_name_change))
redundant_indices = list(b-1 for b in a_redundant + tuple(i + 458 for i in n_redundant))
reorder_lines_indices = list(b-1 for b in a_reorder_lines + tuple(i + 458 for i in n_reorder_lines))
type_indices = list(b-1 for b in a_type_change + tuple(i + 458 for i in n_type_change))
loop_indices = list(b-1 for b in a_loop_change + tuple(i + 458 for i in n_loop_change))
reorder_block_indices = list(b-1 for b in a_reorder_block + tuple(i + 458 for i in n_reorder_block))

labels = preprocessing.LabelEncoder()
# dataset_before = "../../extraction/result_test/Before/features.csv"
# dataset_after = "../../extraction/result_test/After/features.csv"
dataset = "../../extraction/result_train/feat_v1.csv"
# x_before = pd.read_csv(dataset_before)
# x_after = pd.read_csv(dataset_after)
# X_before = x_before.iloc[:, 1:-1]
x = pd.read_csv(dataset, header=None)

X_var = x.iloc[var_indices, 0:-1]
X_red = x.iloc[redundant_indices, 0:-1]
X_reorder_lines = x.iloc[reorder_lines_indices, 0:-1]
X_type = x.iloc[type_indices, 0:-1]
X_loop = x.iloc[loop_indices, 0:-1]
X_reorder_block = x.iloc[reorder_block_indices, 0:-1]

mm_scaler = pickle.load(open(r"../pickled models/mmscaler.pkl", "rb"))
# X_before = mm_scaler.fit_transform(X_before)
# Y_before = x_before.iloc[:, -1:]
# X_after = x_after.iloc[:, 1:-1]
# X_after = mm_scaler.fit_transform(X_after)
# Y_after = x_after.iloc[:, -1:]
X_list = [X_var, X_red, X_reorder_lines, X_type, X_loop, X_reorder_block]
for i in range(len(X_list)):
    X_list[i] = mm_scaler.transform(X_list[i])

Y_var = x.iloc[var_indices, -1]
Y_red = x.iloc[redundant_indices, -1]
Y_reorder_lines = x.iloc[reorder_lines_indices, -1]
Y_type = x.iloc[type_indices, -1]
Y_loop = x.iloc[loop_indices, -1]
Y_reorder_block = x.iloc[reorder_block_indices, -1]
Y_list = [Y_var, Y_red, Y_reorder_lines, Y_type, Y_loop, Y_reorder_block]
# print(X)
# print(Y)
# y_before = labels.fit_transform(Y_before)
# y_after = labels.fit_transform(Y_after)
for i in range(len(Y_list)):
    Y_list[i] = labels.fit_transform(Y_list[i])
# print(Y)
comp = 30
pca = pickle.load(open(r"../pickled models/PCA.pkl", "rb"))
cols = list()
for i in range(comp):
    cols.append("principal_comp_" + str(i + 1))

# X_before_pca = pca.fit_transform(X_before)
# X_after_pca = pca.fit_transform(X_after)
X_pca_list = []
for x in X_list:
    X_pca_list.append(pca.transform(x))

# Y=pd.DataFrame(Y)
# X_before = pd.DataFrame(data=X_before_pca, columns=cols)
# X_after = pd.DataFrame(data=X_after_pca, columns=cols)
yval = []
for idx, (x, y) in enumerate(zip(X_pca_list, Y_list)):
    X = pd.DataFrame(data=x, columns=cols)
    grid = pickle.load(open("../pickled models/svm_pca_prob.pkl", "rb"))
    # y_prob2=grid.predict_proba(X_before_pca)
    y_prob2 = grid.predict_proba(x)
    count = 0
    for i in range(len(y_prob2)):
        # print(y_prob2[i],y_before[i])
        # print(y_prob2[i], y[i])
        # if y_before[i]==0 and y_prob2[i][1]<0.5:
        if y[i] == 0 and y_prob2[i][1] < 0.5:
            count += 1
        # elif y_before[i]==1 and y_prob2[i][1]>=0.5:
        elif y[i] == 1 and y_prob2[i][1] >= 0.5:
            count += 1
    # acc=(count/len(y_before))*100
    acc = (count / len(y)) * 100
    yval.append(acc)
    print(f"Accuracy for category {idx} = ", acc)

pickle.dump(yval, open("../../acc_milepost.pkl", "wb"))

x_labels = ["Variable name change", "Redundant lines", "Reorder lines", "Variable type change", "Change loop type", "Reorder blocks"]
plt.bar(x_labels, yval)
plt.xticks(rotation=20)
plt.ylim(0,100)
plt.ylabel("Accuracy(%)")
plt.title("Milepost GCC + text features classification accuracy for various categories of plagiarism")
plt.show()
