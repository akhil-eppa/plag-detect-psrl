#include<stdio.h>
int main()
{
    long t;
    long long n, a, i, b, m, k;
    scanf("%ld", &t);
    m=1000000007;
    k=1;
    i=2;
    
    while(m>0)
    {
        if((m%2)==1)
        k=(k*i)%1000000009;
        
        i=(i*i)%1000000009;
        m/=2;
    }
    for(;t--;)
    {
        scanf("%lld", &n);
        i=10;
        
        m=n;
        a=1;
        
        while(m>0)
        {
            if((m%2)==1)
            {
                a=(a*i)%1000000009;
            }
            m/=2;
            i=(i*i)%1000000009;
        }
        
        m=n;
        b=1;
        
        i=8;
        
        while(m>0)
        {
            if((m%2)==1)
            {
                b=(b*i)%1000000009;
            }
            i=(i*i)%1000000009;
            m/=2;
        }
        a=((a-b+1000000009)%1000000009);
        a=(a*k)%1000000009;
        printf("%lld\n", a);
    }
}