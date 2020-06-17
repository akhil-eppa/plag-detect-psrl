#include<stdio.h>
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
void main()
{
	long b[100010];
	long n,lcm=0,gcd1=0;
	long a[100010];
	scanf("%ld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}
	for(long long j=n-1;j>=0;j--)
		b[j]=gcd(b[j+1],a[j]);
	for(int i=0;i<n;i++)
	{
		gcd1=gcd(a[i]*b[i+1]/gcd(a[i],b[i+1]),gcd1);
	}

	printf("%ld",gcd1);
}
