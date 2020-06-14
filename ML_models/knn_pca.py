# -*- coding: utf-8 -*-
"""
Created on Sat Jun 13 14:22:21 2020

@author: Akhil
"""

# -*- coding: utf-8 -*-
"""
Created on Tue Jun  9 11:35:39 2020

@author: Akhil
"""

from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix
from sklearn import preprocessing
from sklearn import metrics
from sklearn.model_selection import train_test_split
import pandas as pd
from sklearn.decomposition import PCA
from matplotlib import pyplot

'''
LabelEncoder is used to label as 0 or 1 or 2 based on category
'''
labels=preprocessing.LabelEncoder()
dataset_name="iris.csv"
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
X=x.iloc[:,:-1]
mm_scaler = preprocessing.MinMaxScaler()
X=mm_scaler.fit_transform(X)
Y=x.iloc[:,-1:]
#print(X)
#print(Y)
Y=labels.fit_transform(Y)
'''
Getting the principal components
'''
comp=2
pca=PCA(n_components=comp)
principalComponent=pca.fit_transform(X)
cols=list()
for i in range(comp):
    cols.append('principal_comp_'+str(i+1))
#Y=pd.DataFrame(Y)
principalDf=pd.DataFrame(data=principalComponent,columns=cols)
#finalDf=pd.concat([principalDf,Y],axis=1)
#print(cols)
#print(Y)
'''
20% data is test data
'''
X_train, X_test, y_train, y_test = train_test_split(principalDf, Y.ravel(), test_size=0.2)
print(X_train.shape)
print(y_train.shape)
print(X_test.shape)
print(y_test.shape)
#print(X_train)
#print(y_test)
'''
Number of neighbors considered=7
weights are not uniform but nearer elements will have more weight
like cosine similarity
algorithm is set as suto
'''
model=KNeighborsClassifier(n_neighbors=7, weights='distance', algorithm='auto')
model.fit(X_train,y_train.ravel())
y_pred=model.predict(X_test)
''' 
importance = model.
for i,v in enumerate(importance):
	print('Feature: %0d, Score: %.5f' % (i,v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)
pyplot.show()
'''
#print(y_test)
#print(y_pred)
'''
Print accuracy and the confusion matrix
'''
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))
print(confusion_matrix(y_test,y_pred))

results = permutation_importance(model, X_train, y_train, scoring='accuracy')
# get importance
importance = results.importances_mean
# summarize feature importance
for i,v in enumerate(importance):
	print('Feature: %0d, Score: %.5f' % (i,v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)
pyplot.show()