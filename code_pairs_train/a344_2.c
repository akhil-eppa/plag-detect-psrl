#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,count,*a,i;
		scanf("%lld",&n);
		count=n;
		a=(long long int *)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<n;i++)
		{
			if(a[i-1]<a[i])
			{
				--count;
				a[i]=a[i-1];
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}