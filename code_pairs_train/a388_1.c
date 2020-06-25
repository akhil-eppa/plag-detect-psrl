#include<stdio.h>
long int fact(long int n,int k)
{
	long int i,f=1;
	if(k>n-k)
	{
		k=n-k;
	}
	for(i=1;i<=k;i++)
	{
		f=f*n;
		f=f/i;
		n--;
	}
	return f;
}
int main(void)
{
	long int n,k,l,x;
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&n);
		scanf("%ld",&k);
		if(n==k)
		{
			printf("1\n");
		}
		else
		{
			x=fact(n-1,k-1);
			printf("%ld\n",x);
		}
	}
		
	
		
		
}
