# -*- coding: utf-8 -*-
"""
Created on Mon Jul 13 20:13:59 2020

@author: Akhil
"""
import pickle

import numpy as np
from sklearn.metrics import (accuracy_score, classification_report,
                             confusion_matrix, pairwise_distances)


def similar(v1, v2):
    # inter = [val for val in v1 if val in v2]
    # print(inter)
    # s1 = (len(inter) / len(v1)) * 100
    # s2 = (len(inter) / len(v2)) * 100
    # if s1 > 100:
    #     s1 = 100
    # if s2 > 100:
    #     s2 = 100
    # return s1, s2
    return np.count_nonzero(v1 - v2)


xval = pickle.load(open("count_vect_X.pkl", "rb"))
yval = pickle.load(open("count_vect_y.pkl", "rb"))
p_first = xval[:, :, 0]
p_second = xval[:, :, 1]
sim1 = pairwise_distances(p_first, p_second).diagonal()
sim2 = 1 - pairwise_distances(p_first, p_second, metric="cosine").diagonal()
sim3 = [similar(v1, v2) for v1, v2 in zip(p_first, p_second)]

pred1 = ["p" if a < 10000 else "np" for a in sim1]
pred2 = ["p" if a > 0.055 else "np" for a in sim2]
pred3 = ["p" if a > 450 else "np" for a in sim3]

# print(accuracy_score(yval, pred1))
# print(accuracy_score(yval, pred2))
# print(accuracy_score(yval, pred3))
# print(accuracy_score(yval, pred4))
# print(confusion_matrix(yval, pred5))
print("Metric 1: Euclidean distance")
print(classification_report(yval, pred1))
print("Metric 2: Cosine similarity")
print(classification_report(yval, pred2))
print("Metric 3: Number of differing cluster counts")
print(classification_report(yval, pred3))
# print(accuracy_score(yval, pred6))
