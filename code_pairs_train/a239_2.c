#include <stdio.h>
#include<math.h>

int main() 
{	// your code goes her
	int t;
	scanf("%d",&t);
	while(t>0)
	{
	    int n,i,j,diff=0,min;
	    scanf("%d",&n);
	    int s[n];
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&s[i]);
	    }
	    min=abs(s[0]-s[1]);
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            diff=abs(s[i]-s[j]);
	            if(diff<min)
	            min=diff;
	        
	        }
	    }
	    printf("%d\n",min);
	    t--;
	}
	return 0;
}

