#include<stdio.h>

int main()
{
	int x,y,k,a,b;
	long long int t,n,i,j;
	scanf("%lld",&t);
	
	for(i=0;i<t;i++)
	{
		int count=0;
		scanf("%d %d %d %lld",&x,&y,&k,&n);
		
		for(j=0;j<n;j++)
		{
			scanf("%d%d",&a,&b);
			if(b<=k&&a>=(x-y))
			count++;
		}
		if(count==0)
		printf("UnluckyChef\n");
		else printf("LuckyChef\n");
	}
}