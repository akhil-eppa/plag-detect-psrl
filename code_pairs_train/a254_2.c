#include<stdlib.h>
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int g,n,z,h,t;
		int p,q,i;
		scanf("%lld",&g);
		for(z=0;z<g;z++)
		{	
			scanf("%d %lld %d",&i,&n,&q);
			if(n%2==0)
				printf("%lld\n",n/2);
			else
			{
				if(i==1)
				{
					h=n/2;
					t=((n/2)+1);
				}
				else
				{
					t=n/2;
					h=((n/2)+1);
				}
				if(q==1)
					printf("%lld\n",h);
				else
					printf("%lld\n",t);
			}	
		}
	}
	return 0;
}