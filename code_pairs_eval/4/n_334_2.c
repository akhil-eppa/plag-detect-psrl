#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; ++i)
	{
		long long n;
		scanf("%lld",&n);
		long long a[n];
		long long b[n];
		for(int i=0; i<n; ++i)
		{
			b[i]=0;
		}
		for(int i=0; i<n; ++i)
		{
			scanf("%lld",&a[i]);
			b[a[i]-1]++;
		}
		long long m=0;
		for(int i=0; i<n; ++i)
		{
			m=m+b[i]/(i+1);
			if(i!=n-1)
				b[i+1]=b[i+1]+b[i]%(i+1);
		}
		printf("%lld\n",m);
	}
}
