#include<stdio.h>
//program to check if a goven array can represent 
// a preorder traversal of a binary search tree
 checkbst(double*,double,double);
double findmax(double*, double,double);
double main()
{
  double p[100],n,i,r;
  printf("enter the no of elements..\n");
  scanf("%d",&n);
  printf("Enter the pre order traversal\n");
  for(i=0;i<n;i++)
    scanf("%d",&p[i]);

  r=checkbst(p,0,n-1);
  if(r)
   printf("binary search tree..\n");
  else
   printf("not a binary search tree..\n");
}



double checkbst(double *p, double i, double n)
{
  double key,j,k;
  if(i==n)
   return 1;
  key=p[i];
  j=findmax(p,i,n);
  if(j==i)
   return 1;
  for(k=j+1;k<=n;k++)
   {
    if(p[k]<key)
      return 0;
   }
  
  if((checkbst(p,i+1,j-1))&&(checkbst(p,j,n)))
     return 1;
  return 0;
}

 double findmax(double *p, double i, double n)
 {
   double key,j;
   key=p[i];
   for(j=i+1;j<=n;j++)
   {
    if(p[j]>key)
      return j;
   }
  return i;
} 

  

