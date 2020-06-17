#include<stdio.h>
int main()
{
	long long int t;
	long long int i;
	long long int j;
	long long int n;
	long long int k;
	long long int sum;
	long long int q;
	long long int min;
	long long int max;
	long long int b[101];
	char a[101];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		k=k-1;
		while(k--)
		{
			j=n;
			max=-1;
			min=10;
			while(j)
			{
				q=j%10;
				if(max<q)
					max=q;
				if(min>q)
					min=q;
				j=j/10;
			}
			if(min!=0)
				n=n+max*min;
			else
				break;
		}
		printf("%lld\n",n);
	}
	return 0;
}
