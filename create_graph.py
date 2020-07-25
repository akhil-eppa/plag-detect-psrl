import pickle

import matplotlib.pyplot as plt
import numpy as np

jplag = pickle.load(open("acc_jplag.pkl", "rb"))
moss = pickle.load(open("acc_moss.pkl", "rb"))
milepost = pickle.load(open("acc_milepost.pkl", "rb"))
rnn = pickle.load(open("acc_rnn.pkl", "rb"))

res = np.array((jplag, moss, milepost, rnn))

categories = [
    "variable name change",
    "redundant lines",
    "reordering lines",
    "variable type change",
    "loop type change",
    "reordering blocks",
]

x_labels = ["JPlag", "MOSS", "Milepost GCC", "Char-RNN"]

for cat, col in zip(categories, res.T):
    plt.bar(x_labels, col)
    plt.title(f"Plagiarism type - {cat}")
    plt.show()
    plt.savefig(f"acc_{cat.replace(' ', '_')}.png")
