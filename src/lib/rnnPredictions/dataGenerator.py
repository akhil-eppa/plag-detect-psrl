import numpy as np
import pickle
from keras.utils import Sequence, np_utils

chars = pickle.load(open("chars.pkl", "rb"))
VOCAB_LENGTH = len(chars)
char_to_int = dict((c, i) for i, c in enumerate(chars))
int_to_char = dict((i, c) for i, c in enumerate(chars))


class DataGenerator(Sequence):
    "Generates data for Keras"

    def __init__(
        self,
        list_IDs,
        data_file,
        batch_size=128,
        dim=(1, 1, 1),
        n_classes=10,
        seq_length=100,
        sample_size=100000,
        shuffle=False,
    ):
        "Initialization"
        self.data_file = data_file
        self.seq_length = seq_length
        self.sample_size = sample_size
        self.dim = dim
        self.batch_size = batch_size
        self.list_IDs = list_IDs
        self.n_classes = n_classes
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
        X = np.empty((self.batch_size, self.seq_length, 1))
        y = np.empty((self.batch_size), dtype=int)

        # Generate data
        for i, ID in enumerate(list_IDs_temp):
            # Store sample
            seq_in = self.data_file[ID : ID + self.seq_length]
            X[i,] = (
                np.array([char_to_int[char] for char in seq_in]) / float(VOCAB_LENGTH)
            ).reshape(-1, 1)

            # Store class
            seq_out = self.data_file[ID + self.seq_length]
            y[i] = char_to_int[seq_out]

        return X, np_utils.to_categorical(y, num_classes=self.n_classes)

