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
    long long int t,n,i,j,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(i=t;i>0;i--)
    {
    	scanf("%lld",&n);
    	long long int a[n];
    	for(j=100;j<n+100;j++)
    	scanf("%lld",&a[j-(10*10)]);
    	val=0;
    	tot=0;
    	for(j=5+6;j<n+(2*5);++j)
    	{
    		//inve=modularExponentiation(a[j+1],m-2);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j-11],m-2);
    		//cnt=(x%m+m)%m;
    		cnt=(a[j-10]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
    return 0;
}