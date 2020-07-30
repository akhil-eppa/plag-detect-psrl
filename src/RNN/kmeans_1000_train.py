# -*- coding: utf-8 -*-
"""
Created on Fri Jul 10 11:31:36 2020

@author: Akhil
"""

import os
import pickle

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.cluster import MiniBatchKMeans

vector_files = os.listdir("code_vectors")

kmeans1000 = MiniBatchKMeans(n_clusters=1000)
model = ""

for idx, batch in enumerate(vector_files, 1):
    print(f"{idx}/23000")
    X_batch = np.load(os.path.join("code_vectors", batch))
    model = kmeans1000.partial_fit(X_batch)
    if idx == 23000:
        break


pickle.dump(model, open("kmeans_1000.pkl", "wb"))

# '''
# Error =[]
# for i in range(1, 11):
#     kmeans = KMeans(n_clusters = i).fit(x)
#     kmeans.fit(x)
#     Error.append(kmeans.inertia_)
# import matplotlib.pyplot as plt
# plt.plot(range(1, 11), Error)
# plt.title('Elbow method')
# plt.xlabel('No of clusters')
# plt.ylabel('Error')
# plt.show()
# '''
