#include<stdio.h>
#include<stdlib.h>
#define size 1000008
int spf[size];
void sieve()
{
	for(int i=0;i<size;i++)
		spf[i]=i;
	for(int i=4;i<size;i+=2)
		spf[i]=2;
	for(int i=3;i*i<size;i+=2)
		if(spf[i]==i)
			for(int j=i*i;j<size;j+=i)
				if(spf[j]==j)
					spf[j]=i;
}
int main()
{
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",n-spf[n]);
	}
	return 0;
}