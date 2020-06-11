// C program to implement recursive Binary Search 
#include <stdio.h> 

// A recursive binary search function. It returns 
// location of xindex in given array array[l..r] is present, 
// otherwise -1 
int binarySearch(int array[], int l, int r, int xindex); 
int main(void) 
{ 
	int array[] = { 2, 3, 4, 10, 40 }; 
	int n = sizeof(array) / sizeof(array[0]); 
	int xindex = 10; 
	int result = binarySearch(array, 0, n - 1, xindex); 
	(result == -1) ? printf("Element is not present in array") 
				: printf("Element is present at index %d", 
							result); 
	return 0; 
}
int binarySearch(int array[], int l, int r, int xindex) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		// If the element is present at the middle 
		// itself 
		if (array[mid] == xindex) 
			return mid; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (array[mid] > xindex) 
			return binarySearch(array, l, mid - 1, xindex); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(array, mid + 1, r, xindex); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 
 
