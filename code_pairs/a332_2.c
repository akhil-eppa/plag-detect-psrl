#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int n,i,a,b,min=100000000;
        scanf("%d\n",&n);
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                a=i;
                b=n/a;
                if(abs(b-a)<min)
                min=abs(b-a);
            }
        }
        printf("%d\n",min);
    }
}