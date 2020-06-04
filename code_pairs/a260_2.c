#include <stdio.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int g;
	    scanf("%d",&g);
	      while(g--)
	      {
	          int f,n,q;
	          scanf("%d %d %d",&f,&n,&q);
	          if(n%2==0)
	           printf("%d\n",n/2);  
	          else
	          {
	              if(f==1)
	              {
	                  if(q==1)
	                  printf("%d\n",n/2);
	                  else
	                  printf("%d\n",n/2+1);
	              }
	              else
	              if(q==1)
	                  printf("%d\n",n/2+1);
	                  else
	                  printf("%d\n",n/2);
	              
	          }
	      }
	}
	return 0;
}

