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
