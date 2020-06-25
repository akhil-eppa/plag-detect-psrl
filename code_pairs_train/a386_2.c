#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,r,i=1;
        long int prod=1;
        scanf("%d %d",&n,&r);
        while(i<r)
        {
            prod=prod*(n-r+i);
            prod=prod/i;
            i++;
        }
        printf("%ld\n",prod);
        
    }
    return 0;
}
