#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	   int g;
	   scanf("%d",&g);
	   while(g--)
	   {
	       int i,n,q,head=0,tail=0;
	       scanf("%d %d %d",&i,&n,&q);
	       if(i==1)
	       {
	            if(n%2!=0)
	           {
	               tail=(n/2)+1;
	               head=(n/2);
	           }
	           else
	           {
	               tail=n/2;
	               head=n/2;
	           }
	       }
	       else
	       {
	           if(n%2!=0)
	           {
	               head=(n/2)+1;
	               tail=(n/2);
	           }
	           else
	           {
	               head=n/2;
	               tail=n/2;
	           }
	           
	       }
	       if(q==1)
	       printf("%d\n",head);
	       else
	       printf("%d\n",tail);
	   }
	    
	}
	return 0;
}

