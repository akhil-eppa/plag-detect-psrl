import numpy as np
from keras.callbacks import EarlyStopping
from keras.layers import LSTM, Dense, Dropout
from keras.models import Sequential
from keras.utils import Sequence, np_utils

SEQ_LENGTH = 100
EPOCHS = 100
BATCH_SIZE = 128
TRAIN_FILENAME = "linux_utf8_nocomments.c"
txtfile = open(TRAIN_FILENAME).read().lower()
INPUT_FILE_LEN = len(txtfile)
chars = sorted(list(set(txtfile)))
VOCAB_LENGTH = len(chars)
print("The length of the file is : ", INPUT_FILE_LEN)
print("The vocab length is : ", VOCAB_LENGTH)
char_to_int = dict((c, i) for i, c in enumerate(chars))
int_to_char = dict((i, c) for i, c in enumerate(chars))
print(char_to_int)
print(int_to_char)


class DataGenerator(Sequence):
    "Generates data for Keras"

    def __init__(
        self,
        list_IDs,
        data_file,
        batch_size=128,
        dim=(1, 1, 1),
        n_classes=10,
        n_channels=1,
        seq_length=100,
        sample_size=100000,
        shuffle=False,
    ):
        "Initialization"
        self.data_file = data_file
        self.seq_length = seq_length
        self.sample_size=sample_size
        self.dim = dim
        self.batch_size = batch_size
        self.list_IDs = list_IDs
        self.n_classes = n_classes
        self.n_channels = n_channels
        self.shuffle = shuffle
        self.on_epoch_end()

    def __len__(self):
        "Denotes the number of batches per epoch"
        return int(np.floor(self.sample_size / self.batch_size))

    def __getitem__(self, index):
        "Generate one batch of data"
        # Generate indexes of the batch
        indexes = self.indexes[index * self.batch_size : (index + 1) * self.batch_size]

        # Find list of IDs
        list_IDs_temp = [self.list_IDs[k] for k in indexes]

        # Generate data
        X, y = self.__data_generation(list_IDs_temp)

        return X, y

    def on_epoch_end(self):
        "Updates indexes after each epoch"
        self.indexes = np.random.choice(np.arange(len(self.list_IDs)), self.sample_size)
        # if self.shuffle:
        #     np.random.shuffle(self.indexes)

    def __data_generation(self, list_IDs_temp):
        "Generates data containing batch_size samples"  # X : (n_samples, *dim, n_channels)
        # Initialization
        X = np.empty((self.batch_size, self.seq_length, self.n_channels))
        y = np.empty((self.batch_size), dtype=int)

        # Generate data
        for i, ID in enumerate(list_IDs_temp):
            # Store sample
            seq_in = self.data_file[ID : ID + self.seq_length]
            X[i,] = (np.array([char_to_int[char] for char in seq_in]) / float(
                VOCAB_LENGTH
            )).reshape((-1,1))

            # Store class
            seq_out = self.data_file[ID + self.seq_length]
            y[i] = char_to_int[seq_out]

        return X, np_utils.to_categorical(y, num_classes=self.n_classes)

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
    n_classes=len(chars),
)
data_gen_val = DataGenerator(
    list(range(samples_train, samples_train + samples_val)),
    txtfile,
    dim=(samples_val, SEQ_LENGTH, 1),
    n_classes=len(chars),
)

char_rnn = model.fit_generator(
    data_gen_train,
    epochs=EPOCHS,
    verbose=1,
    validation_data=data_gen_val,
    callbacks=[early_stop],
)
model.save("char_rnn_model")
