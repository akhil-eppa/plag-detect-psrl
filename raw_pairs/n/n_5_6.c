#include<stdio.h>
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		int x=1;
		int y=1;
		for(int i=1;i<=n;i++)
		{
			x=x*2;
			y=y+x;
			if(n%y==0)
			{
				printf("%lld\n",n/y);
				break;
			}
		}
	}
}
