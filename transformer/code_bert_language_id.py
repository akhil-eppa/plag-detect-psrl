# -*- coding: utf-8 -*-
"""
Created on Fri Jul 24 11:57:55 2020

@author: Akhil
"""

# import os
# os.system('pip install transfromers')

import pickle

import numpy as np
from sklearn.metrics import classification_report
from transformers import (AutoModelForSequenceClassification, AutoTokenizer,
                          pipeline)

model_name = "huggingface/CodeBERTa-language-id"
model = AutoModelForSequenceClassification.from_pretrained(model_name)
tokenizer = AutoTokenizer.from_pretrained(model_name)
pipe = pipeline("feature-extraction", model=model, tokenizer=tokenizer)
print("Model loaded")


cache = {}


def get_vector(path):
    y = open(path, "r")
    x = y.read()
    if cache.get(x, None) is not None:
        return cache[x]
    vec = [0 for i in range(6)]
    l = len(x)
    if l < 512:
        vec = pipe(x)
        vec = np.array(vec)
    else:
        temp = []
        for i in range(512, l, 100):
            temp.append(x[i - 512 : i])
        pred = pipe(temp)
        vec = np.mean(pred, axis=0)
    cache[x] = vec
    return vec


def euc_dist(a, b):
    print(np.linalg.norm(a - b))
    return np.linalg.norm(a - b)


# pairs1 = pickle.load(open("../extraction/result_test/pairs_graph.pkl", "rb"))
pairs = pickle.load(open("../extraction/result_test/pairs_graph.pkl", "rb"))

# pairs2 = [
#     (f"../code_pairs_train/n_{i}_1.c", f"../code_pairs_train/n_{i}_2.c")
#     for i in range(1, 50)
# ]

diff = []
cat = []
y_actual = []
for idx, pair in enumerate(pairs, 1):
    print(f"{idx}/{len(pairs)}")
    diff.append(euc_dist(get_vector(pair[0]), get_vector(pair[1])))
    cat.append(pair[2])
    y_actual.append(1 if pair[-1] == "p" else 0)

# y_pred0 = [0 if x > 0.75 else 1 for x in diff]
# y_pred1 = [0 if x > 1.00 else 1 for x in diff]
# y_pred2 = [0 if x > 1.25 else 1 for x in diff]
# y_pred3 = [0 if x > 1.50 else 1 for x in diff]
# y_pred4 = [0 if x > 1.75 else 1 for x in diff]
# y_pred5 = [0 if x > 2.00 else 1 for x in diff]
# y_pred6 = [0 if x > 2.25 else 1 for x in diff]
y_pred7 = [0 if x > 2.50 else 1 for x in diff]

# print("Threshold: 0.75")
# print(classification_report(y_actual, y_pred0))
# print("Threshold: 1.00")
# print(classification_report(y_actual, y_pred1))
# print("Threshold: 1.25")
# print(classification_report(y_actual, y_pred2))
# print("Threshold: 1.50")
# print(classification_report(y_actual, y_pred3))
# print("Threshold: 1.75")
# print(classification_report(y_actual, y_pred4))
# print("Threshold: 2.00")
# print(classification_report(y_actual, y_pred5))
# print("Threshold: 2.25")
# print(classification_report(y_actual, y_pred6))
print("Threshold: 2.50")
print(classification_report(y_actual, y_pred7))
acc = [0] * 6
tot = [0] * 6
for c, y, p in zip(cat, y_actual, y_pred7):
    if y == p:
        acc[c] += 1
    tot[c] += 1

res = np.array(acc) / np.array(tot)
print(res)
pickle.dump(res, open("../acc_transformer.pkl", "wb"))
