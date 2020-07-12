import os
import pickle

import numpy as np
from keras.models import Model, load_model

SEQ_LENGTH = 100
chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)
TRAIN_FILENAME = "linux_utf8_nocomments.c"
FT_FILENAME = "fine_tune_data_utf8.txt"
file_text = (
    open(TRAIN_FILENAME, "r").read().lower() + open(FT_FILENAME, "r").read().lower()
)
char_to_int = dict((c, i) for i, c in enumerate(chars))
int_to_char = dict((i, c) for i, c in enumerate(chars))

model = load_model("char_rnn_model_ft")
vector_gen = Model(inputs=model.inputs, outputs=model.layers[-3].output)
BATCH_SIZE = 5000

window_batch = []
for window_idx in range(1, len(file_text) - SEQ_LENGTH + 1):
    cur_window = np.array(
        [
            char_to_int[i]
            for i in file_text[window_idx - 1 : window_idx - 1 + SEQ_LENGTH]
        ]
    ).reshape(-1, 1)
    window_batch.append(cur_window)
    if window_idx % BATCH_SIZE == 0:
        window_vectors = vector_gen.predict(np.array(window_batch))
        np.save(
            os.path.join("code_vectors", f"vec_batch_{window_idx//BATCH_SIZE}.npy"),
            window_vectors,
        )
        window_batch = []

if window_batch:
    window_vectors = vector_gen.predict(np.array(window_batch))
    np.save(
        os.path.join("code_vectors", f"vec_batch_{window_idx//BATCH_SIZE + 1}.npy"),
        window_vectors,
    )
