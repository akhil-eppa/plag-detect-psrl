# -*- coding: utf-8 -*-
"""
Created on Tue Jun 16 16:09:28 2020

@author: Akhil
"""

import matplotlib.patches as mpatches
import matplotlib.pyplot as plt


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
x = x.sample(frac=1).reset_index(drop=True)
#print(x.shape)
'''
Labels are the last column
Features are all the remaining columns
'''
#X=x.iloc[:,:-1]
mm_scaler = preprocessing.MinMaxScaler()
#X=mm_scaler.fit_transform(X)
x=mm_scaler.fit_transform(x)
#Y=x.iloc[:,-1:]
cols=list()
cols2=list()
for i in range(70):
    cols2.append("ft"+str(i))
cols2.append("y")
x=pd.DataFrame(data=x,columns=cols2)
x.columns=cols2
colors=['green','red']
comp=3
pca = PCA(n_components=3)
pca_result = pca.fit_transform(x.iloc[:,:-1])
x['pca-one'] = pca_result[:,0]
x['pca-two'] = pca_result[:,1] 
x['pca-three'] = pca_result[:,2]
'''sns.color_palette("hls", 2),'''
plt.figure(figsize=(16,10))
sns.scatterplot(
    x="pca-one", y="pca-two",
    hue="y",
    palette=colors,
    data=x,
    legend="full",
    alpha=0.3
)
ax = plt.figure(figsize=(16,10)).gca(projection='3d')
ax.scatter(
    xs=x["pca-one"], 
    ys=x["pca-two"], 
    zs=x["pca-three"], 
    c=x["y"], 
    cmap=matplotlib.colors.ListedColormap(colors)
)
ax.set_xlabel('pca-one')
ax.set_ylabel('pca-two')
ax.set_zlabel('pca-three')
red_patch = mpatches.Patch(color='red', label='plagiarized')
green_patch=mpatches.Patch(color="green",label='non plagiazrized')
plt.legend(handles=[red_patch,green_patch])

#plt.show()
plt.show()