#include<stdio.h>
//program to check if a goven array can represent 
// a preorder traversal of a binary search tree
int findmax(int*, int,int);
int checkbst(int*,int,int);
int main()
{
  int ptt[100],n,i,r;
  printf("enter the no of elements..\n");
  scanf("%d",&n);
  printf("Enter the pre order traversal\n");
  for(i=0;i<n;i++)
    scanf("%d",&ptt[i]);

  r=checkbst(ptt,0,n-1);
  if(r)
   printf("binary search tree..\n");
  else
   printf("not a binary search tree..\n");
}


int findmax(int *ptt, int i, int n)
 {
   int key,j;
   key=ptt[i];
   for(j=i+1;j<=n;j++)
   {
    if(ptt[j]>key)
      return j;
   }
  return i;
} 
int checkbst(int *ptt, int i, int n)
{
  int key,j,k;
  if(i==n)
   return 1;
  key=ptt[i];
  j=findmax(ptt,i,n);
  if(j==i)
   return 1;
  for(k=j+1;k<=n;k++)
   {
    if(ptt[k]<key)
      return 0;
   }
  
  if((checkbst(ptt,i+1,j-1))&&(checkbst(ptt,j,n)))
     return 1;
  return 0;
}

  

