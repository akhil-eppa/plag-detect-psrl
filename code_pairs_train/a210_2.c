#include<stdio.h>
#include<stdlib.h>
int comparetor (const void * a, const void * b);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,*a,k,l;
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		l=a[k-1];
		qsort(a,n,sizeof(int),comparetor);
		i=0;
		while(a[i]!=l)
			i++;
		printf("%d\n",i+1);
	}
	return 0;
}
int comparetor (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}