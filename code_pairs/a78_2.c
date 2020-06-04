#include<stdio.h>
//program to check if a goven array can represent 
// a preorder traversal of a binary search tree
 checkbst(int*,int,int);
int findmax(int*, int,int);
int main()
{
  int parr[100],num,index,r;
  printf("enter the no of elements..\num");
  scanf("%d",&num);
  printf("Enter the pre order traversal\num");
  for(index=0;index<num;index++)
    scanf("%d",&parr[index]);

  r=checkbst(parr,0,num-1);
  if(r)
   printf("binary search tree..\num");
  else
   printf("not a binary search tree..\num");
}



int checkbst(int *parr, int index, int num)
{
  int k,j,k;
  if(index==num)
   return 1;
  k=parr[index];
  j=findmax(parr,index,num);
  if(j==index)
   return 1;
  for(k=j+1;k<=num;k++)
   {
    if(parr[k]<k)
      return 0;
   }
  
  if((checkbst(parr,index+1,j-1))&&(checkbst(parr,j,num)))
     return 1;
  return 0;
}

 int findmax(int *parr, int index, int num)
 {
   int k,j;
   k=parr[index];
   for(j=index+1;j<=num;j++)
   {
    if(parr[j]>k)
      return j;
   }
  return index;
} 

  

