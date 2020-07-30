# -*- coding: utf-8 -*-
"""
Created on Mon Jun 29 15:33:51 2020

@author: Akhil
"""

import pickle

import pandas as pd
from sklearn import preprocessing, svm
from sklearn.decomposition import PCA
from sklearn.model_selection import GridSearchCV


def evaluate(data_path, train=False):
    x = pd.read_csv(data_path, header=None)
    n_components = 30

    if train:
        X = x[:, :-1]
        y = x[:, -1]
        mm_scaler = preprocessing.MinMaxScaler().fit(X)
        encoder = preprocessing.LabelEncoder().fit(y)
        pickle.dump(mm_scaler, open("milepostPredictions/models/mmscaler.pkl", "wb"))
        pickle.dump(encoder, open("milepostPredictions/models/encoder.pkl", "wb"))

        X = mm_scaler.transform(X)
        pca = PCA(n_components).fit(X)
        X = pca.transform(X)
        pickle.dump(pca, open("milepostPredictions/models/PCA.pkl", "wb"))

        y = encoder.transform(y)
        param_grid = {
            "C": [0.1, 1, 10, 100],
            "gamma": [1, 0.1, 0.01, 0.001],
            "kernel": ["rbf", "poly", "sigmoid"],
        }

        grid = GridSearchCV(svm.SVC(), param_grid, refit=True, verbose=2).fit(X, y)
        pickle.dump(grid, open("milepostPredictions/models/svm_pca_prob.pkl", "wb"))

    else:
        X = x
        mm_scaler = pickle.load(open("milepostPredictions/models/mmscaler.pkl", "rb"))
        X = mm_scaler.transform(X)
        pca = pickle.load(open("milepostPredictions/models/PCA.pkl", "rb"))
        X = pca.transform(X)
        grid = pickle.load(open("milepostPredictions/models/svm_pca_prob.pkl", "rb"))
        y_prob = grid.predict_proba(X)
        y_pred = grid.predict(X)
        return y_pred, y_prob
