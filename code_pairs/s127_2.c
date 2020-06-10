#include <stdio.h>
 
#define m 1000000007
 
long long int d;
void ExtendedEuclid(long long int A,long long int B) ;



long long int z;
long long int modularExponentiation(long long int x,long long int n);
  long long int y;
  long long int x;
int main()
{
    long long int val;
    long long int n;
    long long int i;
    long long int j;
    long long int inve;
    long long int cnt;
    long long int t;
    long long int tot;
    
    
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        tot=0, val = 0;
    	scanf("%lld",&n);
    	long long int a[n];
    	for(j=0;j<n;j++)
        {
    	    scanf("%lld",&a[j]);
        }
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
    	printf("%lld\n",((tot*(tot+1))/2)%m);
    }
    return 0;
}

void ExtendedEuclid(long long int A,long long int B) 
{
    if(B == 0)
    {
        y = 0;
        x = 1;
        d = A;
        
        
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