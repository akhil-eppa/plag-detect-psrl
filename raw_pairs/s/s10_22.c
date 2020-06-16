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
{ int i ,t,j,n;
scanf("%d",&t);
while(t--)
{ scanf("%d",&n);
for(i =1;i<=n;i++)
{ for(j=1;j <=2*n;j++)
{ if((j>=i+1) && (j <=2*n-i ))
printf("#");
else
{ printf("*");
}
 
}
printf("\n");
}
}
return 0;
}
