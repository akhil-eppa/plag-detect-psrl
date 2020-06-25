#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		long n;
		scanf("%ld",&n);

		if(((n/2)%2)==1)
		{ printf("NO\n");
			continue;
		}
		else
			printf("YES\n");

		for(int i=1;i<=(n/2);i++)
		{
			printf("%ld ",2*i);
		}
		for(int i=1;i<=(n/2);i++)
		{
			if(i!=n/2)
				printf("%ld ",((2*i)-1));
			else
				printf("%ld ",((2*i)-1+(n/2)));
		}



		printf("\n");

	}
}
