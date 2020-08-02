import os
import pickle

import numpy as np
from sklearn.svm import SVC


def evaluate(data_path, train=False):
    X = pickle.load(open(data_path, "rb"))
    if train:
        y = X[:, -1]
        X = X[:, :-1]
        classifier = SVC().fit(X,y)
        pickle.dump(classifier, open("lib/rnnPredictions/models/SVM_RNN.pkl", "wb"))
        return None, None
    else:
        classifier = pickle.load(open("lib/rnnPredictions/models/SVM_RNN.pkl", "rb"))
        y_pred, y_prob = classifier.predict_proba(X)
        return y_pred, y_prob
