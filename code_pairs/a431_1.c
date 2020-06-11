#include<stdio.h>
 
 
int main()
{
int i,j,t;
char m[27],str[102];
scanf("%d", &t);
scanf("%s", m);
while(t--)
{
scanf("%s", str);
for(i=0;str[i];++i)
{
if((str[i]>=65 && str[i] <=90) )
{
printf("%c",m[str[i]-65] - 32);
}
else if(str[i]>=97 && str[i]<=122)
printf("%c",m[str[i]-97]);
else if(str[i] == '_')
{
printf(" ");
}
else
printf("%c",str[i]);
}
printf("\n");
}
return 0;
}