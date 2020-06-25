#include<stdio.h>
#define MAX 10
void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
int rone,cone,rtwo,ctwo;
int crm[MAX][MAX];
int main()
{
    int arm[MAX][MAX],brm[MAX][MAX],i,j,k;
	
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
    if(cone!=rtwo)
    {
         printf("\n Check col. of first and row of second matrix.");
         printf("\n They are different. Try again.\n");
    }
  else
  {
      printf("\n Input elements in the first matrix :\n");
      i=0;
      while(i<rone){
      for(j=0;j<cone;j++){
	  	   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&arm[i][j]);}
           i++;}
      printf(" Input elements in the second matrix :\n");
      i++;
      while(i<rtwo){
      for(j=0;j<ctwo;j++){
		   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&brm[i][j]);}
           i++;}
      printf("\n Here is the elements of First matrix : \n");
      i=0;
      while(i<rone)
      {
      printf("\n");
      j=0;
      while(j<cone)
      {
           printf(" %d\t",arm[i][j]);
           j++;
      }
      i++;
      }
      printf("\n Here is the elements of Second matrix : \n");
      i=0;
      while(i<rtwo)
      {
      printf("\n");
      j=0;
      while(j<ctwo)
      {
           printf(" %d\t",brm[i][j]);
           j++;
      }
      i++;
      }
      multiplyMatrix(arm,brm);
  }
  printf("\n The multiplication of two matrix is : \n");
  i=0;
  while(i<rone)
  {
      printf("\n");
      j=0;
      while(j<ctwo)
      {
           printf(" %d\t",crm[i][j]);
           j++;
      }
      i++;
  }
  printf("\n\n");
  return 0; 
}
void multiplyMatrix(int arm[MAX][MAX],int brm[MAX][MAX])
{
    static int sum,i=0,j=0,k=0;
    if(i<rone)
    { //row of first matrix
    if(j<ctwo)
    {  //column of second matrix
         if(k<cone)
         {
             sum=sum+arm[i][k]*brm[k][j];
             k++;
             multiplyMatrix(arm,brm);
         }
         crm[i][j]=sum;
             sum=0;
             k=0;
             j++;
             multiplyMatrix(arm,brm);
    }
    j=0;
    i++;
    multiplyMatrix(arm,brm);
    }
}