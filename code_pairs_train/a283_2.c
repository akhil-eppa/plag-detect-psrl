#include<stdio.h>
//program to check if a goven array can represent 
// a preorder traversal of a binary search tree
 checkbst(int*,int,int);
int findmax(int*, int,int);
int main()
{
  int n,i,r,p[100];
  printf("enter the no of elements..\n");
  scanf("%d",&n);
  printf("Enter the pre order traversal\n");
  for(i=0;n>i;++i)
    scanf("%d",&p[i]);

  r=checkbst(p,0,n-1);
  if(r)
   printf("binary search tree..\n");
  else
   printf("not a binary search tree..\n");
}



int checkbst(int *p, int i, int n)
{
  int k,j,key;
  if(n==i)
   return 1;
  key=p[i];
  j=findmax(p,i,n);
  if(i==j)
   return 1;
  for(k=j+1;n>=k;++k)
   {
    if(key>p[k])
      return 0;
   }
  
  if((checkbst(p,i+1,j-1))&&(checkbst(p,j,n)))
     return 1;
  return 0;
}

 int findmax(int *p, int i, int n)
 {
   int j,key;
   key=p[i];
   for(j=i+1;n>=j;++j)
   {
    if(key<p[j])
      return j;
   }
  return i;
} 

  

