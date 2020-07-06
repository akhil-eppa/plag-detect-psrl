import pickle

import numpy as np
from keras.models import Model, load_model
from sklearn.svm import SVC
from sklearn.decomposition import PCA

# SEQ_LENGTH = 100
# chars = pickle.load(open("chars.pkl", "rb"))
# VOCAB_LENGTH = len(chars)
# char_to_int = dict((c, i) for i, c in enumerate(chars))
# int_to_char = dict((i, c) for i, c in enumerate(chars))
# 
# model = load_model("char_rnn_model_ft")
# vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)
# 
pairs = pickle.load(
    open(
        "/home/anirudh/Projects/PlagDetect/plag-detect-psrl/extraction/result_train/pairs.pkl",
        "rb",
    )
)
y_actual = []
# v1_arr = []
# v2_arr = []
# windows = []
# w_indices = []
# cur_idx = 0
for idx, pair in enumerate(pairs, 1):
    # print(f"{idx}/{len(pairs)}")
    y_actual.append(0 if pair[-1] == "np" else 1)
#     txtfile1 = open(pair[0]).read().lower()
#     INPUT_FILE_LEN1 = len(txtfile1)
#     for i in range(INPUT_FILE_LEN1 - SEQ_LENGTH):
#         windows.append(
#             np.array(
#                 list(
#                     char_to_int[a] if a in chars else 0
#                     for a in txtfile1[i : i + SEQ_LENGTH]
#                 )
#             ).reshape(-1, 1)
#         )
#         cur_idx += 1
# 
#     w_indices.append(cur_idx + 1)
# 
#     txtfile2 = open(pair[1]).read().lower()
#     INPUT_FILE_LEN2 = len(txtfile2)
#     for i in range(INPUT_FILE_LEN2 - SEQ_LENGTH):
#         windows.append(
#             np.array(
#                 list(
#                     char_to_int[a] if a in chars else 0
#                     for a in txtfile2[i : i + SEQ_LENGTH]
#                 )
#             ).reshape(-1, 1)
#         )
#         cur_idx += 1
# 
#     w_indices.append(cur_idx + 1)
# 
# windows = np.array(windows)
# del pairs
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
#     if idx % 2:
#         v1_arr.append(a)
#     else:
#         v2_arr.append(a)
# 
# v1_arr = np.array(v1_arr)
# v2_arr = np.array(v2_arr)
# 
# pickle.dump(v1_arr, open("v1_arr.pkl", "wb"))
# pickle.dump(v2_arr, open("v2_arr.pkl", "wb"))

v1_arr = pickle.load(open("v1_arr.pkl", "rb"))
v2_arr = pickle.load(open("v2_arr.pkl", "rb"))
pca = PCA(n_components=250)

X = v1_arr - v2_arr
X_red = pca.fit_transform(X)
model = SVC()
classifier = model.fit(X_red, y_actual)
pickle.dump(classifier, open("SVM_RNN.pkl", "wb"))
