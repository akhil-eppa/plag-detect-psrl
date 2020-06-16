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
void main()
{
    char a[1000];
    int d,b,c,i,flag = 1,k,l;
    scanf("%s%d",a,&k);
     l = k%10;
    //if(k!=26)
    k = k%26;
        for(i=0;a[i] != '\0';i++)
        {
            if((a[i]>=65)&&(a[i]<=(90-k)))
                a[i] = a[i] + k;
            else if((a[i]>=97)&&(a[i]<=(122-k)))
                a[i] = a[i] + k;
            else if((a[i]>=48)&&(a[i]<=(57-l)))
                a[i] = a[i] + l;
            else if((a[i]>(90-k))&&(a[i]<=90))
            {
                d = 90 - a[i];
                b = k - d;
                a[i] = 64 + b;
            }
            else if((a[i]>(122-k))&&(a[i]<=122))
            {
                d = 122 - a[i];
                b = k -  d;
                a[i] = 96 + b;
            }
            else if((a[i]>(57-l))&&(a[i]<=57))
            {
                d = 57 - a[i];
                b = l - d;
                a[i] = 47 + b;
            }
        }
        printf("%s",a);
}