#include <stdio.h>
#include<string.h>
int main(void) {
	// your code goes here
	int t,count,i,j,len1,len2;
	char a[101],b[101];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	   char c[26]={0},d[26]={0};count=0;
	  scanf("%s %s",a,b);
	  len1=strlen(a);len2=strlen(b);
	  for(j=0;j<len1;j++)
	  if(a[j]>64&&a[j]<91)
	  c[a[j]%65]=1;
	  else
	  d[a[j]%97]=1;
	  for(j=0;j<len2;j++)
	  if(b[j]>64&&b[j]<91)
	  {
	    if(c[b[j]%65]==1)
	    count++;
	  }
	  else
	  {
	      if(d[b[j]%97]==1)
	      count++;
	  }
	  printf("%d\n",count);
	}
	return 0;
}