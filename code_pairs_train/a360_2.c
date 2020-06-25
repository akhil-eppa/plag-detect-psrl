#include <stdio.h>

int main(void) 
{   int t,sum,w[100],n,i,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&w[i]);
		}
		min=w[0];
		for(i=1;i<n;i++)
		{
			if(min > w[i])	
				min = w[i];
		}
		sum=0;
		for(i=0;i<n;i++)
			sum += w[i] - min;
			printf("%d\n",sum);
	}
	// your code goes here
	return 0;
}

