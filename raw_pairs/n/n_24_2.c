#include<stdio.h>
long long gcd(long long a,long long b);
int main()
{
	long long b[100010];
	long long n,lcm=0,gcd1=0;
	long long a[100010];
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(long long j=n-1;j>=0;j--)
		b[j]=gcd(b[j+1],a[j]);
	for(int i=0;i<n;i++)
	{
		gcd1=gcd(a[i]*b[i+1]/gcd(a[i],b[i+1]),gcd1);
	}

	printf("%lld",gcd1);
	return 0;
}
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
