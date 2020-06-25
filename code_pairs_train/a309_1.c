#include<stdio.h>
#include<stdlib.h>
int comparetor (const void * a, const void * b);
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	int n,k,i;
	long long int sum1=0,sum2=0,sum,*c;
	scanf("%d %d",&n,&k);
	c=(long long int *)malloc(n*sizeof(long long int));
	for(i=0;i<n;i++)
		scanf("%lld",&c[i]);
	qsort(c,n,sizeof(long long int),comparetor);
	if(n-k<k)
	k=n-k;
	for(i=0;i<k;i++)
		sum1=sum1+c[i];
	for(i=k;i<n;i++)
		sum2=sum2+c[i];
	sum=abs(sum2-sum1);
	printf("%lld\n",sum);
}
return 0;
}
int comparetor (const void * a, const void * b)
	{
		return ( *(long long int*)a - *(long long int*)b );
	}