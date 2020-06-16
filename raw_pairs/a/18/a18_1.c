#include<stdio.h>
  void main()
  {
  int  arra[100],f,l,m,i,n,x,flag=0;
  printf("Input no. of elements in  an array\n");
  scanf("%d",&n);
  printf("Input  %d value in ascending order\n",n);
  for(i=0;n>i;++i)
  scanf("%d",&arra[i]);
  printf("Input  the value to be search : ");
  scanf("%d",&x);
  /* Binary Search  logic */
  f=0;l=n-1;
  while(l>=f)
  {
  m=(l+f)/2;
  if(arra[m]==x)
  {
  flag=1;
  break;
  }
  else  if(arra[m]>x)
  l=m-1;
  else
  f=1+m;
  }
  if(flag==0)
  printf("%d  value not found\n",x);
  else
  printf("%d value  found at %d position\n",x,m);
  }
