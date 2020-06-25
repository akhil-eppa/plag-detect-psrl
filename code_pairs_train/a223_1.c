#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n,b,c,s,p;
	    scanf("%d",&n);
	    int a[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        scanf("%d",&p);
        s=a[p-1];
        for(int o=0;o<n;o++)
        {
	    for(int k=1;k<n;k++)
	    {
	        if(a[k-1]>a[k])
	        {
	           b=a[k];
	           c=a[k-1];
	           a[k-1]=b;
	           a[k]=c;
	        }
	    }
        }
	    for(int v=0;v<n;v++)
	    {
	        if(a[v]==s)
	        {
	            printf("%d\n",v+1);
	            break;
	        }
	    }
	}
	return 0;
}