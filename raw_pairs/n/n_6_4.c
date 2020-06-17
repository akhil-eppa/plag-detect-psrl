#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);

	for(int i=0;i<t;++i)
	{
		long n;
		scanf("%ld",&n);

		printf("%s\n",((n/2)%2)==1?"NO":"YES");
		if(((n/2)%2)==1)
		{
			continue;
		}

		for(int i=1;i<=(n/2);i++)
		{
			printf("%d ",2*i);
		}
		for(int i=1;i<=(n/2);i++)
		{
			printf("%ld ",(i!=n/2)?(2*i-1):(2*i-1+n/2));
		}



		printf("\n");

	}
}
