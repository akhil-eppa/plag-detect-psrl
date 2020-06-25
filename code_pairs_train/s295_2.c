#include <stdio.h>
 
int main()
{
    int n,m,a[1000],ans=2,j,i,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {l=0;
    	ans=2;
    	scanf("%d",&m);
    	for(j=0;j<m;j++)
    	{
    		scanf("%d",&a[j]);
    	}
    	for(j=0;j<m;j++)
    	{
    	 k=prime(a[j],&l);
    	ans=ans*k;
    	}
    	ans=ans*(l+2);
    	ans=ans%1000000007;
    	printf("%d\n",ans);
    }
}
int prime(int a,int *l)
{
	int count=0,j;
	for(j=1;j<=a;j++)
	{
		if(a%j==0)
		count++;
		if(count<3)
		continue;
		else break;
	}
	if(count==2) 
	{
		(*l)++;
		return 3;
	}
	else return 2;
}