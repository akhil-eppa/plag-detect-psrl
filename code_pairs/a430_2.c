#include <stdio.h>
#include<string.h>
int main(void) 
{
	int t,i,l,j;
	char a[30],b[30],s[105],c,d[30];
	for(i=0;i<26;i++)
	{
	    a[i]=i+'a';
	    b[i]=i+'A';
	}
	scanf("%d",&t);
	scanf("%s",d);
	while(t--)
	{
	    scanf("%s",s);
	    l=strlen(s);
	    for(i=0;i<l;i++)
	    {
	        if(s[i]>='a' && s[i]<='z')
	        {
	            for(j=0;a[j]!='\0';j++)
	            {
	                if(s[i]==a[j])
	                {
	                    s[i]=d[j];
	                    break;
	                }
	            }
	        } 
	        else if(s[i]>='A' && s[i]<='Z')
	        {
	            for(j=0;b[j]!='\0';j++)
	            {
	                if(s[i]==b[j])
	                {
	                    s[i]=(d[j]-'a'+'A');
	                    break;
	                }
	            }
	        }
	        else if(s[i]=='_')
	            s[i]=' ';
	    }
	    printf("%s\n",s);
	}
	return 0;
}

