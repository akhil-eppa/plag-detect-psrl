#include<stdio.h>
int main()
{
	char a[101];
	long long int t,i,j,n,k,sum,q,min,max,b[101];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		k=k-1;
		while(k--)
		{
			max=-1;min=10;
			j=n;
			while(j)
			{
				q=j%10;
				if(min>q)
					min=q;
				if(max<q)
					max=q;
				j=j/10;
			}
			if(min==0)break;
			n=n+max*min;
		}
		printf("%lld\n",n);
	}
	return 0;
}
