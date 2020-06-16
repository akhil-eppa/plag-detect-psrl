#include<stdio.h>
int main()
{
    long n, i, j;
    scanf("%ld", &n);
    long long s=0, a, b;
    long c[n+1];
    for(i=0; i<=n; i++)
    c[i]=0;
    
    for(i=2; i<=n; i++)
    {
        scanf("%ld", &b);
        c[b]++;
    }
    for(i=1; i<=n; i++)
    {
        scanf("%ld", &a);
        s+=a;
    }
    
    for(i=1; i<=n; i++)
    {
        if(c[i]>1)
        {
            printf("%ld", s);
            return 0;
        }
        
    }
    printf("0");
    
}