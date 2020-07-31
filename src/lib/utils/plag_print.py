# -*- coding: utf-8 -*-
"""
Created on Sun Jul 26 15:28:12 2020

@author: Akhil
"""

import pickle
from sklearn.decomposition import PCA
from sklearn import preprocessing
import pandas as pd
model = pickle.load(open('svm_pca_prob.pkl', 'rb'))
orig_data="feat_v1.csv"
x=pd.read_csv(orig_data)
X=x.iloc[:,:-1]
X=preprocessing.scale(X)
mm_scaler = preprocessing.MinMaxScaler()
X=mm_scaler.fit_transform(X)
comp=30
#print(X)
pca=PCA(n_components=comp)
X=pca.fit_transform(X)

test_data="filename.csv"
data=pd.read_csv(test_data)
dataX=data.iloc[:,:]
dataX=preprocessing.scale(dataX)
dataX=mm_scaler.fit_transform(dataX)
dataX=pca.fit_transform(dataX)
prob=model.predict_proba(dataX)
mylist=[]
plag_pairs=[]
threshold=0.5
with open('parrot.pkl', 'wb') as f:
    pickle.dump(mylist, f)
for i in prob:
    if i[1]>threshold:
        plag_pairs.append(mylist[i])
file=open("plag_pairs","w")
for i in plag_pairs:
    txt=i[0]+"and"+i[1]+"are possibly plagiarized.\n"
    file.write(txt)
file.close()
        