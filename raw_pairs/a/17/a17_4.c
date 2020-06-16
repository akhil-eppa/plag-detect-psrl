#include<stdio.h>
#define MAX 10
void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
int rones,cones,rtwos,ctwos;
int crm[MAX][MAX];
int main()
{
    int arm[MAX][MAX],brm[MAX][MAX],ip,jp,kp;
	
	   printf("\n\n Multiplication of two Matrices :\n");
       printf("----------------------------------\n");  
    printf(" Input number of rows for the first matrix : ");
    scanf("%d",&rones);
    printf(" Input number of columns for the first matrix : ");
    scanf("%d",&cones);	
    printf(" Input number of rows for the second matrix : ");
    scanf("%d",&rtwos);
    printf(" Input number of columns for the second matrix : ");
    scanf("%d",&ctwos);	
    if(cones!=rtwos)
    {
         printf("\n Check col. of first and row of second matrix.");
         printf("\n They are different. Try again.\n");
    }
  else
  {
      printf("\n Input elements in the first matrix :\n");
      for(ip=0;ip<rones;ip++){
      for(jp=0;jp<cones;jp++){
	  	   printf(" element - [%d],[%d] : ",ip,jp);
           scanf("%d",&arm[ip][jp]);}}
      printf(" Input elements in the second matrix :\n");
      for(ip=0;ip<rtwos;ip++){
      for(jp=0;jp<ctwos;jp++){
		   printf(" element - [%d],[%d] : ",ip,jp);
           scanf("%d",&brm[ip][jp]);}}
      printf("\n Here is the elements of First matrix : \n");
      for(ip=0;ip<rones;ip++)
      {
      printf("\n");
      for(jp=0;jp<cones;jp++)
      {
           printf(" %d\t",arm[ip][jp]);
      }
      }
      printf("\n Here is the elements of Second matrix : \n");
      for(ip=0;ip<rtwos;ip++)
      {
      printf("\n");
      for(jp=0;jp<ctwos;jp++)
      {
           printf(" %d\t",brm[ip][jp]);
      }
      }
      multiplyMatrix(arm,brm);
  }
  printf("\n The multiplication of two matrix is : \n");
  for(ip=0;ip<rones;ip++)
  {
      printf("\n");
      for(jp=0;jp<ctwos;jp++)
      {
           printf(" %d\t",crm[ip][jp]);
      }
  }
  printf("\n\n");
  return 0; 
}
void multiplyMatrix(int arm[MAX][MAX],int brm[MAX][MAX])
{
    static int sum,ip=0,jp=0,kp=0;
    if(ip<rones)
    { //row of first matrix
    if(jp<ctwos)
    {  //column of second matrix
         if(kp<cones)
         {
             sum=sum+arm[ip][kp]*brm[kp][jp];
             kp++;
             multiplyMatrix(arm,brm);
         }
         crm[ip][jp]=sum;
             sum=0;
             kp=0;
             jp++;
             multiplyMatrix(arm,brm);
    }
    jp=0;
    ip++;
    multiplyMatrix(arm,brm);
    }
}