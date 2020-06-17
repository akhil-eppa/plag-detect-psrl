#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long int a[n+1];
		for(int i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		int peak[n+1];
		int i=0;
		for(;i<=n;i++)
			peak[i]=0;
		i=2;
		while(i<n)
		{
			if(a[i]>a[i+1]&&a[i]>a[i-1])
				peak[i]=1;
			++i;

		}
		int sum = 0; int pos = 1;
		for( int i=2;i<=k-1;i++)
		{
			sum+=peak[i];


		}
		int max=sum;

		i=2;
		while(i<n)
		{

			sum= sum - peak[i]+ peak[i+k-2];
			if(max<sum)
			{
				max= sum;
				pos = i;
			}
			++i;


		}
		printf ("%d %d\n",max+1,pos);


	}
	return 0;

}
