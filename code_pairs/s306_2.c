#include<stdio.h>
long long sum[1000001];
long long modexp(long long a)
{
	long long b=1000000005;
	long long ans=1;
	while(b>0)
	{
		if((b%2)==1)
		{
			ans=(ans*a)%1000000007;
		}
		b/=2;
		a=(a*a)%1000000007;
	}
	return ans;
}
int main()
{
	long long t, n, q, i, j, ans;
	sum[0]=0;
	sum[1]=1;
	long long k;
	k=1;
	i=2; j=1000000005;
 
	while(j>0)
	{
		if((j%2)==1)
		{
			k=(k*i)%1000000007;
		}
		i=(i*i)%1000000007;
		j/=2;
	}
 
	for(i=2; i<=1000000; i++)
	{
		sum[i]=(sum[i-1]+i)%1000000007;
	}
	scanf("%lld", &t);
 
	for(;t--;)
	{
		ans=0;
		scanf("%lld", &n);
		long long a[n];
		for(i=0; i<n; i++)
		scanf("%lld", &a[i]);
 
		for(i=1; i<n; i++)
		{
			j=a[i]*modexp(a[i-1]);
			j=j%1000000007;
			ans=(ans+sum[j])%1000000007;
		}
		ans=(ans*(ans+1))%1000000007;
		ans=ans*k;
		ans=ans%1000000007;
		printf("%lld\n", ans);
	}
}