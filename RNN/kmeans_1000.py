# -*- coding: utf-8 -*-
"""
Created on Fri Jul 10 11:31:36 2020

@author: Akhil
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

df=pd.read_csv('vectors.csv')
x=df.iloc[:, :].values
kmeans1000=KMeans(n_clusters=1000)
ymeans1000=kmeans1000.fit_predict(x)
print(kmeans1000.cluster_centers_)

'''
Error =[]
for i in range(1, 11):
    kmeans = KMeans(n_clusters = i).fit(x)
    kmeans.fit(x)
    Error.append(kmeans.inertia_)
import matplotlib.pyplot as plt
plt.plot(range(1, 11), Error)
plt.title('Elbow method')
plt.xlabel('No of clusters')
plt.ylabel('Error')
plt.show()
'''