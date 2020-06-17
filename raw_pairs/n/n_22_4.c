#include <stdio.h>

int main()
{
	long long t;
	long long n;
	long long k;
	long long a;
	long long b;
	long long i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		a=k-1;b=2*(k-1);

		if(n-a>0 && (n-a)%2==1)
		{
			printf("YES\n");
			for(i=0;i<k-1;i++) {
				putchar('1');
				putchar(' ');
			}
			printf("%lld\n",n-a);
		}
		else if(n-b>0 && (n-b)%2==0)
		{
			printf("YES");
			putchar('\n');
			for(i=0;i<k-1;i++) printf("2 ");
			printf("%lld\n",n-b);
		}
		else printf("NO\n");
	}

	return 0;
}
