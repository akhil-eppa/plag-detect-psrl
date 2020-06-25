#include<stdio.h>

int main(){

   int counter, temper, i, j, number[30];

   printf("How many numbers are u going to enter?: ");
   scanf("%d",&counter);

   printf("Enter %d numbers: ",counter);

   for(i=0;i<counter;i++)
   scanf("%d",&number[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   i=counter-1;
   while (i>=0){
       j=0;
      while (j<=i){
        if(number[j]>number[j+1]){
           temper=number[j];
           number[j]=number[j+1];
           number[j+1]=temper;
        }
        j++;
      }
      i--;
   }

   printf("Sorted elements: ");
   for(i=0;i<counter;i++)
      printf(" %d",number[i]);

   return 0;
}