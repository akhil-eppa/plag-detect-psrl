#include <stdio.h>
 
void soe(int a[])
{
	int i,j;
	for(i=2;i<=500000;i++)
	{
		if(a[i]==1)
		{
			for(j=2*i;j<=1000000;j+=i)
		    a[j]=0;
		}
	}
}
 
int main()
{
    int n,i,j,x,index;
    scanf("%d",&n);
    int a[n],b[n],c[1000001];
    for(i=2;i<=1000000;i++)
    c[i]=1;
    c[1]=0;
    c[0]=0;
    soe(c);
    x=0;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    	if(c[a[i]]==1)
    	b[x++]=i+1;
    }
    if(x==0)
    {
    	for(i=0;i<n;i++)
    	printf("-1 ");
    }
    else
    {
    	if(b[x-1]!=n)
        b[x++]=n+1;
    	i=1;
    	while(i<b[0])
    	{
    		printf("%d ",b[0]);
    		i++;
    	}
    	index=0;
    	while(i<=n)
    	{
    		if(i-b[index]<=b[index+1]-i || b[index+1]==n+1)
    		printf("%d ",b[index]);
    		else
    		printf("%d ",b[index+1]);
    		if(i==b[index+1])
    		index++;
    		i++;
    	}
    }
    return 0;
}