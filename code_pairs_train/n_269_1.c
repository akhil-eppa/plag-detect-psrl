#include<stdio.h>
int main()
{
	long long int t,i,j,n,k,sum,q,min,max,b[101];
	char a[101];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		k=k-1;
		while(k--)
		{
			j=n;
			max=-1;min=10;
			while(j)
			{
				q=j%10;
				if(max<q)
					max=q;
				if(min>q)
					min=q;
				j=j/10;
			}
			if(min==0)break;
			n=n+max*min;
		}
		printf("%lld\n",n);
	}
	return 0;
}
