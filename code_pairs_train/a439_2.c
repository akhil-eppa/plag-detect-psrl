#include<stdio.h>

int main(){

   printf("How many numbers are u going to enter?: ");
   int i,j,count, temp, number[30];
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   for(i=count-2;i>=0;--i){
      for(j=0;j<=i;++j){
        if(number[j+1]<number[j]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<count;++i)
      printf(" %d",number[i]);

   return 0;
}