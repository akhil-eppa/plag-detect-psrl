#include <stdio.h>
int main(void) {
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&k);
	    int a[n],i,j,p,d=0,e=0;
	    for(i=0;i<n;i++)
	    scanf("%d",a+i);
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            if(a[i]>a[j])
	            {
	                p=a[i];
	                a[i]=a[j];
	                a[j]=p;
	            }
	        }
	    }
	    if(k<=n/2)
	    {
	    for(i=0;i<k;i++)
	        d+=a[i];
	    for(i=k;i<n;i++)
	      e+=a[i];
	      printf("%d\n",e-d);
	    }
	    else 
	    {
	      for(i=0;i<n-k;i++) 
	      d+=a[i];
	      for(i=n-k;i<n;i++)
	      e+=a[i];
	       printf("%d\n",e-d);
	    }
	}
	return 0;
}

