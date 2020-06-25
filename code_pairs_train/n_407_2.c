#include<stdio.h>
void main()
{
	long t;
	scanf("%ld",&t);
	while(t--)
	{
		long n;
		scanf("%ld",&n);
		int x=1,y=1;
		for(int i=1;i<=n;i++)
		{
			x=x*2;
			y=y+x;
			if(n%y==0)
			{
				printf("%ld\n",n/y);
				break;
			}
		}
	}
}
