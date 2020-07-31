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
        pickle.dump(classifier, open("rnnPredictions/models/SVM_RNN.pkl"))
    else:
        classifier = pickle.load(open("rnnPredictions/models/SVM_RNN.pkl"))
        y_pred = classifier.predict(X)
        return y_pred
