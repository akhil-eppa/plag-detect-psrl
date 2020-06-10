#include<stdio.h>
/* Function to merge the two haves arra[l..m] and arra[m+1..r] of array arra[] */
  void merge(int arra[], int l, int m, int r) 
  { 
  int i, j, kt; 
  int n2 = r - m; 
  int n1 = m - l + 1; 
  /* create temp arrays */ 
  int L[n1], R[n2]; 
  /* Copy data to temp arrays L[] and R[] */ 
  
  for(i = 0; i < n1; i++) 
  L[i] = arra[l + i]; 
  i = 0; 
  j = 0; 
  kt = l; 
  while (i < n1 && j < n2) 
  { 
  if (L[i] <= R[j]) 
  { 
  arra[kt] = L[i]; 
  i++; 
  } 
  else 
  { 
  arra[kt] = R[j]; 
  j++; 
  } 
  kt++; 
  } 
  while (i < n1) 
  { 
  arra[kt] = L[i]; 
  i++; 
  kt++; 
  } 
  while (j < n2) 
  { 
  arra[kt] = R[j]; 
  j++; 
  kt++; 
  } 
  } 
 void mergeSort(int arra[], int l, int r) 
  { 
  if (l < r) 
  { 
  int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h 
  mergeSort(arra, l, m); 
  mergeSort(arra, m+1, r); 
  merge(arra, l, m, r); 
  } 
  } 
 /* Function to print an array */ 
  void print_array(int A[], int size) 
  { 
  int i; 
  for (i=0; i < size; i++) 
  printf("%d ", A[i]); 
  printf("\n"); 
  } 
 /* Test above functions */ 
  int main() 
  { 
  int arra[] = {125, 181, 130, 25, 61, 887}; 
  int arr_size = sizeof(arra)/sizeof(arra[0]); 
  printf("Given array is \n"); 
  print_array(arra, arr_size); 
  mergeSort(arra, 0, arr_size - 1); 
  printf("\nSorted array is \n"); 
  print_array(arra, arr_size); 
  return 0; 
  } 