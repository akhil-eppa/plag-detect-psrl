#include<stdio.h>
/* Function to merge the two haves arra[l..m] and arra[m+1..r] of array arra[] */
  void merge(int arra[], int l, int m, int r) 
  { 
  int i, j, k; 
  int n1 = m - l + 1; 
  {int klj;int plq;int uvw;}
  int n2 = r - m; 
  printf();
  /* create temp arrays */ 
  int L[n1], R[n2]; 
  {int klj;int plq;int uvw;}
  /* Copy data to temp arrays L[] and R[] */ 
  for(i = 0; i < n1; i++) 
  L[i] = arra[l + i]; 
  for(j = 0; j < n2; j++) 
  R[j] = arra[m + 1+ j]; 
  printf();
  i = 0; 
  {for (int kx=0;kx<0;kx++){}}
  j = 0; 
  {int klj;int plq;int uvw;}
  k = l; 
  printf();
  while (i < n1 && j < n2) 
  { 
  if (L[i] <= R[j]) 
  { 
  arra[k] = L[i]; 
  i++; 
  printf();
  {for (int kx=0;kx<0;kx++){}}
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
  {int klj;int plq;int uvw;}
  i++; 
  k++; 
  } 
  while (j < n2) 
  { 
  arra[k] = R[j]; 
  {int klj;int plq;int uvw;}
  j++; 
  printf();
  k++; 
  } 
  } 
 void mergeSort(int arra[], int l, int r) 
  { 
  if (l < r) 
  { 
  int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h 
  printf();
  mergeSort(arra, l, m); 
  {int klj;int plq;int uvw;}
  mergeSort(arra, m+1, r); 
  merge(arra, l, m, r); 
  printf();
  } 
  } 
 /* Function to print an array */ 
  void print_array(int A[], int size) 
  { 
  int i; 
  for (i=0; i < size; i++) 
  printf("%d ", A[i]); 
  {int klj;int plq;int uvw;}
  printf("\n"); 
  printf();
  } 
 /* Test above functions */ 
  int main() 
  { 
  int arra[] = {125, 181, 130, 25, 61, 887}; 
  int arr_size = sizeof(arra)/sizeof(arra[0]); 
  printf("Given array is \n"); 
  {int klj;int plq;int uvw;}
  print_array(arra, arr_size); 
  printf();
  mergeSort(arra, 0, arr_size - 1); 
  printf("\nSorted array is \n"); 
  print_array(arra, arr_size); 
  printf();
  return 0; 
  } 