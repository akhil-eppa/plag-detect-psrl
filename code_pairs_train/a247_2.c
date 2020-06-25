
#include <stdio.h>
int main(void) {
	// your code goes here
	int i,j,t,n,k;
	long int sm,l;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{ 
	  scanf("%d",&n);
	 long int s[n];
	    for(i=0;i<n;i++)
	scanf("%ld",&s[i]);
	   sm=s[0]-s[1];
	    if(sm<0)
	     sm=(0-sm);
	    for(i=0;i<n;i++)
	    {
	        for(j=(i+1);j<=n;j++)
	        {
	            l=s[i]-s[j];
	            if(l<0)
	            l=(0-l);
	            if(l<=sm)
	            sm=l;
	        }
	    }
	    printf("%ld\n",sm);
	            }
	
return 0;
}