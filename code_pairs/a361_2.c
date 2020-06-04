#include<stdio.h>
int main()
{
    int testcase;
    scanf("%d",&testcase);
    while(testcase--!=0)
    {
        int n,min=10000,sum=0,t,i;
        scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t<min)
        min=t;
        sum=sum+t;
    }
    printf("%d",sum-n*min);
    printf("\n");
    }
    return 0;
}
