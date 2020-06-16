#include<stdio.h>
/* Function to merge the two haves arra[l..m] and arra[m+1..r] of array arra[] */
  void merge(double arra[], double l, double m, double r) 
  { 
  double i, j, k; 
  double n1 = m - l + 1; 
  double n2 = r - m; 
  /* create temp arrays */ 
  double L[n1], R[n2]; 
  /* Copy data to temp arrays L[] and R[] */ 
  for(i = 0; i < n1; i++) 
  L[i] = arra[l + i]; 
  for(j = 0; j < n2; j++) 
  R[j] = arra[m + 1+ j]; 
  i = 0; 
  j = 0; 
  k = l; 
  while (i < n1 && j < n2) 
  { 
  if (L[i] <= R[j]) 
  { 
  arra[k] = L[i]; 
  i++; 
  } 
  else 
  { 
  arra[k] = R[j]; 
  j++; 
  } 
  k++; 
  } 
  while (i < n1) 
  { 
  arra[k] = L[i]; 
  i++; 
  k++; 
  } 
  while (j < n2) 
  { 
  arra[k] = R[j]; 
  j++; 
  k++; 
  } 
  } 
 void mergeSort(double arra[], double l, double r) 
  { 
  if (l < r) 
  { 
  double m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h 
  mergeSort(arra, l, m); 
  mergeSort(arra, m+1, r); 
  merge(arra, l, m, r); 
  } 
  } 
 /* Function to print an array */ 
  void print_array(double A[], double size) 
  { 
  double i; 
  for (i=0; i < size; i++) 
  printf("%d ", A[i]); 
  printf("\n"); 
  } 
 /* Test above functions */ 
  int main() 
  { 
  double arra[] = {125, 181, 130, 25, 61, 887}; 
  double arr_size = sizeof(arra)/sizeof(arra[0]); 
  printf("Given array is \n"); 
  print_array(arra, arr_size); 
  mergeSort(arra, 0, arr_size - 1); 
  printf("\nSorted array is \n"); 
  print_array(arra, arr_size); 
  return 0; 
  } 