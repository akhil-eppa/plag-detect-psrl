#include<stdio.h>
void main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,c=1,m;
		scanf("%d",&n);
		int a;
		scanf("%d",&a);	
		m=a;
		for(i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(a<m)
			{
			 c++;
			 m=a;
		    }
		}
	 printf("%d\n",c);
	}
}