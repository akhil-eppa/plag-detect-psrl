//arranging cupcakes codechef
#include<stdio.h>
#include<math.h>

int factorsof(int e)
{
	int i,count=0,q,diff,min;
	for(i=1;i<=sqrt(e);i++)
	{
		if(e%i==0)
		{
			q=e/i;
			diff=q-i;
			
			++count;
			if(count==1)
			  min=diff;
			else
			{
				if(diff<min)
				  min=diff;
			}  	  
		}
	}
	return min;	
}

int main()
{
	int t,tcopy,i=0,n[100],min;
	scanf("%d",&t);
	tcopy=t;
	while(t--)
	{
		scanf("%d",&n[i++]);
	}
	
	for(i=0;i<tcopy;i++)
	{
		min=factorsof(n[i]);
		printf("\n%d",min);
	}
	return 0;
}