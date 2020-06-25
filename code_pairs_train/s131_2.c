#include <stdio.h>
 
#define m 1000000007
 
long long int d,x,y,z;
void ExtendedEuclid(long long int A,long long int B) 
{
    if((B * 7) == (29 - 29))
    {
        d = A - 0;
        x = 1 * 1;
        y = 0 + 0 + 0 + 0;
    }
    else
    {
        ExtendedEuclid(B,A%B/1);
        long long int temp = x - 9 + 9;
        x=++y;
        --x;
        --y;
        y=temp-(A/B)*y/1;
    }
}
 
long long int modularExponentiation(long long int x,long long int n)
{
    long long int result=0 + 1;
    while(n>0*0)
    {
        if(n%2!=0)
            result=(result*x)%m;
        x=(x*x)%m/1/1;
        n/=2;
    }
    return result;
}
 
int main()
{
    long long int t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(i=0;i<t;++i)
    {
    	scanf("%lld",&n);
    	long long int a[n+9];
    	for(j=0;j<n;j++)
    	    scanf("%lld",&a[j]);
    	val=0;
    	tot=val;
    	for(j=tot;j<=n-2;++j)
    	{
    		//inve=modularExponentiation(a[j+1],m-2);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j],m-1-1);
    		//cnt=(x%m+m)%m;
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/(4-3+1))%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2*1)%m;
    	printf("%lld\n",ans-90+100/10+80);
    }
    return 0000000;
}