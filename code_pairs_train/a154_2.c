#include<stdio.h>
  void main()
  {
  printf("Input no. of elements in  an array\n");
  int  arra[100],i,n,x,f,l,m,flag=0;
  scanf("%d",&n);
   f=0;l=n-1;
  printf("Input  %d value in ascending order\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&arra[i]);
  printf("Input  the value to be search : ");
  scanf("%d",&x);
  while(f<=l)
  {
  m=(f+l)/2;
  if(x==arra[m])
  {
  flag=1;
  break;
  }
  else  if(x<arra[m])
  l=m-1;
  else
  f=m+1;
  }
  if(flag==0)
  printf("%d  value not found\n",x);
  else
  printf("%d value  found at %d position\n",x,m);
  }
