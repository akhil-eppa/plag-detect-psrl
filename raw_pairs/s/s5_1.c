#include <stdio.h>
 
int searchLocation(int arr[], int val, int low, int high)
{
	if (low >= high) {
		if (val <= arr[low])
			return low;
			
		return low + 1;
	}
 
	int mid = (low + high) / 2;
 
	if (val == arr[mid])
		return mid + 1;
	
	else if (val > arr[mid])
		return searchLocation (arr, val, mid + 1, high);
	
	return searchLocation (arr, val, low, mid - 1);
}
 
void sortAdd(int arr[], int val, int n)
{
	int index = searchLocation (arr, val, 0, n);
 
	for (int i = n + 1; i > index; i--)
		arr[i] = arr[i - 1];
 
	arr[index] = val;
}
 
int main(){
	int num = 0, a = 0, i = 0, val = 0;
	scanf("%d", &num);
	int arr[num];
 
	while(num--) {
		scanf("%d", &a);
 
		if (a == 1) {
			scanf("%d", &val);
			
			if (i == 0)
				arr[i] = val;
			else
				sortAdd(arr, val, i - 1);
 
			i++;
		}
 
		else if (a == 2) {
			if (i < 3)
				printf("Not enough enemies\n");
 
			else 
				printf("%d\n", arr[i - (i / 3)]);
		}
	}
 
	return 0;
}