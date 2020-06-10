#include <stdio.h>
 
#define maxi 1000001
 
typedef long long int ll;
ll sum_of_primes[maxi];
 
void sieve()
{
int prime[maxi];
memset(prime,1,sizeof(prime));
for(int i=2;i*i<maxi;i++)
{
if(prime[i])
{
for(int j=i*2;j<maxi;j=j+i)
{
prime[j]=0;
}
}
}
prime[2]=1;
sum_of_primes[0]=0;
sum_of_primes[1]=0;
sum_of_primes[2]=2;
for(ll k=3;k<maxi;k++)
{
if(prime[k])
{
sum_of_primes[k]=sum_of_primes[k-1]+k;
}
else{
sum_of_primes[k]=sum_of_primes[k-1];
}
}
}
 
int main()
{
sieve();
int test,n,i,j;
scanf("%d",&test);
while(test--)
{
scanf("%d%d",&i,&j);
printf("%lld\n",sum_of_primes[j]-sum_of_primes[i-1]);
}
}
 
 
