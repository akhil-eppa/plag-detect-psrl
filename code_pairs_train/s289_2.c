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
int main()
{
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&ar[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}
	return 0;
}