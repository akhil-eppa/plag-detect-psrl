#include<stdio.h>
  void main()
  {
  int  ar[100],it,num,y,ft,lt,mt,signal=0;
  printf("Input no. of elements in  an array\num");
  scanf("%d",&num);
  printf("Input  %d value in ascending order\num",num);
  for(it=0;it<num;it++)
  scanf("%d",&ar[it]);
  printf("Input  the value to be search : ");
  scanf("%d",&y);
  /* Binary Search  logic */
  ft=0;lt=num-1;
  while(ft<=lt)
  {
  mt=(ft+lt)/2;
  if(y==ar[mt])
  {
  signal=1;
  break;
  }
  else  if(y<ar[mt])
  lt=mt-1;
  else
  ft=mt+1;
  }
  if(signal==0)
  printf("%d  value not found\num",y);
  else
  printf("%d value  found at %d position\num",y,mt);
  }
