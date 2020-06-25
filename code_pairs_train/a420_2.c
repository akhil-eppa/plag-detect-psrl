#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	char m[26];
	scanf("%d %s",&t,m);
	char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char b[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	while(t--)
	{
	  char s[100],p;
	  int i=0,j,k,z;
	  
	  scanf("%s",s);
	  while(s[i]!='\0')
	  {
	  		z=(int)s[i];
	  	j=0,k=0;
	  	if(s[i]=='_')
	  		printf(" ");
	  
	  	else if(z>=97&&z<=122)
	  	{
	  	while(s[i]!=a[j])
	  	{
	  		k++;
	  		j++;
	  	}
	  	p=m[k];
	  	printf("%c",m[k]);
	    }
	    else if(z>=65&&z<=90)
	    {
	    	while(s[i]!=b[j])
	  	{
	  		k++;
	  		j++;
	  	}
	  	p=m[k]-32;
	  	printf("%c",p);
	    }
	    else
	    	printf("%c",s[i]);
	    i++;
	  }
	  printf("\n");
	}
	  return 0;
}