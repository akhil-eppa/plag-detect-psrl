import os
import pickle
from collections import Counter

import numpy as np
from keras.models import Model, load_model

SEQ_LEN = 100
chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)
char_to_int = dict((c, i) for i, c in enumerate(chars))

tf1 = "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/code_pairs_train/n_1_1.c"
tf2 = "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/code_pairs_train/n_1_2.c"
tf3 = "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/code_pairs_train/n_301_1.c"
tf4 = "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/code_pairs_train/n_301_2.c"

model = load_model("char_rnn_model_ft")
vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)
classifier = pickle.load(open("kmeans_1000.pkl", "rb"))

vectorized_windows = []

for file in (tf1, tf2, tf3, tf4):
    txt = open(file).read().lower()
    FILE_LEN = len(txt)
    windows = []
    for i in range(FILE_LEN - SEQ_LEN):
        windows.append(
            np.array(
                [char_to_int[a] if a in chars else 0 for a in txt[i : i + SEQ_LEN]]
            ).reshape(-1, 1)
        )
    windows = np.array(windows)
    vect = vector_gen.predict(windows)
    vectorized_windows.append(vect)

count_vectors = []
for vect in vectorized_windows:
    classes = classifier.predict(vect).reshape(1,-1)
    classes = list(classes[0])
    count = Counter(classes)
    v = np.zeros((1000,), dtype="int64")
    for i in range(1000):
        if count[i]:
            v[i] = count[i]

    count_vectors.append(v)

print(v)
