#include<stdio.h>
int t;
int main()
{
	scanf("%d",&t);

	while(t--)
	{
		long n;
		scanf("%ld",&n);

		if(((n/2)%2)!=1)
		{
			printf("YES\n");
			continue;
		}
		else
			printf("NO\n");

		for(int i=1;i<=(n/2);i++)
		{
			printf("%ld ",2*i);
		}
		for(int i=1;i<=(n/2);i++)
		{
			if(i==n/2)
				printf("%ld ",((2*i)-1+(n/2)));
			else
				printf("%ld ",((2*i)-1));
		}



		printf("\n");

	}
}
