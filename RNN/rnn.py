# -*- coding: utf-8 -*-
"""
Created on Fri Jun 19 10:59:54 2020

@author: Akhil
"""

import numpy
import os
import sys
import time
from keras.models import Sequential
from keras.layers import Activation
from keras.layers import Dense
from keras.layers import Dropout
from keras.layers import LSTM
from keras.utils import np_utils
from keras.callbacks import EarlyStopping

SEQ_LENGTH=100
EPOCHS=4000
BATCH_SIZE=128
train_filename="linux.txt"
txtfile=open(train_filename).read().lower()
INPUT_FILE_LEN=len(txtfile)
chars=sorted(list(set(txtfile)))
VOCAB_LENGTH=len(chars)
print("The length of the file is : ",INPUT_FILE_LEN)
print("The vocab length is : ",VOCAB_LENGTH)
char_to_int = dict((c,i) for i,c in enumerate(chars))
int_to_char = dict((i,c) for i,c in enumerate(chars))
print(char_to_int)
print(int_to_char)
dataX=list()
dataY=list()
for i in range(0, INPUT_FILE_LEN-SEQ_LENGTH, 1):
    seq_in = txtfile[i:i+SEQ_LENGTH]
    seq_out= txtfile[i+SEQ_LENGTH]
    dataX.append([char_to_int[char] for char in seq_in])
    dataY.append(char_to_int[seq_out])
samples=len(dataX)
print("no. of samples =",str(samples))

#reshape dataX
X=numpy.reshape(dataX, (samples,SEQ_LENGTH,1))

#normalize
X=X/float(VOCAB_LENGTH)

#one hot encoding of output variables
y=np_utils.to_categorical(dataY)
print("X.shape = ",str(X.shape))
print("y.shape = ",str(y.shape))

#Creating the model
model=Sequential()
model.add(LSTM(512, input_shape=(X.shape[1],X.shape[2]), return_sequences=True))
model.add(Dropout(0.25))
model.add(LSTM(512, return_sequences=True))
model.add(Dropout(0.25))
model.add(LSTM(512))
model.add(Dropout(0.25))
model.add(Dense(y.shape[1], activation='softmax'))
model.compile(loss='categorical_crossentropy', optimizer='adam')
print(model.summary())
early_stop = EarlyStopping(monitor='val_loss', patience=20, verbose=1, mode='min')
char_rnn=model.fit(X, y, epochs=EPOCHS, batch_size=BATCH_SIZE, verbose=1, validation_split=0.02, callbacks=[early_stop])
model.save("char_rnn_model")


'''
Model: "sequential_2"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
lstm_3 (LSTM)                (None, 100, 512)          1052672   
_________________________________________________________________
dropout_2 (Dropout)          (None, 100, 512)          0         
_________________________________________________________________
lstm_4 (LSTM)                (None, 100, 512)          2099200   
_________________________________________________________________
dropout_3 (Dropout)          (None, 100, 512)          0         
_________________________________________________________________
lstm_5 (LSTM)                (None, 512)               2099200   
_________________________________________________________________
dropout_4 (Dropout)          (None, 512)               0         
_________________________________________________________________
dense_1 (Dense)              (None, 53)                27189     
=================================================================
Total params: 5,278,261
Trainable params: 5,278,261
Non-trainable params: 0
'''


'''
Epoch 1/10
3137/3137 [==============================] - 188s 60ms/step - loss: 3.4797
Epoch 2/10
3137/3137 [==============================] - 192s 61ms/step - loss: 3.4713
Epoch 3/10
3137/3137 [==============================] - 199s 63ms/step - loss: 3.4534
Epoch 4/10
3137/3137 [==============================] - 168s 53ms/step - loss: 3.4401
Epoch 5/10
3137/3137 [==============================] - 162s 52ms/step - loss: 3.4384
Epoch 6/10
3137/3137 [==============================] - 169s 54ms/step - loss: 3.4403
Epoch 7/10
3137/3137 [==============================] - 163s 52ms/step - loss: 3.4267
Epoch 8/10
3137/3137 [==============================] - 162s 52ms/step - loss: 3.4298
Epoch 9/10
3137/3137 [==============================] - 164s 52ms/step - loss: 3.4234
Epoch 10/10
3137/3137 [==============================] - 615s 196ms/step - loss: 3.4228
'''