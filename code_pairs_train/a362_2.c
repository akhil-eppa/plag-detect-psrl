#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int o=0;o<t;o++)
	{
		int n,min;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		min=arr[0];
		for(int i=0;i<n;i++)
			{
				if(arr[i]<min)
					min=arr[i];
			}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum=sum+(arr[i]-min);
		}
		printf("%d\n",sum);
	}return 0;
}
