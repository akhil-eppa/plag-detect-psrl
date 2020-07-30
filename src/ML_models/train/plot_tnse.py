# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 10:50:39 2020

@author: Akhil
"""

import matplotlib.patches as mpatches
import matplotlib.pyplot as plt

import time
from sklearn import preprocessing

import pandas as pd
from sklearn.decomposition import PCA
from matplotlib import pyplot

import matplotlib



from sklearn.manifold import TSNE

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import seaborn as sns
'''
LabelEncoder is used to label as 0 or 1 or 2 based on category
'''
labels=preprocessing.LabelEncoder()
dataset_name="feat_v1.csv"
x=pd.read_csv(dataset_name)
'''
Shuffling the order of rows in file
'''
#x = x.sample(frac=1).reset_index(drop=True)
#print(x.shape)
'''
Labels are the last column
Features are all the remaining columns
'''
#X=x.iloc[:,:-1]
mm_scaler = preprocessing.MinMaxScaler()
#X=mm_scaler.fit_transform(X)
x=mm_scaler.fit_transform(x)

cols2=list()
for i in range(70):
    cols2.append("ft"+str(i))
cols2.append("y")
x=pd.DataFrame(data=x,columns=cols2)
x.columns=cols2
colors=['green','red']

time_start = time.time()
tsne = TSNE(n_components=2, verbose=1, perplexity=40, n_iter=300)
tsne_results = tsne.fit_transform(x)
print('t-SNE done! Time elapsed: {} seconds'.format(time.time()-time_start))
x['tsne-2d-one'] = tsne_results[:,0]
x['tsne-2d-two'] = tsne_results[:,1]
plt.figure(figsize=(16,10))
sns.scatterplot(
    x="tsne-2d-one", y="tsne-2d-two",
    hue="y",
    palette=colors,
    data=x,
    legend="full",
    alpha=0.3
)


time_start = time.time()
tsne2 = TSNE(n_components=3, verbose=1, perplexity=40, n_iter=300)
tsne_results2 = tsne2.fit_transform(x)
print('t-SNE done! Time elapsed: {} seconds'.format(time.time()-time_start))

x['tsne-3d-one'] = tsne_results2[:,0]
x['tsne-3d-two'] = tsne_results2[:,1]
x['tsne-3d-three'] = tsne_results2[:,2]


ax = plt.figure(figsize=(16,10)).gca(projection='3d')
ax.scatter(
    xs=x["tsne-3d-one"], 
    ys=x["tsne-3d-two"], 
    zs=x["tsne-3d-three"], 
    c=x["y"], 
    cmap=matplotlib.colors.ListedColormap(colors)
)
ax.set_xlabel('t-sne-1')
ax.set_ylabel('t-sne-2')
ax.set_zlabel('t-sne-3')
red_patch = mpatches.Patch(color='red', label='plagiarized')
green_patch=mpatches.Patch(color="green",label='non plagiazrized')
plt.legend(handles=[red_patch,green_patch])

#plt.show()
plt.show()