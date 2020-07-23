import os
import pickle
from collections import Counter

import numpy as np
from keras.models import Model, load_model

SEQ_LEN = 100
chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)
char_to_int = dict((c, i) for i, c in enumerate(chars))

pairs = pickle.load(
    open(
        os.path.join(
            os.path.dirname(os.getcwd()), "extraction", "result_train", "pairs.pkl"
        ),
        "rb",
    )
)

cache = {}

model = load_model("char_rnn_model_ft")
vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)
classifier = pickle.load(open("kmeans_1000.pkl", "rb"))

vectorized_windows = []
yval = []

print("Making windows...")
for idx, pair in enumerate(pairs, 1):
    print(f"{idx}/{len(pairs)}")
    for file in pair[0:2]:
        txt = open(file).read().lower()
        if cache.get(txt, None) is not None:
            vectorized_windows.append(cache[txt])
            continue
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
        cache[txt] = vect
    yval.append(pair[-1])

print("Making count vectors...")
count_vectors = []
for idx, vect in enumerate(vectorized_windows, 1):
    print(f"{idx}/{len(vectorized_windows)}")
    classes = classifier.predict(vect).reshape(1, -1)
    classes = list(classes[0])
    count = Counter(classes)
    v = np.zeros((1000,), dtype="int64")
    for i in range(1000):
        if count[i]:
            v[i] = count[i]

    count_vectors.append(v)

count_vectors = np.array(count_vectors).reshape(-1, 1000, 2)
yval = np.array(yval).reshape(-1,1)
# res = np.concatenate((count_vectors, yval), axis=1)
# print(res.shape)

pickle.dump(count_vectors, open("count_vect_X.pkl", "wb"))
pickle.dump(yval, open("count_vect_y.pkl", "wb"))
