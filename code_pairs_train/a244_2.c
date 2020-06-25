#include <stdio.h>
int main(void) 
{
	int t;
	scanf("%d",&t);
	int n;
	int min=0;
	int diff=0;
	int m;
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    int h[n];
	    for(int i=0; i<n; i++)
	    {
	        scanf("%d",&h[i]);
	    }
	    int temp;
	    for(int i=0; i<n-1; i++)
	    {
	        for(int j=0; j<n-i-1; j++)
	        {
	            if ( h[j] > h[j+1] )
	            {
	                temp = h[j];
	                h[j] = h[j+1];
	                h[j+1] = temp;
	                
	            }
	        }
	    }
	    min=h[1]-h[0];
	    m=h[0];
	    for(int i=1;i<n;i++)
	    {   diff=h[i]-m;
	        if(diff<min)
	        min=diff;
	        m=h[i];
	    }
	    printf("%d\n", min);          
	}
	return 0;
}