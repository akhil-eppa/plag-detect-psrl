#include <stdio.h>
#include<malloc.h>
#include <string.h>

long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;

	return gcd(b%a,a);
}
long long int lcm(long long int a,long long int b)
{
	return a*b/gcd(a,b);
}
int main()
{
	long long int i;
	long long j;
	long long k;
	long long n;
	long long min;
	long long *a;
	long long sum;
	long long cal;
	// printf("%d",gcd(1,1));
	scanf("%lld",&n);
	a=(long long int *)malloc(sizeof(long long int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	k=0;
	cal=gcd(a[0],a[1]);
	sum=lcm(a[0],a[1]);

	for(i=2;i<n;i++)
	{
		sum=gcd(sum,lcm(cal,a[i]));
		cal=gcd(cal,a[i]);
	}
	printf("%lld",sum);
	return 0;
}
