# plag-detect-psrl
Machine Learning Based Source Code Plagiarism Detector

## Dataset Created
* Approximately 1250 pairs of source codes
* Approximately 550 non plagiarized pairs
* Approximately 700 plagiarized pairs

## Feature Extraction :
### Textual Features :
* difference in number of lines between 2 codes in a pair (raw and ratio)
* difference in average line length between 2 codes in a pair
* edit distance between 2 codes in a pair
* number of common lines between 2 codes in a pair (raw and ratio) 
 
 ratio is calculated as **number of common lines / max(number of lines in each pair)**
* number of common comments between 2 codes in a pair(raw and ratio)
        
ratio is calculated as **number of common comments / max(number of comments in each pair)**



# ML Models
## 1. KNN without PCA 
Got accuracy of 96.37 %
```
Accuracy: 0.9637096774193549
[[147   5]
 [  4  92]]

Feature scores using permuatation importance
Feature: 0, Score: 0.00988
Feature: 1, Score: 0.01472
Feature: 2, Score: 0.00726
Feature: 3, Score: 0.00101
Feature: 4, Score: 0.00948
Feature: 5, Score: 0.00282
Feature: 6, Score: 0.00000
Feature: 7, Score: 0.00927
Feature: 8, Score: 0.00504
Feature: 9, Score: 0.00000
Feature: 10, Score: 0.00423
Feature: 11, Score: 0.00726
Feature: 12, Score: 0.00685
Feature: 13, Score: 0.00363
Feature: 14, Score: 0.01028
Feature: 15, Score: 0.00524
Feature: 16, Score: 0.00383
Feature: 17, Score: 0.00262
Feature: 18, Score: 0.00948
Feature: 19, Score: 0.00544
Feature: 20, Score: 0.00605
Feature: 21, Score: 0.00786
Feature: 22, Score: 0.00665
Feature: 23, Score: 0.00504
Feature: 24, Score: 0.00464
Feature: 25, Score: 0.00746
Feature: 26, Score: 0.00020
Feature: 27, Score: 0.00343
Feature: 28, Score: 0.00161
Feature: 29, Score: 0.00101
Feature: 30, Score: 0.00101
Feature: 31, Score: 0.00000
Feature: 32, Score: 0.00000
Feature: 33, Score: 0.00141
Feature: 34, Score: 0.00081
Feature: 35, Score: 0.00706
Feature: 36, Score: 0.00847
Feature: 37, Score: 0.00423
Feature: 38, Score: 0.00827
Feature: 39, Score: 0.00423
Feature: 40, Score: 0.00544
Feature: 41, Score: 0.00827
Feature: 42, Score: 0.01089
Feature: 43, Score: 0.00806
Feature: 44, Score: 0.00827
Feature: 45, Score: 0.00605
Feature: 46, Score: 0.00665
Feature: 47, Score: 0.00605
Feature: 48, Score: 0.00383
Feature: 49, Score: 0.00383
Feature: 50, Score: 0.01431
Feature: 51, Score: 0.00000
Feature: 52, Score: 0.00706
Feature: 53, Score: 0.00504
Feature: 54, Score: 0.00665
Feature: 55, Score: 0.00927
Feature: 56, Score: 0.00504
Feature: 57, Score: 0.00585
Feature: 58, Score: 0.01492
Feature: 59, Score: 0.01089
Feature: 60, Score: 0.00444
Feature: 61, Score: 0.00363
Feature: 62, Score: 0.00302
Feature: 63, Score: 0.00605
Feature: 64, Score: 0.00504
Feature: 65, Score: 0.00605
Feature: 66, Score: 0.06734
Feature: 67, Score: 0.11230
Feature: 68, Score: 0.00040
Feature: 69, Score: 0.01714
```
![knn1](https://user-images.githubusercontent.com/42675875/84623651-58eb5c80-aefd-11ea-9b36-1dacccae7589.png)


## 2. KNN with PCA 
Got accuracy of 97.98%
```
Accuracy: 0.9798387096774194
[[139   2]
 [  3 104]]
 
 
 
Feature: 0, Score: 0.36109
Feature: 1, Score: 0.04012
Feature: 2, Score: 0.02278
Feature: 3, Score: 0.01290
Feature: 4, Score: 0.02560
Feature: 5, Score: 0.01472
Feature: 6, Score: 0.01976
Feature: 7, Score: 0.01754
Feature: 8, Score: 0.01935
Feature: 9, Score: 0.01149
Feature: 10, Score: 0.01169
Feature: 11, Score: 0.00847
Feature: 12, Score: 0.00544
Feature: 13, Score: 0.01008
Feature: 14, Score: 0.01028
Feature: 15, Score: 0.01089
Feature: 16, Score: 0.00786
Feature: 17, Score: 0.00907
Feature: 18, Score: 0.00827
Feature: 19, Score: 0.00847
Feature: 20, Score: 0.00847
Feature: 21, Score: 0.00847
Feature: 22, Score: 0.00786
Feature: 23, Score: 0.00806
Feature: 24, Score: 0.00645
Feature: 25, Score: 0.00625
Feature: 26, Score: 0.00504
Feature: 27, Score: 0.00625
Feature: 28, Score: 0.00685
Feature: 29, Score: 0.00565
```

![knn2](https://user-images.githubusercontent.com/42675875/84620871-c051de00-aef6-11ea-91cf-a0866fdf48ea.png)

## 3. SVM without PCA
Got accuracy of 98.79%
Best hyperparameters obtained using GridSearchCV
```
Accuracy: 0.9879032258064516
[[139   1]
 [  2 106]]
              precision    recall  f1-score   support

           0       0.99      0.99      0.99       140
           1       0.99      0.98      0.99       108

    accuracy                           0.99       248
   macro avg       0.99      0.99      0.99       248
weighted avg       0.99      0.99      0.99       248

Feature: 0, Score: 0.01190
Feature: 1, Score: 0.00101
Feature: 2, Score: 0.00000
Feature: 3, Score: 0.00081
Feature: 4, Score: 0.00081
Feature: 5, Score: 0.00000
Feature: 6, Score: 0.00141
Feature: 7, Score: 0.00181
Feature: 8, Score: 0.00000
Feature: 9, Score: 0.00060
Feature: 10, Score: 0.00161
Feature: 11, Score: 0.00020
Feature: 12, Score: 0.00000
Feature: 13, Score: 0.00060
Feature: 14, Score: 0.00040
Feature: 15, Score: 0.00000
Feature: 16, Score: 0.00020
Feature: 17, Score: 0.00484
Feature: 18, Score: 0.00000
Feature: 19, Score: 0.00323
Feature: 20, Score: 0.00141
Feature: 21, Score: 0.00020
Feature: 22, Score: 0.00000
Feature: 23, Score: 0.00020
Feature: 24, Score: 0.01270
Feature: 25, Score: 0.00000
Feature: 26, Score: 0.00181
Feature: 27, Score: 0.00202
Feature: 28, Score: 0.00060
Feature: 29, Score: 0.00000
Feature: 30, Score: 0.00000
Feature: 31, Score: 0.00000
Feature: 32, Score: 0.00040
Feature: 33, Score: 0.00000
Feature: 34, Score: 0.00202
Feature: 35, Score: 0.00161
Feature: 36, Score: 0.00040
Feature: 37, Score: 0.00786
Feature: 38, Score: 0.00060
Feature: 39, Score: 0.00423
Feature: 40, Score: 0.00101
Feature: 41, Score: 0.01310
Feature: 42, Score: 0.00101
Feature: 43, Score: 0.00000
Feature: 44, Score: 0.00020
Feature: 45, Score: 0.00020
Feature: 46, Score: 0.00141
Feature: 47, Score: 0.00020
Feature: 48, Score: 0.00000
Feature: 49, Score: 0.00121
Feature: 50, Score: 0.00000
Feature: 51, Score: 0.00060
Feature: 52, Score: 0.00000
Feature: 53, Score: 0.00302
Feature: 54, Score: 0.00101
Feature: 55, Score: 0.00020
Feature: 56, Score: 0.00000
Feature: 57, Score: 0.00645
Feature: 58, Score: 0.01270
Feature: 59, Score: 0.00000
Feature: 60, Score: 0.00020
Feature: 61, Score: 0.00000
Feature: 62, Score: 0.00020
Feature: 63, Score: 0.00060
Feature: 64, Score: 0.00343
Feature: 65, Score: 0.04093
Feature: 66, Score: 0.21754
Feature: 67, Score: 0.00000
Feature: 68, Score: 0.00343
```
![svm1](https://user-images.githubusercontent.com/42675875/84623317-a61afe80-aefc-11ea-98b0-5a75ebac21ec.png)


## 4. SVM with PCA
Got accuracy of 99.59%
Best hyperparameters obtained using GridSearchCV
```
SVC(C=10, gamma=1)
Accuracy: 0.9959677419354839
[[140   0]
 [  1 107]]
              precision    recall  f1-score   support

           0       0.99      1.00      1.00       140
           1       1.00      0.99      1.00       108

    accuracy                           1.00       248
   macro avg       1.00      1.00      1.00       248
weighted avg       1.00      1.00      1.00       248

[Parallel(n_jobs=1)]: Done 240 out of 240 | elapsed:   13.3s finished
Feature: 0, Score: 0.34032
Feature: 1, Score: 0.01875
Feature: 2, Score: 0.01573
Feature: 3, Score: 0.00141
Feature: 4, Score: 0.00927
Feature: 5, Score: 0.00242
Feature: 6, Score: 0.03770
Feature: 7, Score: 0.00242
Feature: 8, Score: 0.00101
Feature: 9, Score: -0.00020
Feature: 10, Score: -0.00020
Feature: 11, Score: -0.00020
Feature: 12, Score: 0.00020
Feature: 13, Score: 0.00867
Feature: 14, Score: 0.00020
Feature: 15, Score: -0.00060
Feature: 16, Score: 0.00121
Feature: 17, Score: -0.00060
Feature: 18, Score: 0.00000
Feature: 19, Score: 0.00383
Feature: 20, Score: 0.00000
Feature: 21, Score: 0.00141
Feature: 22, Score: 0.00363
Feature: 23, Score: 0.00202
Feature: 24, Score: 0.00141
Feature: 25, Score: 0.00464
Feature: 26, Score: 0.00081
Feature: 27, Score: 0.00060
Feature: 28, Score: 0.00141
Feature: 29, Score: -0.00121
```

![svm2](https://user-images.githubusercontent.com/42675875/84622703-42dc9c80-aefb-11ea-8ccc-02f74cf5345d.png)
