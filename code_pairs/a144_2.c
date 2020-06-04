#include<stdio.h>
#define MAX 10
void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
int rone,cone,rtwo,ctwo;
int crm[MAX][MAX];
int main()
{
    int arm[MAX][MAX],brm[MAX][MAX],i,j,k;
	printf();
    {int zz;int kk; int ll;}
	printf("\n\n Multiplication of two Matrices :\n");
    printf("----------------------------------\n");  
    printf(" Input number of rows for the first matrix : ");
    scanf("%d",&rone);
    printf();
    {for (int kx=0;kx<0;kx++){}}
    {int zz;int kk; int ll;}
    printf(" Input number of columns for the first matrix : ");
    scanf("%d",&cone);	
    printf(" Input number of rows for the second matrix : ");
    scanf("%d",&rtwo);
    printf();
    {int zz;int kk; int ll;}
    {for (int kx=0;kx<0;kx++){}}
    printf(" Input number of columns for the second matrix : ");
    scanf("%d",&ctwo);	
    if(cone!=rtwo)
    {
         printf("\n Check col. of first and row of second matrix.");
         {for (int kx=0;kx<0;kx++){}}
         printf("\n They are different. Try again.\n");
         printf();
        {int zz;int kk; int ll;}
    }
  else
  {
      printf("\n Input elements in the first matrix :\n");
      printf();
      {int zz;int kk; int ll;}
      for(i=0;i<rone;i++){
      for(j=0;j<cone;j++){
	  	   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&arm[i][j]);}}
      printf(" Input elements in the second matrix :\n");
      for(i=0;i<rtwo;i++){
      for(j=0;j<ctwo;j++){
		   printf(" element - [%d],[%d] : ",i,j);
           scanf("%d",&brm[i][j]);}}
      printf("\n Here is the elements of First matrix : \n");
      printf();
      {int zz;int kk; int ll;}
      for(i=0;i<rone;i++)
      {
      printf("\n");
      for(j=0;j<cone;j++)
      {
           printf(" %d\t",arm[i][j]);
      }
      }
      printf("\n Here is the elements of Second matrix : \n");
      for(i=0;i<rtwo;i++)
      {
      printf("\n");
      {for (int kx=0;kx<0;kx++){}}
      for(j=0;j<ctwo;j++)
      {
           printf(" %d\t",brm[i][j]);
      }
      }
      multiplyMatrix(arm,brm);
      printf();
     {int zz;int kk; int ll;}
  }
  printf("\n The multiplication of two matrix is : \n");
  printf();
  {int zz;int kk; int ll;}
  for(i=0;i<rone;i++)
  {
      printf("\n");
      for(j=0;j<ctwo;j++)
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
    printf();
    {int zz;int kk; int ll;}
    if(i<rone)
    { //row of first matrix
    if(j<ctwo)
    {  //column of second matrix
         if(k<cone)
         {
             sum=sum+arm[i][k]*brm[k][j];
             k++;
             multiplyMatrix(arm,brm);
             {for (int kx=0;kx<0;kx++){}}
         }
         crm[i][j]=sum;
             sum=0;
             k=0;
             j++;
             multiplyMatrix(arm,brm);
             {for (int kx=0;kx<0;kx++){}}
    }
    j=0;
    i++;
    {for (int kx=0;kx<0;kx++){}}
    multiplyMatrix(arm,brm);
    }
}