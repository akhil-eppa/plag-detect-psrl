#include <stdio.h>
 
int main(){
int N,count,brickOfPatlu,brickOfMotu;
int A[100000],sumOfPatluMotu;
scanf("%d", &N);
count = 1;
brickOfPatlu = 0;
brickOfMotu = 0;
do{
brickOfPatlu = brickOfPatlu + count;
brickOfMotu = brickOfMotu + 2*count;
sumOfPatluMotu = brickOfPatlu + brickOfMotu;
A[count-1] = sumOfPatluMotu;
count++;
}while(sumOfPatluMotu<=N);
int brickOfPatluLastRound = A[count-3] + (count-1);
if(brickOfPatluLastRound>=N){
printf("Patlu");
} else printf("Motu");
}