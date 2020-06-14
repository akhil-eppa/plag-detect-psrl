from sklearn.metrics import confusion_matrix,classification_report
from sklearn import preprocessing
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
import pandas as pd
import numpy as np
'''
LabelEncoder is used to label as 0 or 1 or 2 based on category
'''
labels=preprocessing.LabelEncoder()
dataset_name=".csv"
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
Y=labels.fit_transform(Y)
#print(Y)
'''
20% data is test data
'''
X_train, X_test, y_train, y_test = train_test_split(X, np.ravel(Y), test_size=0.2,random_state=101)
print(X_train.shape)
print(y_train.shape)
print(X_test.shape)
print(y_test.shape)
#print(X_train)
#print(y_test)

'''
Random Forest regressor model
'''
model = RandomForestRegressor(n_estimators = 100, random_state = 0) 
model.fit(X_train, y_train)   
y_pred=model.predict(X_test)
print(y_test)
print(y_pred)
'''
Print accuracy and the confusion matrix
'''
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))
print(confusion_matrix(y_test,y_pred))
print(classification_report(y_test,y_pred))