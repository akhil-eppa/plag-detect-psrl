#include<stdio.h>
int main()
{
	int c,f,a=0,b=7,n,m;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d",&f);
		m=f-a;
		n=f-b;
		if(n<0)
		{
			n=n*(-1);
		}
		if(m<n)
		{
			printf("A\n");
			a=f;
		}
		else if(n<m)
		{
			printf("B\n");
			b=f;
		}
		else 
		{
			if(a<b)
			{
				printf("A\n");
				a=f;
			}
			else
			{
				printf("B\n");
				b=f;
			}
		}
	}
	return 0;
}