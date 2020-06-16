/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include<stdio.h>
void main(){
long long int N,min=-1,sum=0;
scanf("%lld",&N);
long long int a[N];
for(int i=0;i<N;i++){
scanf("%lld",&a[i]);
sum+=a[i];
}
for(long long int i=0;i<N;i++){
if((sum-a[i])%7==0){
if( (min==-1) || (a[min]>a[i]) )
min=i;
}
}
printf("%lld",min);
}