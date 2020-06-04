#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int g;
	    scanf("%d",&g);
	    for(int i=0;i<g;i++)
	    {
	        int i,n,q;
	        scanf("%d %d %d",&i,&n,&q);
	        if(i==1 && n%2==1)
	        {
	            if(q==1)
	            printf("%d\n",n/2);
	            else
	            printf("%d\n",(n/2)+1);
	        }
	        else if(i==1 && n%2==0)
	        {
	            if(q==1)
	            printf("%d\n",n/2);
	            else
	            printf("%d\n",(n/2));
	        }
	        
	        else if(i==2 && n%2==1)
	        {
	            if(q==2)
	            printf("%d\n",n/2);
	            else
	            printf("%d\n",(n/2)+1);
	        }
	        
	       else if(i==2 && n%2==0)
	        {
	            if(q==2)
	            printf("%d\n",n/2);
	            else
	            printf("%d\n",(n/2));
	        }
	        
	    }
	}
	return 0;
}

