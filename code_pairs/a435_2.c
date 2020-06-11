#include<stdio.h>

int main(){

   int i, j, count, temp, number[30];

   printf("How many numbers are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;count>i;++i)
   scanf("%d",&number[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   for(i=count-2;0<=i;--i){
      for(j=0;i>=j;++j){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;count>i;++i)
      printf(" %d",number[i]);

   return 0;
}