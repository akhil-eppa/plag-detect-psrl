#include<stdio.h>
#define MAX_RANGE 500000
int elementArr[MAX_RANGE];
int isFirstDisplay = 0;
 
int insertIntoArayElement(int array[], int element, int pointer) {
	int pos = 0;
	int i;
	for (i = 0; i <= pointer; i++) {
		if (element >= array[i]) {
			pos = i;
			break;
		} else {
			pos = i;
		}
	}
	for (i = pointer - 1; i >= pos; i--) {
		array[i + 1] = array[i];
	}
	array[pos] = element;
	return (pointer + 1);
}
void merge(int elementArr[], int p, int q, int r) {
	int left[(q - p + 1)];
	int right[(r - q)];
	int i, j;
	int k = p;
	for (i = 0; i < (q - p + 1); i++) {
		left[i] = elementArr[k++];
	}
	for (j = 0; j < (r - q); j++) {
		right[j] = elementArr[k++];
	}
	i = 0;
	j = 0;
	k = p;
	while (i < (q - p + 1) && j < (r - q)) {
		if (left[i] > right[j]) {
			elementArr[k++] = left[i++];
		} else {
			elementArr[k++] = right[j++];
		}
	}
	while (i < (q - p + 1)) {
		elementArr[k++] = left[i++];
	}
	while (j < (r - q)) {
		elementArr[k++] = right[j++];
	}
}
void mergeSort(int elementsArr[], int p, int r) {
	if (p < r) {
		int mid = (p + r) / 2;
		mergeSort(elementsArr, p, mid);
		mergeSort(elementsArr, mid + 1, r);
		merge(elementArr, p, mid, r);
	}
}
int main() {
	int num;
	scanf("%d ", &num);
	int i;
	for (i = 0; i < num; i++) {
		elementArr[i] = 0;
	}
	int pointer = 0;
	for (i = 0; i < num; i++) {
		int type, element;
		scanf("%d ", &type);
		if (type == 1) {
			scanf("%d ", &element);
			if (isFirstDisplay == 0) {
				elementArr[pointer++] = element;
			} else {
				pointer = insertIntoArayElement(elementArr, element, pointer);
			}
 
		} else {
			if (isFirstDisplay == 0) {
				mergeSort(elementArr, 0, pointer - 1);
				isFirstDisplay = 1;
			}
			if ((pointer / 3) > 0) {
				printf("%d\n", elementArr[(pointer / 3) - 1]);
			} else {
				printf("Not enough enemies\n");
			}
 
		}
	}
 
	return 0;
}