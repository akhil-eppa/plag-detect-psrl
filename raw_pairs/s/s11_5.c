#include <stdio.h>
 
#define m 1000000007
 
 int d,x,y,z, p;
 
 int modularExponentiation( long long x,long long n)
{
    long result=1;
    while(n>0)
    {
        if(n%2==1)
            result=(result*x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
 
void main()
{
    unsigned int t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long signed a[n];
    	for(j=0;j<n;j++)
    	scanf("%lld",&a[j]);
    	val=0;
    	tot=0;
    	for(j=0;j<n-1;j++)
    	{
    		inve=modularExponentiation(a[j],m-2);
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
}