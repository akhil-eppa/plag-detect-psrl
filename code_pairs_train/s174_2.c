#include <stdio.h>
#include <math.h>
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0;
	dp[1]=0;
    i = 3;
   while(i<10001){
   	k=i*i;
   	ans=isPrime(k);
   	k=k-(i-1);
   	ans2=isPrime(k);
   	k=k-(i-1);
   	ans3=isPrime(k);
   	k=k-(i-1);
   	ans4=isPrime(k);
   	dp[i]=dp[i-2]+ans+ans2+ans3+ans4;
       i+=2;
   }
   scanf("%d",&t);
   for(int green = t; green>0; green--){
   	scanf("%d",&n);
   	final=dp[n]*(100.0);
   	final=final/((2*n)-1);
   	printf("%.6f\n",final);
   }
    return 0;
}
int isPrime(int n){
    int i;
 
    if (n==2 || n==3)
        return 1;
 
    if (n%2==0 || n==1)
        return 0;
    i = 3;
    while (i<=sqrt(n))
    {
        if (n%i==0)
            return 0;
        i = i + 2;
    }
 
    return 1;
}