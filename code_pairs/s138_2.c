#include <stdio.h>
 
long long m =  1000000007;
#define Z 0
#define TWO 2
#define lli long long int
 
lli d,x,y,z;
void ExtendedEuclid(lli A,lli B) 
{
    if(B == Z)
    {
        d = A;
        x = 1;
        y = Z;
    }
    else
    {
        ExtendedEuclid(B,A%B);
        lli temp = x;
        x=y;
        y=temp-(A/B)*y;
    }
}
 
lli modularExponentiation(lli x,lli n)
{
    lli result=1;
    while(n>0)
    {
        if(n%TWO==1)
            result=(result*x)%m;
        x=(x*x)%m;
        n=n/TWO;
    }
    return result;
}
 
int main()
{
    lli t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	lli a[n];
    	for(j=Z;j<n;j++)
    	scanf("%lld",&a[j]);
    	val=Z;
    	tot=Z;
    	for(j=Z;j<n-1;j++)
    	{
    		//inve=modularExponentiation(a[j+1],m-TWO);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j],m-TWO);
    		//cnt=(x%m+m)%m;
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/TWO)%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/TWO)%m;
    	printf("%lld\n",ans);
    }
    return Z;
}