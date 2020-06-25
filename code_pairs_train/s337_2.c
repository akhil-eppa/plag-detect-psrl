#include <stdio.h>
#define m 1000000009
 
long long int binaryExponentiation(long long int x,long long int n)
{
    long long int result=1;
    while(n>0)
    {
        if(n%2==1)
            result=(result*x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
 
int main()
{
    long long int t,n,i,j,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	ans=(5*binaryExponentiation(10,n-1))%m;
    	ans-=(4*binaryExponentiation(8,n-1))%m;
    	if(ans<0)
    	ans+=m;
    	printf("%lld\n",ans);
    }
    return 0;
}