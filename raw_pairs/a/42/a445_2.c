// C program to implement recursive Binary Search 
#include <stdio.h> 

// A recursive binary search function. It returns 
// location of xi in given array arrays[l..r] is present, 
// otherwise -1 
int binarySearch(int arrays[], int l, int r, int xi) 
{ 
	if (r >= l) { 
		int middle = l + (r - l) / 2; 

		// If the element is present at the middle 
		// itself 
		if (arrays[middle] == xi) 
			return middle; 

		// If element is smaller than middle, then 
		// it can only be present in left subarray 
		if (arrays[middle] > xi) 
			return binarySearch(arrays, l, middle - 1, xi); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arrays, middle + 1, r, xi); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 

int main(void) 
{ 
	int arrays[] = { 2, 3, 4, 10, 40 }; 
	int n = sizeof(arrays) / sizeof(arrays[0]); 
	int xi = 10; 
	int result = binarySearch(arrays, 0, n - 1, xi); 
	(result == -1) ? printf("Element is not present in array") 
				: printf("Element is present at index %d", 
							result); 
	return 0; 
} 
