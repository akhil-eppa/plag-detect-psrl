import os
import pickle

import numpy as np
from keras.models import Model, load_model
from sklearn.decomposition import PCA
# from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler

from ..utils.extractTextFeatures import extractTextFeatures


def extractRnnFeatures(file_pairs, root_dir, train=False):
    if train:
        file_pairs = [(root_dir / i, root_dir / j, k) for i, j, k in file_pairs]
    else:
        file_pairs = [(root_dir / i, root_dir / j) for i, j in file_pairs]
    SEQ_LENGTH = 100
    chars = pickle.load(open("lib/rnnPredictions/models/chars.pkl", "rb"))
    VOCAB_LENGTH = len(chars)
    char_to_int = dict((c, i) for i, c in enumerate(chars))
    int_to_char = dict((i, c) for i, c in enumerate(chars))

    model = load_model("lib/rnnPredictions/models/char_rnn_model_ft")
    vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)

    if train:
        y_actual = []
    v1_arr = []
    v2_arr = []
    windows = []
    w_indices = []
    cur_idx = 0
    for idx, pair in enumerate(file_pairs, 1):
        print(f"{idx}/{len(file_pairs)}")
        txtfile1 = open(pair[0]).read().lower()
        txtfile2 = open(pair[1]).read().lower()
        input_file_len1 = len(txtfile1)
        input_file_len2 = len(txtfile2)
        if input_file_len1 < 100 or input_file_len2 < 100:
            print("Skipped")
            continue
        for i in range(input_file_len1 - SEQ_LENGTH):
            windows.append(
                np.array(
                    list(
                        char_to_int[a] if a in chars else 0
                        for a in txtfile1[i : i + SEQ_LENGTH]
                    )
                ).reshape(-1, 1)
            )
            cur_idx += 1

        w_indices.append(cur_idx + 1)

        for i in range(input_file_len2 - SEQ_LENGTH):
            windows.append(
                np.array(
                    list(
                        char_to_int[a] if a in chars else 0
                        for a in txtfile2[i : i + SEQ_LENGTH]
                    )
                ).reshape(-1, 1)
            )
            cur_idx += 1

        w_indices.append(cur_idx + 1)
        if train:
            y_actual.append(0 if pair[-1] == "np" else 1)

    windows = np.array(windows)
    del chars
    del char_to_int
    del int_to_char

    window_vectors = vector_gen.predict(windows)
    print("Generated vectors")
    del windows
    del model
    del vector_gen

    for idx, num in enumerate(w_indices):
        if idx == 0:
            start = 0
        else:
            start = w_indices[idx - 1]

        a = np.mean(window_vectors[start:num], axis=0)
        if idx % 2:
            v1_arr.append(a)
        else:
            v2_arr.append(a)

    # pickle.dump(v1_arr, open("v1_arr.pkl", "wb"))
    # pickle.dump(v2_arr, open("v2_arr.pkl", "wb"))

    # v1_arr = pickle.load(open("v1_arr.pkl", "rb"))
    # v2_arr = pickle.load(open("v2_arr.pkl", "rb"))
    ld_rat, ad, ed, cc_rat, cl_rat = extractTextFeatures(file_pairs, root_dir, "")
    v1_arr = np.array(v1_arr)
    v2_arr = np.array(v2_arr)
    X = v1_arr - v2_arr
    if train:
        pca = PCA(n_components=250)
        mmscaler = MinMaxScaler()
        scaler = mmscaler.fit(X)
        X = scaler.transform(X)
        pca_mod = pca.fit(X)
        X = pca_mod.transform(X)
        pickle.dump(scaler, open("lib/rnnPredictions/models/mmscaler.pkl", "wb"))
        pickle.dump(pca_mod, open("lib/rnnPredictions/models/PCA.pkl", "wb"))
    else:
        scaler = pickle.load(open("lib/rnnPredictions/models/mmscaler.pkl", "rb"))
        pca_mod = pickle.load(open("lib/rnnPredictions/models/PCA.pkl", "rb"))
        X = scaler.transform(X)
        X = pca_mod.transform(X)

    X = np.concatenate((X, ld_rat, ad, ed, cl_rat, cc_rat), axis=1)
    if train:
        X = np.concatenate((X, y_actual), axis=1)
    pickle.dump(X, open("lib/rnnPredictions/result/X.pkl"))
