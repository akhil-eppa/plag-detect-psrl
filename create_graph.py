import pickle

import matplotlib.pyplot as plt
import numpy as np

jplag = pickle.load(open("acc_jplag.pkl", "rb"))
moss = pickle.load(open("acc_moss.pkl", "rb"))
milepost = pickle.load(open("acc_milepost.pkl", "rb"))
rnn = pickle.load(open("acc_rnn.pkl", "rb"))
trans = pickle.load(open("acc_transformer.pkl", "rb"))

res = np.array((jplag, moss, milepost, rnn, trans * 100))
print(res.shape)
print(res.T[0])
print(res[0])

categories = [
    "variable name change",
    "redundant lines",
    "reordering lines",
    "variable type change",
    "loop type change",
    "reordering blocks",
]

x_labels = ["JPlag", "MOSS", "Milepost GCC", "Char-RNN", "Transformer"]
xval = np.array([1, 3, 5, 7, 9, 11])

# for cat, col in zip(categories, res.T):
#     plt.bar(x_labels, col)
#     plt.title(f"Plagiarism type - {cat}")
#     plt.savefig(f"results/acc_{cat.replace(' ', '_')}.png")
#     plt.cla()

ax = plt.subplot(111)
ax.bar(xval - 0.4, res[0], width=0.2)
ax.bar(xval - 0.2, res[1], width=0.2)
ax.bar(xval - 0.0, res[2], width=0.2)
ax.bar(xval + 0.2, res[3], width=0.2)
ax.bar(xval + 0.4, res[4], width=0.2)
# ax.bar(xval + 0.5, res.T[5], width=0.2)
plt.xticks([1, 3, 5, 7, 9, 11], categories, rotation=0)
plt.xlabel("Plagiarism method")
plt.ylabel("Accuracy(%)")
plt.legend(x_labels)
plt.show()
