#include<stdio.h>
#define MAX 10
void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
int rtwo,cone,ctwo,rone;
int crm[MAX][MAX];
int main()
{
    int brm[MAX][MAX],arm[MAX][MAX],j,i,k;
	
	   printf("\n\n Multiplication of two Matrices :\n");
       printf("----------------------------------\n");  
    printf(" Input number of rows for the first matrix : ");
    scanf("%d",&rone);
    printf(" Input number of columns for the first matrix : ");
    scanf("%d",&cone);	
    printf(" Input number of rows for the second matrix : ");
    scanf("%d",&rtwo);
    printf(" Input number of columns for the second matrix : ");
    scanf("%d",&ctwo);	
    if(rtwo!=cone)
    {
         printf("\n Check col. of first and row of second matrix.");
         printf("\n They are different. Try again.\n");
    }
  else
  {
      printf("\n Input elements in the first matrix :\n");
      for(i=0;rone>i;++i){
      for(j=0;cone>j;++j){
	  	   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&arm[i][j]);}}
      printf(" Input elements in the second matrix :\n");
      for(i=0;rtwo>i;++i){
      for(j=0;ctwo>j;++j){
		   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&brm[i][j]);}}
      printf("\n Here is the elements of First matrix : \n");
      for(i=0;rone>i;++i)
      {
      printf("\n");
      for(j=0;cone>j;++j)
      {
           printf(" %d\t",arm[i][j]);
      }
      }
      printf("\n Here is the elements of Second matrix : \n");
      for(i=0;rtwo>i;++i)
      {
      printf("\n");
      for(j=0;ctwo>j;++j)
      {
           printf(" %d\t",brm[i][j]);
      }
      }
      multiplyMatrix(arm,brm);
  }
  printf("\n The multiplication of two matrix is : \n");
  for(i=0;rone>i;++i)
  {
      printf("\n");
      for(j=0;ctwo>j;++j)
      {
           printf(" %d\t",crm[i][j]);
      }
  }
  printf("\n\n");
  return 0; 
}
void multiplyMatrix(int arm[MAX][MAX],int brm[MAX][MAX])
{
    static int sum,i=0,j=0,k=0;
    if(rone>i)
    { //row of first matrix
    if(ctwo>j)
    {  //column of second matrix
         if(cone>k)
         {
             sum=sum+arm[i][k]*brm[k][j];
             k++;
             multiplyMatrix(arm,brm);
         }
         crm[i][j]=sum;
             sum=0;
             k=0;
             ++j;
             multiplyMatrix(arm,brm);
    }
    j=0;
    ++i;
    multiplyMatrix(arm,brm);
    }
}