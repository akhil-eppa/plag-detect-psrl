#include <stdio.h>

void main()
{
	long t,n,k,a,b,i;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&n,&k);
		a=k-1;b=2*(k-1);

		if(n-a>0 && (n-a)%2==1)
		{
			printf("YES\n");
			for(i=0;i<k-1;i++) printf("1 ");
			printf("%ld\n",n-a);
		}
		else if(n-b>0 && (n-b)%2==0)
		{
			printf("YES\n");
			for(i=0;i<k-1;i++) printf("2 ");
			printf("%ld\n",n-b);
		}
		else printf("NO\n");
	}
}
