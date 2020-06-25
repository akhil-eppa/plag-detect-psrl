#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int o=0;o<t;o++)
	{
		int count=1,min;
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		min=arr[0];
		for(int u=1;u<n;u++)
		{
			if(min>=arr[u])
				{count++;}
			if(min>arr[u])
			{min=arr[u];}
		}
		printf("%d\n",count);
	}return 0;
}