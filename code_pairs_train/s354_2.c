#include<stdio.h>
long long fun(long long);
long long sum=0, c[1001], cou, ans;
int main()
{
    long n, i, j, f;
    scanf("%ld", &n);
    long k[1001];
    int a, temp;
    
    for(i=0; i<=1000; i++)
    {
        c[i]=0;
    }
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        c[a]++;
    }
    for(i=1; i<=1000; i++)
    {
        k[i]=c[i];
        if(c[i]!=0)
        {
        c[i]=fun(c[i]);
        sum=(sum+(c[i]-k[i]-1)*i)%1000000007;
        }
        
    }
    for(i=1; i<=1000; i++)
    {
        if(c[i]!=0)
        {
            cou=0;
            for(j=i+1; j<=1000; j++)
            {
                if(c[j]!=0)
                {
               ans=fun(cou)%1000000007;
               ans=(ans*(c[i]-1))%1000000007;
               ans=(ans*(c[j]-1))%1000000007;
               ans=(ans*(i|j))%1000000007;
               sum=(sum+ans)%1000000007;
               cou=(cou+k[j])%1000000007;
            
                    
                }
            }
        }
    }
    printf("%lld", sum);
}
 
long long fun(long long c)
{
    if(c!=0)
    {
        long long x=2, r=1;
        while(c>0)
        {
            if(c&1)
            {
                r=(r*x)%1000000007;
            }
            x=(x*x)%1000000007;
            c/=2;
        }
        return r;
    }
    else
    {
        return 1;
    }
}