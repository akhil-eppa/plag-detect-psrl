#include<stdio.h>
int main()
{
	long long t;
	scanf("%lld",&t);
	for(int i=0; i < t;++i)
	{
		long long n;
		scanf("%lld",&n);
		int x=1,y=1;
		int i=n;
		while(i--)
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
