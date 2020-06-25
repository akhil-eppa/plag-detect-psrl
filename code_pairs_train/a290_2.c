#include <stdio.h>
#include <string.h>
int main()
{ int t,i,x,count;
	char s[100],j[100];
	scanf("%d",&t);
	while(t--)
	{   count=0;
		scanf("%s",j);
		scanf("%s",s);
		for(i=0;i<strlen(s);i++)
		  { for(x=0;x<strlen(j);x++)
			 { if(s[i]==j[x])
			    { count++;
				  break;
		        }
	      }
	    }
	   printf("%d\n",count);   
     }
 return 0;
} 