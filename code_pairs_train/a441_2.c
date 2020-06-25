#include<stdio.h>

int main(){

   printf("How many numbers are u going to enter?: ");
   int counter, temper, i, j, nmbr[30];
   scanf("%d",&counter);

   printf("Enter %d numbers: ",counter);

   for(i=0;i<counter;++i)
   scanf("%d",&nmbr[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   for(i=counter-2;i>=0;--i){
      for(j=0;j<=i;++j){
        if(nmbr[j]>nmbr[j+1]){
           temper=nmbr[j];
           nmbr[j]=nmbr[j+1];
           nmbr[j+1]=temper;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<counter;i++)
      printf(" %d",nmbr[i]);

   return 0;
}