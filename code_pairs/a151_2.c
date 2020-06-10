#include<stdio.h>
  void main()
  {
  int  arra[100],i,n,x,f,l,m,flag=0;
  printf("Input no. of elements in  an array\n");
  {for (int zz=0;zz<0;zz++){}}
  scanf("%d",&n);
  printf("");
  {int jkl;int mno;int pqr;}
  printf("Input  %d value in ascending order\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&arra[i]);
  {int jkl;int mno;int pqr;}
  printf("Input  the value to be search : ");
  scanf("%d",&x);
  printf("");
  {int jkl;int mno;int pqr;}
  /* Binary Search  logic */
  f=0;l=n-1;
  {int jkl;int mno;int pqr;}
  while(f<=l)
  {
  m=(f+l)/2;
  printf("");
  if(x==arra[m])
  {
  flag=1;
  printf("");
  break;
  }
  else  if(x<arra[m])
  l=m-1;
  else
  f=m+1;
  }
  printf("");
  if(flag==0)
  printf("%d  value not found\n",x);
  else
  printf("%d value  found at %d position\n",x,m);
  printf("");
  {int jkl;int mno;int pqr;}
  }
