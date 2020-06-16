#include <stdio.h>
 
#define m 1000000007
 
long long int d,x,y,z;
void ExtendedEuclid(long long int A,long long int B) 
{
    if(B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        ExtendedEuclid(B,A%B);
        long long int temp = x;
        x=y;
        y=temp-(A/B)*y;
    }
}
 
long long int modularExponentiation(long long int x,long long int n)
{
    long long int result=1;
    for(;n>0;n/=2)
    {
        if(n%2==1)
            result=(result*x)%m;
        x=(x*x)%m;
    }
    return result;
}
 
int main()
{
    long long int t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    while(t--)
    {
    	scanf("%lld",&n);
    	long long int a[n];
        j = n;
    	do
        {
    	    scanf("%lld",&a[n-j]);
            --j;
        }while(j>0);
    	val=0;
    	tot=0;
        j = tot;
        j = val;
    	while(j<n-1)
    	{
    		//inve=modularExponentiation(a[j+1],m-2);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j],m-2);
    		//cnt=(x%m+m)%m;
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
            ++j;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
    return 0;
}