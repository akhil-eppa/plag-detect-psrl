#include<stdio.h>
/* Function to merge the two haves arra[l..m] and arra[m+1..r] of array arra[] */
  void merge(int arra[], int l, int m, int r) 
  { 
  int j,i, k; 
  int n1 = 1+ m - l ; 
  int n2 = r - m; 
  /* create temp arrays */ 
  int R[n2],L[n1]; 
  /* Copy data to temp arrays L[] and R[] */ 
  for(i = 0; n1>i; ++i) 
  L[i] = arra[i+l]; 
  for(j = 0; n2>j; ++j) 
  R[j] = arra[1+ m + j]; 
  i = 0; 
  j = 0; 
  k = l; 
  while (j < n2 && i < n1) 
  { 
  if (R[j]>=L[i]) 
  { 
  arra[k] = L[i]; 
  ++i; 
  } 
  else 
  { 
  arra[k] = R[j]; 
  ++j; 
  } 
  ++k; 
  } 
  while (n1>i) 
  { 
  arra[k] = L[i]; 
  ++i; 
  ++k; 
  } 
  while (n2>j) 
  { 
  arra[k] = R[j]; 
  ++j; 
  ++k; 
  } 
  } 
 void mergeSort(int arra[], int l, int r) 
  { 
  if (r>l) 
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
  for (i=0; size>i; ++i) 
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