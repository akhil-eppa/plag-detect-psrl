#include <stdio.h>
 
int main()
{
    int t;
    long int n,x,i;
    long int y[1000004];
    scanf("%d",&t);
    y[0] = 1;
    for(i=1;i<1000004;i++)
    {
    	y[i] = (i%1000003)*y[i-1];
    	y[i] %= 1000003;
    }
    for(i=0;i<t;i++)
    {
    		scanf("%lld%lld",&n,&x);
    		if(n>1000003)
    		{
    			printf("0\n");
    		}
    		else
    		{
	    		x = x%1000003;
				x = x*y[n];
				printf("%ld\n",x%1000003);
    		}
    }
    return 0;
}