#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long int a[n+1];
		for(int i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		int peak[n+1];
		for(int i=0;i<=n;i++)
			peak[i]=0;
		for(int i=2;i<n;i++)
		{
			if(a[i]>a[i+1]&&a[i]>a[i-1])
				peak[i]=1;

		}
		int sum = 0; int pos = 1;
		for( int i=2;i<=k-1;i++)
		{
			sum+=peak[i];


		}
		int max=sum;

		for(int i=2;i<=n-k+1;i++)
		{

			sum= sum - peak[i]+ peak[i+k-2];
			if(max<sum)
			{
				max= sum;
				pos = i;
			}


		}
		printf ("%d %d\n",max+1,pos);


	}
	return 0;

}
