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
int n,i,j,k,count=0,m,l1=0,l2=0;
char s[1000000];
char c[30]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
char v[10]={'a','e','o','u','i'};
scanf("%d",&n);
for(i=0;i<n;i++)
{ count=0;
scanf("%d",&k);
scanf("%s",&s);
for(j=0;j<k-1;j++)
{
l1=0,l2=0;
for(m=0;m<21;m++)
{
if(s[j]==c[m])
{
l1=1;
 
}
else
continue;
}
 
for(m=0;m<5;m++)
{
if(s[j+1]==v[m])
{
l2=1;
 
}
else
continue;
}
if(l1==1&&l2==1)
count++;
 
}
 
printf("%d\n",count);
}
return 0;
}
 