#include<stdio.h>
//check if tree is bst 
// we use preorder traversal
//checkbst is the function that checks
 checkbst(int*,int,int);
int findmax(int*, int,int);//finds max element in that tree
//main function that is used to call all the other functions
//it calls all the other functions
int main()
{
  int p[100],n,i,r;
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
//this function checks if the given tree is a bst
//finds max in respective trees
//compares that value with the root
int checkbst(int *p, int i, int n)
{
  int key,j,k;
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
//finding the max element in a subtree
//this function finds the max element in a given subtree
 int findmax(int *p, int i, int n)
 {
   int key,j;
   key=p[i];
   for(j=i+1;j<=n;j++)
   {
    if(p[j]>key)
      return j;
   }
  return i;
} 

  

