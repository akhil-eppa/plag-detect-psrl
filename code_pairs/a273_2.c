
#include <stdio.h>
 
int main()
{
	long int t;
	scanf("%ld",&t);
	while(t>0)
	{
		t--;
		long int x,c=0,y,r,k,n,i=0;
		scanf("%ld%ld%ld%ld",&y,&x,&k,&n);
		r=y-x;
		long int a[n],b[n];
		while(i<n)
		{
			scanf("%ld%ld",&a[i],&b[i]);
			i++;
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>=r&&b[i]<=k)
			{
				c=1;
				break;
		   }
		  c=0;
		}
		if(c==1)
		  printf("LuckyChef\n");
		else
		  printf("UnluckyChef\n");
		 }
	return 0;
}
 
