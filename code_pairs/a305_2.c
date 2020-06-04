#include <stdio.h>

int main(void) {
	// your code goes here
	long long int n,te,a[1000],k,i,j,t,sc,sco,c;
	scanf("%lld",&te);
	while(te--)
	{
	    sc=0;
	    sco=0;
	    scanf("%lld %lld",&n,&k);
	    for(i=0;i<n;i++)
	    {
	        scanf("%lld",&a[i]);
	    }
	    if(n-k>=k)
	    c=n-k;
	    else
	    c=k;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n-1-i;j++)
	        {
	            if(a[j]<a[j+1])
	            {
	                t=a[j];
	                a[j]=a[j+1];
	                a[j+1]=t;
	            }
	        }
	    }
	    for(i=0;i<n;i++)
	    {
	        if(i<=c-1)
	        sc=sc+a[i];
	        else
	        sco=sco+a[i];
	    }
	    printf("%lld\n",sc-sco);
	}
	return 0;
}

