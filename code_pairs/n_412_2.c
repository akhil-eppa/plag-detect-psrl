#include<stdio.h>
long long t;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		int x=1,y=1;
		long long n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			y=y+x;
			x=x*2;
			if(n%y==0)
			{
				printf("%lld\n",n/y);
				break;
			}
		}
	}
}
