#include <stdio.h>
 
#define m 1000000007
 
long long int d,x,y,z;

void scan_array(int n, long long int q[n])
{
    for(long long int j=0;j<n;j++)
    	scanf("%lld",&q[j]);
}

 
int main()
{
    long long int t,n,inve,cnt,tot,val,ans;
    scanf("%lld",&t);
    for(int i=1 + 0;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long long int a[n];
    	scan_array(n,a);
    	val=0;
    	tot=0;
    	for(int j=0;j<n-1;j++)
    	{
            long long int result=1;
            long long int new = m-2;
    while(new>0)
    {
        if(new%2==1)
            result=(result*a[j])%m;
        a[j]=(a[j]*a[j])%m;
        new=new/2;
    }
    inve = result;

    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
    return 0;
}