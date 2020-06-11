#include<stdio.h>
#include<stdlib.h>
long long int nCr(long long int a,long long int b)
{
    long long int ans=1;
    if(b>a/2)
    b=(a-b);
    for(int i=1;i<=b;i++)
    {
        ans*=(a+1-i);
        ans/=i;
    }
    return ans;
}
int main()
{
    int t;long long int n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        printf("%lld\n",nCr(n-1,k-1));
    }
}
