#include <stdio.h>

int main()
{
	long long t,n,k,a,b,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		a=k-1;b=2*(k-1);

		if(n-a>0 && (n-a)%2==1)
		{
			printf("YES\n");
			for(i=0;i<k-1;i++) printf("1 ");
			printf("%lld\n",n-a);
		}
		else if(n-b>0 && (n-b)%2==0)
		{
			printf("YES\n");
			for(i=0;i<k-1;i++) printf("2 ");
			printf("%lld\n",n-b);
		}
		else printf("NO\n");
	}

	return 0;
}
