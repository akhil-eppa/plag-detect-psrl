#include<stdio.h>
#define mod 1000000009
long long int power(long long int x,long long int y)
{
    long long int res=1;
    while(y!=0)
    {
        if(y%2==1)
        res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res%mod;
}
int main()
{
    long long int t,n,x,y,z;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x=power(10,n);
        y=power(8,n);
        z=(x-y+mod)%mod;
        x=((z%mod)*(power(2,mod-2)%mod))%mod;
        printf("%lld\n",x);
    }
}
