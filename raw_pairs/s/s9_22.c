#include<stdio.h>
#define max 1000
int main()
{
char route[max];
 
int x,y,i=0;
x=y=0;
 
scanf("%s",route);
 
while(route[i]!='\0')
{
switch(route[i])
{
case 'L':
x-=1;
break;
case 'R':
x+=1;
break;
case 'U':
y+=1;
break;
case 'D':
y-=1;
break;
}
++i;
}
printf("%d %d",x,y);
 
}
 
