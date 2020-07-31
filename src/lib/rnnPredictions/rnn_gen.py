import pickle

from keras.callbacks import EarlyStopping
from keras.layers import LSTM, Dense, Dropout
from keras.models import Sequential


SEQ_LENGTH = 100
EPOCHS = 100
BATCH_SIZE = 128
TRAIN_FILENAME = "linux_utf8_nocomments.c"
FT_FILENAME = "fine_tune_data_utf8.txt"
txtfile = open(TRAIN_FILENAME).read().lower()
ftfile = open(FT_FILENAME).read().lower()
INPUT_FILE_LEN = len(txtfile)
chars = sorted(list(set(txtfile).union(set(ftfile))))
pickle.dump(chars, open("chars.pkl", "wb"))
VOCAB_LENGTH = len(chars)

from dataGenerator import DataGenerator


# Creating the model
model = Sequential()
model.add(LSTM(512, input_shape=(SEQ_LENGTH, 1), return_sequences=True))
model.add(Dropout(0.25))
model.add(LSTM(512, return_sequences=True))
model.add(Dropout(0.25))
model.add(LSTM(512))
model.add(Dropout(0.25))
model.add(Dense(len(chars), activation="softmax"))
model.compile(loss="categorical_crossentropy", optimizer="adam")
print(model.summary())
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
char_rnn = model.fit_generator(
    data_gen_train,
    epochs=EPOCHS,
    verbose=1,
    validation_data=data_gen_val,
    callbacks=[early_stop],
)
model.save("models/char_rnn_model")
