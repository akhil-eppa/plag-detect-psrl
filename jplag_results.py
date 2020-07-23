import csv
import os
import pickle

import matplotlib.pyplot as plt

import numpy as np

pairs = pickle.load(open("extraction/result_test/pairs_graph.pkl", "rb"))
chk = [0] * len(pairs)
mapchk = dict((os.path.basename(pair[0]), idx) for idx, pair in enumerate(pairs))
map2 = dict((os.path.basename(pair[1]), idx) for idx, pair in enumerate(pairs))
mapchk.update(map2)
mappair1 = dict(
    (os.path.basename(pair[0]), os.path.basename(pair[1])) for pair in pairs
)
mappair2 = dict(
    (os.path.basename(pair[1]), os.path.basename(pair[0])) for pair in pairs
)
mapclass = dict()

tot = [0] * 6
for pair in pairs:
    tot[pair[2]] += 1
    mapclass[os.path.basename(pair[0])] = pair[2]
    mapclass[os.path.basename(pair[1])] = pair[2]

cnt = [0] * 6

with open("matches_avg.csv") as f:
    r = csv.reader(f, delimiter=";")
    for row in r:
        if not chk[mapchk[row[0]]]:
            chk[mapchk[row[0]]] = 1
            pair = mappair1.get(row[0], mappair2.get(row[0]))
            if pair in row:
                cnt[mapclass[pair]] += 1

yval = np.array(cnt) / np.array(tot) * 100

x_labels = [
    "Variable name change",
    "Redundant lines",
    "Reorder lines",
    "Variable type change",
    "Change loop type",
    "Reorder blocks",
]
plt.bar(x_labels, yval)
plt.xticks(rotation=20)
plt.show()
