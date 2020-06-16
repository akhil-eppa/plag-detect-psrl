#include <stdio.h>
int main()
{
int a,p,l,i;
long long int x,m;
scanf("%d",&a);
while(a--)
{
char b[100000];
long long count=0;
scanf("%s",b);
m=strlen(b);
for(i=0;i<m;i++)
{
if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u'||b[i]=='A'||b[i]=='E'||b[i]=='I'||b[i]=='O'||b[i]=='U')
{ x=(m-i)*(i+1);
count=count+x;
}
else
continue; }
printf("%lld\n",count);
 
}
return 0;
}