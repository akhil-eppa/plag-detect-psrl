# -*- coding: utf-8 -*-
"""
Created on Tue Jun 16 11:20:17 2020

@author: Akhil
"""

import numpy as np 
import pandas as pd 
from sklearn.metrics import confusion_matrix 
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier 
from sklearn.metrics import accuracy_score 
from sklearn.metrics import classification_report   
from sklearn import preprocessing
from matplotlib import pyplot
from sklearn.inspection import permutation_importance
from sklearn.decomposition import PCA
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
X=x.iloc[:,:-1]
mm_scaler = preprocessing.MinMaxScaler()
X=mm_scaler.fit_transform(X)
Y=x.iloc[:,-1:]
#print(X)
#print(Y)
#Y=labels.fit_transform(Y)
'''
Getting the principal components
'''
comp=30
pca=PCA(n_components=comp)
principalComponent=pca.fit_transform(X)
cols=list()
for i in range(comp):
    cols.append('principal_comp_'+str(i+1))
#Y=pd.DataFrame(Y)
principalDf=pd.DataFrame(data=principalComponent,columns=cols)
#print(Y)
'''
20% data is test data
'''
X_train, X_test, y_train, y_test = train_test_split(principalDf, Y, test_size=0.2, random_state=100)
print(X_train.shape)
print(y_train.shape)
print(X_test.shape)
print(y_test.shape)
#print(X_train)
#print(y_test)

'''
The model uses both entropy and gini index
'''

# Creating the classifier object with giniIndex
model_gini = DecisionTreeClassifier(criterion = "gini", random_state = 101,max_depth=4, min_samples_leaf=5)
model_gini.fit(X_train, y_train) 

#Printing Gini results
print("Results Using Gini Index:") 
y_pred_gini = model_gini.predict(X_test)
#print("Predicted values:")
#print(y_pred_gini)
print("Confusion Matrix: ", confusion_matrix(y_test, y_pred_gini)) 
      
print ("Accuracy : ",accuracy_score(y_test,y_pred_gini)*100) 
      
print("Report : ", classification_report(y_test, y_pred_gini))

# Creating the classifier object with Entropy
model_entropy = DecisionTreeClassifier( criterion = "entropy", random_state = 101, max_depth = 4, min_samples_leaf = 5)
model_entropy.fit(X_train, y_train) 

#Printing Entropy results
print("Results Using Entropy:") 
y_pred_entropy = model_entropy.predict(X_test)
#print("Predicted values:")
#print(y_pred_entropy)
print("Confusion Matrix: ", confusion_matrix(y_test, y_pred_entropy)) 
      
print ("Accuracy : ", accuracy_score(y_test,y_pred_entropy)*100) 
      
print("Report : ", classification_report(y_test, y_pred_entropy))

'''
importance = model_entropy.feature_importances_
# summarize feature importance
for i,v in enumerate(importance):
	print('Feature: %0d, Score: %.5f' % (i,v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)
pyplot.show()
'''
results = permutation_importance(model_entropy, X_train, y_train,scoring='accuracy')
importance = results.importances_mean
# summarize feature importance
for i,v in enumerate(importance):
	print('Feature: %0d, Score: %.5f' % (i,v))
# plot feature importance
pyplot.bar([x for x in range(len(importance))], importance)
pyplot.show()