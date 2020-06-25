#include <stdio.h>
 
#define m 1000000007
 
long long int d,x,y,z;
void ExtendedEuclid(long long int A,long long int B) 
{
    if(!B)
    {
        ExtendedEuclid(B,A%B);
        long long int temp = x;
        x=y;
        y=temp-(A/B)*y;
    }
    else
    {
        d = A;
        x = 1;
        y = 0;
    }
}
 
long long int modularExponentiation(long long int x,long long int n)
{
    long long int result=1;
    while(n>0)
    {
        if(n%2!=0)
            result=(result*x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
 
int main()
{
    long long int t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long long int a[n];
    	for(j=0;j<n;j++)
    	scanf("%lld",&a[j]);
    	val=0;
    	tot=0;
    	for(j=0;j<n-1;j++)
    	{
    		//inve=modularExponentiation(a[j+1],m-2);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j],m-2);
    		//cnt=(x%m+m)%m;
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
    return 0;
}