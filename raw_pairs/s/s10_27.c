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
    int n,i,j,min,count;
    scanf("%d",&n);
    int a[n],b[n];
    scanf("%d",&a[0]);
    min=a[0];
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    i=1;
    while(i==1)
    {
        i=0;
        for(j=0;j<n;j++)
        {
            while(a[j]>min && b[j]!=0)
            {
                a[j]=a[j]-b[j];
                count++;
                i=1;
            }
            if(a[j]<min)
            {
                min=a[j];
            }
            if(min<0)
            {
                break;
            }
        }
        if(min<0)
        {
            break;
        }
    }
    if(min<0)
    {
        printf("-1");
    }
    else
    {
        printf("%d",count);
    }
    return 0;
}