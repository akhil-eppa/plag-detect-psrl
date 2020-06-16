#include <stdio.h>
#include <math.h>
 
int a[1000001];
 
void soe()
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
 
int checkprime(int n)
{
	if(n<=1000000)
	{
		if(a[n]==1)
		return 1;
		else
		return 0;
	}
	else
	{
		int i,root,flag=1;
		root=sqrt(n);
		for(i=2;i<=root;i++)
		{
			if(n%i==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		return 1;
		else
		return 0;
	}
}
 
int main()
{
    int t,n,i,j,cnt;
    double val,tot;
    scanf("%d",&t);
    int ans[10000];
    for(i=2;i<=1000000;i++)
    	a[i]=1;
    a[0]=0;
    a[1]=0;
    soe();
    ans[1]=0;
    val=1;
    for(i=3;i<10000;i+=2)
    {
    	cnt=0;
    	cnt+=checkprime(val+i-1);
    	cnt+=checkprime(val+2*(i-1));
    	cnt+=checkprime(val+3*(i-1));
    	cnt+=checkprime(val+4*(i-1));
    	val=val+4*(i-1);
    	ans[i]=cnt+ans[i-2];
    }
    for(i=1;i<=t;i++)
    {
    	scanf("%d",&n);
    	val=ans[n]*100;
    	tot=2*n-1;
    	val=val/tot;
    	printf("%.6f\n",val);
    }
    return 0;
}