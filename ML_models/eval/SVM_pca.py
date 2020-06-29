import pickle

import os
import numpy as np
import pandas as pd
from matplotlib import pyplot
from sklearn import metrics, preprocessing
from sklearn.inspection import permutation_importance
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.decomposition import PCA

labels = preprocessing.LabelEncoder()
dataset_before = "../../extraction/result_test/Before/features.csv"
dataset_after = "../../extraction/result_test/After/features.csv"
pairs_before = pickle.load(open("../../extraction/result_test/Before/pairs.pkl", "rb"))
pairs_after = pickle.load(open("../../extraction/result_test/After/pairs.pkl", "rb"))
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
grid = pickle.load(open("../pickled models/model_svm_pca.pkl", "rb"))

grid_pred = grid.predict(X_before)
with open("misclassified_svmpca_before.txt", "w") as wr:
    for idx,pair in enumerate(zip(y_before, grid_pred)):
        if pair[0] == 0 and pair[1] == 1:
            wr.write(f"{os.path.basename(pairs_before[idx][0])} - {os.path.basename(pairs_before[idx][1])} - false positive\n")
        elif pair[0] == 1 and pair[1] == 0:
            wr.write(f"{os.path.basename(pairs_before[idx][0])} - {os.path.basename(pairs_before[idx][1])} - false negative\n")
print(confusion_matrix(y_before, grid_pred))
print(classification_report(y_before, grid_pred))
print("Accuracy:", metrics.accuracy_score(y_before, grid_pred))
results = permutation_importance(grid, X_before, y_before, scoring="accuracy")
# get importance
importance = results.importances_mean
# summarize feature importance
for i, v in enumerate(importance):
    print("Feature: %0d, Score: %.5f" % (i, v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)

grid_pred = grid.predict(X_after)
with open("misclassified_svmpca_after.txt", "w") as wr:
    for idx,pair in enumerate(zip(y_after, grid_pred)):
        if pair[0] == 0 and pair[1] == 1:
            wr.write(f"{os.path.basename(pairs_after[idx][0])} - {os.path.basename(pairs_after[idx][1])} - false positive\n")
        elif pair[0] == 1 and pair[1] == 0:
            wr.write(f"{os.path.basename(pairs_after[idx][0])} - {os.path.basename(pairs_after[idx][1])} - false negative\n")
print(confusion_matrix(y_after, grid_pred))
print(classification_report(y_after, grid_pred))
print("Accuracy:", metrics.accuracy_score(y_after, grid_pred))
results = permutation_importance(grid, X_after, y_after, scoring="accuracy")
# get importance
importance = results.importances_mean
# summarize feature importance
for i, v in enumerate(importance):
    print("Feature: %0d, Score: %.5f" % (i, v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)

pyplot.show()
