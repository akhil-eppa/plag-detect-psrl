#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0;
	dp[1]=0;
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
   	ans=isPrime(k);
   	k=k-(i-1);
   	ans2=isPrime(k);
   	k=k-(i-1);
   	ans3=isPrime(k);
   	k=k-(i-1);
   	ans4=isPrime(k);
   	dp[i]=dp[i-2]+ans+ans2+ans3+ans4;
   }
   scanf("%d",&t);
   while(t--){
   	scanf("%d",&n);
   	final=dp[n]*(100.0);
   	final=final/((2*n)-1);
   	printf("%.6f\n",final);
   }
    return 0;
}
int isPrime(int n){
    int i;

    switch(!(n!=3 && n!=2))
    {
        case false: break;
        default: return 1;
    }
 
    switch(!(n%2 && n!=1))
    {
        case true: return 0;
        default: break;
    }
 
    for (i=3;i<=sqrt(n);i+=2)
    {
        switch(n%i)
        {
            case true: break;
            case false: return 0;
        }
    }
 
    return 1;
}