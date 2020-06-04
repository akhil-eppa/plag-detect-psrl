#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int o=0;o<t;o++)
	{
		int n;
		scanf("%d",&n);
		int min=n;
		for(int i=1;i*i<=n;i++)
		{ 
			if((n%i==0)&&((n/i)-i<=min)&&((n/i)-i>=0))
			{
				min=(n/i)-i;
			}
		}
		printf("%d\n",min);
	}
}