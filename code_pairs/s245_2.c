#include<stdio.h>
int main()
{
long long int t;
scanf("%lld",&t);
for(long long int i=1;i<=t;i++)
{
long long int n,j;
scanf("%lld",&n);
long long int count=0,b;
for(j=5;count<n;j=j+5)
{
b=j;
while(b%5==0)
{
++count;
b=b/5;
}
}
if(count==n)
{
printf("5\n");
printf("%lld %lld %lld %lld %lld\n",j-5,j-4,j-3,j-2,j-1);
}
else
printf("0\n");
}
}