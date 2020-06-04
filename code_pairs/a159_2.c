#include<stdio.h>
/* Function to merge the two haves ar[l..mx] and ar[mx+1..r] of array ar[] */
  void merge(int ar[], int l, int mx, int r) 
  { 
  int ix, jx, kx; 
  int num1 = mx - l + 1; 
  int num2 = r - mx; 
  /* create temp arrays */ 
  int L[num1], R[num2]; 
  /* Copy data to temp arrays L[] and R[] */ 
  for(ix = 0; ix < num1; ix++) 
  L[ix] = ar[l + ix]; 
  for(jx = 0; jx < num2; jx++) 
  R[jx] = ar[mx + 1+ jx]; 
  ix = 0; 
  jx = 0; 
  kx = l; 
  while (ix < num1 && jx < num2) 
  { 
  if (L[ix] <= R[jx]) 
  { 
  ar[kx] = L[ix]; 
  ix++; 
  } 
  else 
  { 
  ar[kx] = R[jx]; 
  jx++; 
  } 
  kx++; 
  } 
  while (ix < num1) 
  { 
  ar[kx] = L[ix]; 
  ix++; 
  kx++; 
  } 
  while (jx < num2) 
  { 
  ar[kx] = R[jx]; 
  jx++; 
  kx++; 
  } 
  } 
 void mergeSort(int ar[], int l, int r) 
  { 
  if (l < r) 
  { 
  int mx = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h 
  mergeSort(ar, l, mx); 
  mergeSort(ar, mx+1, r); 
  merge(ar, l, mx, r); 
  } 
  } 
 /* Function to print an array */ 
  void print_array(int A[], int size) 
  { 
  int ix; 
  for (ix=0; ix < size; ix++) 
  printf("%d ", A[ix]); 
  printf("\n"); 
  } 
 /* Test above functions */ 
  int main() 
  { 
  int ar[] = {125, 181, 130, 25, 61, 887}; 
  int size = sizeof(ar)/sizeof(ar[0]); 
  printf("Given array is \n"); 
  print_array(ar, size); 
  mergeSort(ar, 0, size - 1); 
  printf("\nSorted array is \n"); 
  print_array(ar, size); 
  return 0; 
  } 