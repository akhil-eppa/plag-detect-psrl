#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; ++i)
	{
		int n;
		int i;
		scanf("%d",&n);
		int a[n];
		int b[n];
		i = 0;
		while(i<n)
		{
			b[i]=0;
			++i;
		}
		for(int i=0; i<n; ++i)
		{
			scanf("%d",&a[i]);
			b[a[i]-1]++;
		}
		int m=0;
		i = 0;
		while(i<n)
		{
			m=m+b[i]/(i+1);
			if(i!=n-1)
				b[i+1]=b[i+1]+b[i]%(i+1);
			++i;
		}
		printf("%d\n",m);
	}
}