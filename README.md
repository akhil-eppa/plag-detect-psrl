# plag-detect-psrl
Machine Learning Based Source Code Plagiarism Detector

## Dataset Created
* Approximately 1100 pairs of source codes
* Approximately 600 non plagiarized pairs
* Approximately 500 plagiarized pairs

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
Got accuracy of 84.67 %
```
Accuracy: 0.8467741935483871
[[138   5]
 [ 33  72]]



Feature Scores using permutation importance:
Feature: 0, Score: 0.00060
Feature: 1, Score: 0.00000
Feature: 2, Score: 0.00000
Feature: 3, Score: 0.00000
Feature: 4, Score: 0.00060
Feature: 5, Score: 0.00000
Feature: 6, Score: 0.00000
Feature: 7, Score: 0.00060
Feature: 8, Score: 0.00000
Feature: 9, Score: 0.00000
Feature: 10, Score: 0.00020
Feature: 11, Score: 0.00020
Feature: 12, Score: 0.00000
Feature: 13, Score: 0.00121
Feature: 14, Score: 0.00040
Feature: 15, Score: 0.00000
Feature: 16, Score: 0.00101
Feature: 17, Score: 0.00000
Feature: 18, Score: 0.00000
Feature: 19, Score: 0.00000
Feature: 20, Score: 0.00000
Feature: 21, Score: 0.00000
Feature: 22, Score: 0.00000
Feature: 23, Score: 0.00020
Feature: 24, Score: 0.00000
Feature: 25, Score: 0.00020
Feature: 26, Score: 0.00000
Feature: 27, Score: 0.00040
Feature: 28, Score: 0.00000
Feature: 29, Score: 0.00000
Feature: 30, Score: 0.00000
Feature: 31, Score: 0.00000
Feature: 32, Score: 0.00000
Feature: 33, Score: 0.00000
Feature: 34, Score: 0.00000
Feature: 35, Score: 0.00020
Feature: 36, Score: 0.00000
Feature: 37, Score: 0.00020
Feature: 38, Score: 0.00000
Feature: 39, Score: 0.00040
Feature: 40, Score: 0.00020
Feature: 41, Score: 0.00181
Feature: 42, Score: 0.00040
Feature: 43, Score: 0.00121
Feature: 44, Score: 0.00020
Feature: 45, Score: 0.00343
Feature: 46, Score: 0.00343
Feature: 47, Score: 0.00101
Feature: 48, Score: 0.00020
Feature: 49, Score: 0.00000
Feature: 50, Score: 0.00000
Feature: 51, Score: 0.00000
Feature: 52, Score: 0.00000
Feature: 53, Score: 0.00423
Feature: 54, Score: 0.00040
Feature: 55, Score: 0.00020
Feature: 56, Score: 0.00444
Feature: 57, Score: 0.01875
Feature: 58, Score: 0.00000
Feature: 59, Score: 0.00040
Feature: 60, Score: 0.12056
Feature: 61, Score: 0.35222
Feature: 62, Score: 0.00000
Feature: 63, Score: 0.00020
Feature: 64, Score: 0.00000
Feature: 65, Score: 0.07581
Feature: 66, Score: 0.04516
Feature: 67, Score: 0.09516
Feature: 68, Score: 0.13165
Feature: 69, Score: 0.00403
```

![knn1](https://user-images.githubusercontent.com/42675875/84620490-c8f5e480-aef5-11ea-8548-a157efee28bd.png)


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
