#include<stdio.h>
int main()
{ 
unsigned n,k,testnum;
long long sub,ans,j,a,b,b1;
long long i,div,aa;

scanf("%u",&testnum);
 
for(i=0;i<testnum;i++)
{
scanf("%u %u",&n,&k);

a=n-1;
b=k-1;
b1=n-k;
if(n==k||k==1)
{
printf("1\n");

continue;
}

ans=1;
if(b>b1)
{
sub=b+1;
div=b1;
}


else 
{
sub=b1+1;
div=b;
}

aa=1;


for(j=a;j>=sub;j--)
{

ans=ans*j;
ans=ans/aa;
aa++;
}

printf("%lld\n",ans);
}
 
return 0;
}