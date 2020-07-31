import pickle

import numpy as np
from keras.callbacks import EarlyStopping
from keras.layers import LSTM, Dense, Dropout
from keras.models import Sequential, load_model
from keras.utils import Sequence, np_utils

from dataGenerator import DataGenerator

SEQ_LENGTH = 100
EPOCHS = 40
BATCH_SIZE = 128
TRAIN_FILENAME = "fine_tune_data_utf8.txt"
txtfile = open(TRAIN_FILENAME).read().lower()
INPUT_FILE_LEN = len(txtfile)
chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)


model = load_model("char_rnn_model")
model_ft = Sequential()
for layer in model.layers[:-1]:
    layer.trainable = False
    model_ft.add(layer)
model.layers[-2].trainable = True
model.layers[-1].trainable = True
model_ft.add(Dense(VOCAB_LENGTH, activation="softmax"))
model_ft.compile(loss="categorical_crossentropy", optimizer="adam")
print(model_ft.summary())

early_stop = EarlyStopping(monitor="val_loss", patience=20, verbose=1, mode="min")
samples_train = int((INPUT_FILE_LEN - SEQ_LENGTH) * 0.9)
samples_val = INPUT_FILE_LEN - SEQ_LENGTH - samples_train
data_gen_train = DataGenerator(
    list(range(samples_train)),
    txtfile,
    dim=(samples_train, SEQ_LENGTH, 1),
    n_classes=VOCAB_LENGTH,
)
data_gen_val = DataGenerator(
    list(range(samples_train, samples_train + samples_val)),
    txtfile,
    dim=(samples_val, SEQ_LENGTH, 1),
    n_classes=VOCAB_LENGTH,
)
char_rnn = model_ft.fit_generator(
    data_gen_train,
    epochs=EPOCHS,
    verbose=1,
    validation_data=data_gen_val,
    callbacks=[early_stop],
)
model_ft.save("models/char_rnn_model_ft")
