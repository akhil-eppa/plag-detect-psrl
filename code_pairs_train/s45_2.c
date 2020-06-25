#include <stdio.h>
 
int binarySearch(int a[], int item, int low, int high) {
	if (high <= low)
		return (item > a[low])?  (low + 1): low;
	int mid = (low + high)/2;
	if(item == a[mid])
		return mid+1;
	if(item > a[mid])
		return binarySearch(a, item, mid+1, high);
	return binarySearch(a, item, low, mid-1);
}
 
void insertionSort(int a[], int p, int size) {
	int j, selected;
	j = size - 1;
	selected = p;
	int loc = binarySearch(a, selected, 0, j);
	while (j >= loc) {
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = selected;
}
 
int main() {
	int n;
	scanf("%d", &n);
	int i, type, p;
	int a[n];
	int size = 0;
	for (i=0; i<n; i++) {
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &p);
			if (size == 0) {
				a[0] = p;
				size++;
				continue;
			}
			insertionSort(a, p, size);
			size++;
		} else {
			if (size < 3) {
				printf("Not enough enemies");
			} else {
				printf("%d", a[size - size / 3]);
			}
			printf("\n");
		}
	}
}