import os
import pickle

import numpy as np
from keras.models import Model, load_model
from sklearn.decomposition import PCA
from sklearn.metrics import classification_report, confusion_matrix

from text_features import generate_text_features

classifier = pickle.load(open("SVM_RNN.pkl", "rb"))
pairs_test_before = pickle.load(
    open(
        "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/extraction/result_test/pairs_graph.pkl",
        "rb",
    )
)
# pairs_test_after = pickle.load(
#     open(
#         "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/extraction/result_test/After/pairs.pkl",
#         "rb",
#     )
# )

SEQ_LENGTH = 100
chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)
char_to_int = dict((c, i) for i, c in enumerate(chars))
int_to_char = dict((i, c) for i, c in enumerate(chars))

model = load_model("char_rnn_model_ft")
vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)

y_actual_before = []
categories = []
v1_arr_before = []
v2_arr_before = []
windows = []
w_indices = []
cur_idx = 0
for idx, pair in enumerate(pairs_test_before, 1):
    print(f"{idx}/{len(pairs_test_before)}")
    txtfile1 = open(pair[0]).read().lower()
    txtfile2 = open(pair[1]).read().lower()
    INPUT_FILE_LEN1 = len(txtfile1)
    INPUT_FILE_LEN2 = len(txtfile2)
    if INPUT_FILE_LEN1 < 100 or INPUT_FILE_LEN2 < 100:
        print("Skipped")
        continue
    for i in range(INPUT_FILE_LEN1 - SEQ_LENGTH):
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

    for i in range(INPUT_FILE_LEN2 - SEQ_LENGTH):
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
    y_actual_before.append(0 if pair[-1] == "np" else 1)
    categories.append(pair[2])

windows = np.array(windows)
print(windows.shape)
del pairs_test_before

window_vectors = vector_gen.predict(windows)
print("Generated vectors")
del windows

for idx, num in enumerate(w_indices):
    if idx == 0:
        start = 0
    else:
        start = w_indices[idx - 1]

    a = np.mean(window_vectors[start:num], axis=0)
    if np.isnan(a).any():
        continue
    if idx % 2:
        v1_arr_before.append(a)
    else:
        v2_arr_before.append(a)

v1_arr_before = np.array(v1_arr_before)
v2_arr_before = np.array(v2_arr_before)
#
# pickle.dump(v1_arr_before, open("v1_arr_before.pkl", "wb"))
# pickle.dump(v2_arr_before, open("v2_arr_before.pkl", "wb"))

# y_actual_after = []
# v1_arr_after = []
# v2_arr_after = []
# windows = []
# w_indices = []
# cur_idx = 0
# for idx, pair in enumerate(pairs_test_after, 1):
# print(f"{idx}/{len(pairs_test_after)}")
# txtfile1 = open(pair[0]).read().lower()
# txtfile2 = open(pair[1]).read().lower()
# INPUT_FILE_LEN1 = len(txtfile1)
# INPUT_FILE_LEN2 = len(txtfile2)
# if INPUT_FILE_LEN1 < 100 or INPUT_FILE_LEN2 < 100:
#     print("Skipped")
#     continue
#
# for i in range(INPUT_FILE_LEN1 - SEQ_LENGTH):
#     windows.append(
#         np.array(
#             list(
#                 char_to_int[a] if a in chars else 0
#                 for a in txtfile1[i : i + SEQ_LENGTH]
#             )
#         ).reshape(-1, 1)
#     )
#     cur_idx += 1
#
# w_indices.append(cur_idx + 1)
#
# for i in range(INPUT_FILE_LEN2 - SEQ_LENGTH):
#     windows.append(
#         np.array(
#             list(
#                 char_to_int[a] if a in chars else 0
#                 for a in txtfile2[i : i + SEQ_LENGTH]
#             )
#         ).reshape(-1, 1)
#     )
#     cur_idx += 1
#
# w_indices.append(cur_idx + 1)
# y_actual_after.append(0 if pair[-1] == "np" else 1)

# windows = np.array(windows)
# del pairs_test_after
# del chars
# del char_to_int
# del int_to_char
#
# window_vectors = vector_gen.predict(windows)
# print("Generated vectors")
# del windows
# del model
# del vector_gen
#
# for idx, num in enumerate(w_indices):
#     if idx == 0:
#         start = 0
#     else:
#         start = w_indices[idx - 1]
#
#     a = np.mean(window_vectors[start:num], axis=0)
#     if np.isnan(a).any():
#         continue
#     if idx % 2:
#         v1_arr_after.append(a)
#     else:
#         v2_arr_after.append(a)
#
# v1_arr_after = np.array(v1_arr_after)
# v2_arr_after = np.array(v2_arr_after)
#
# pickle.dump(v1_arr_after, open("v1_arr_after.pkl", "wb"))
# pickle.dump(v2_arr_after, open("v2_arr_after.pkl", "wb"))

# v1_arr_before = pickle.load(open("v1_arr_before.pkl", "rb"))
# v2_arr_before = pickle.load(open("v2_arr_before.pkl", "rb"))
# v1_arr_after = pickle.load(open("v1_arr_after.pkl", "rb"))
# v2_arr_after = pickle.load(open("v2_arr_after.pkl", "rb"))
pca = pickle.load(open("PCA.pkl", "rb"))
scaler = pickle.load(open("mmscaler.pkl", "rb"))

X_before = v1_arr_before - v2_arr_before
# X_after = v1_arr_after - v2_arr_after
X_before_red = pca.transform(X_before)
# X_after_red = pca.fit_transform(X_after)
pwd = os.getcwd()
generate_text_features(
    train=False,
    res_dir="",
    pairs_file="/home/anirudh/Projects/PlagDetect/plag-detect-psrl/extraction/result_test/pairs_graph.pkl",
)
os.chdir(pwd)
ld_rat = np.array(pickle.load(open("text_features/ld_rat.pkl", "rb"))).reshape(-1, 1)
ad = np.array(pickle.load(open("text_features/ad.pkl", "rb"))).reshape(-1, 1)
cl_rat = np.array(pickle.load(open("text_features/cl_rat.pkl", "rb"))).reshape(-1, 1)
cc_rat = np.array(pickle.load(open("text_features/cc_rat.pkl", "rb"))).reshape(-1, 1)
ed = np.array(pickle.load(open("text_features/ed.pkl", "rb"))).reshape(-1, 1)
X_before_red = np.concatenate((X_before_red, ld_rat, ad, ed, cl_rat, cc_rat), axis=1)
X_before_red = scaler.transform(X_before_red)


y_pred_before = classifier.predict(X_before_red)
# y_pred_after = classifier.predict(X_after_red)

tot = [0] * 6
cnt = [0] * 6

for i, j, k in zip(categories, y_actual_before, y_pred_before):
    tot[i] += 1
    if j == k:
        cnt[i] += 1

yval = np.array(cnt) / np.array(tot) * 100
pickle.dump(yval, open("../acc_rnn.pkl", "wb"))
