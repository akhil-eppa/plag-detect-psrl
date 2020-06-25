#include<stdio.h>
#include<math.h>
int divisor(int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c,k,r,i,j,y,d,l;
		scanf("%d",&n);
		int a[1000];long int p=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		y=1;
		while(y<=n)
		{
			for(i=y;i<=n;i++)
			{
				c=0;
				for(j=y;j<=i;j++)
				{
					c=c+divisor(a[j]);
				}
				p=(p*(c+2))%1000000007;
				for(j=i;j>y;j--)
				{
					d=n-i;l=i+1;
					while(d>0)
					{
						c=0;
						for(k=y;k<=i;k++)
						{
							if(k==j)
							{
								c=c+divisor(a[l]);
							}
							else
							{
								c=c+divisor(a[k]);
							}
						}
						p=(p*(c+2))%1000000007;
						l++;d--;
					}
				}
			}
			y++;
		}
		p=(p*2)%1000000007;
		printf("%ld\n",p);
	}
}
int divisor(int a)
{
	int j,s,d;
	d=0;s=sqrt(a);
	for(j=1;j<=s;j++)
	{
		if(a%j==0)
		{
			d=d+2;
		}
	}
	if(a==s*s)
	{
		d=d-1;
	}
	if(d>2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}