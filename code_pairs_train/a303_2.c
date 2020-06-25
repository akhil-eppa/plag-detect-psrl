#include <stdio.h>

int main(void) {
    int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,k;
	    scanf("%d %d",&n,&k);
	    int a[100];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);
	    }
	    for(int i=0;i<=n-2;i++)
	    {
	        int min=i;
	        for(int j=i+1;j<=n-1;j++)
	        {
	            if(a[j]<a[min])
	            min=j;
	            
	        }
	        int temp;
	        temp=a[i];
	        a[i]=a[min];
	        a[min]=temp;
	    }
	    if(k>n/2)
	    k=n-k;
	    int sum=0;
	    for(int i=0;i<k;i++)
	    {
	       sum+=a[i]; 
	    }
	    int cs=0;
	    for(int i=k;i<n;i++)
	    {
	        cs+=a[i];
	    }
	    int maxdiff=cs-sum;
	    printf("%d\n",maxdiff);
	}
	return 0;
}

