#include <stdio.h>
#include <string.h>
int main() {
	
	int t,sum;
	char s[100];
	char j[100];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",j);
	    scanf("%s",s);
	    for(int i=0;i<strlen(j);i++)
	    {
            for(int k=i+1;k<strlen(j);k++)
            {
                if(j[k]==j[i])
                    j[k]='.';
            }
	    }
	    sum=0;
	    for(int i=0;i<strlen(j);i++)
	    {
	        if(j[i]!='.')
	        {
	            for(int k=0;k<strlen(s);k++)
	            {
	                if(j[i]==s[k])
	                    sum++;
	            }
	        }
	    }
	    //printf("%s",j);
	    printf("%d\n",sum);
	}
	return 0;
}