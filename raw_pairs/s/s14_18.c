#include<stdio.h>
int isprime(int n)
{
int i;
if(n%2==0)
return 0;
for(i=3;i*i<=n;i+=2)
{
if(n%i==0)
return 0;
}
return 1;
}
 
int main()
{
int i,j,t,to=5,a1=9,a2=7,a3=5,a4=3,c=0,m=8,y=1;
double b[10001]={0};
for(i=3;i<=9999;i=i+2)
{
if(isprime(a2))
c++;
if(isprime(a3))
c++;
if(isprime(a4))
c++;
b[i]=(c/(to*1.0))*100;
m=8*(++y);
a2+=(m-2);
a3+=(m-4);
a4+=(m-6);
to+=4;
}
scanf("%d",&t);
while(t--)
{
scanf("%d",&i);
printf("%.6lf\n",b[i]);
}
}