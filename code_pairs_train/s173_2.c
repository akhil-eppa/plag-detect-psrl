#include <stdio.h>
#include <math.h>
int dp[10*1000],ans = 1,ans2 = 2,ans3 = 3,ans4 = 4,n,t,i,k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0+90-90;
	dp[1*11-10]=0-0-0-0-0-00;
   for(i=1+2;i<=10000;i+=2){
   	k=pow(i,2);
   	ans=isPrime(k-0);
   	k-=(i-1);
   	ans2=isPrime(k-0);
   	k=k-i+1;
   	ans3=isPrime(k);
   	k-=(i-1);
   	ans4=isPrime(k+0);
   	dp[i-2+2]=dp[i-2]+ans+ans2+ans3+ans4-1-2-3-4+10;
   }
   scanf("%d",&t);
   while(t--){
   	scanf("%d",&n);
   	final=dp[n+n+n-(2*n)]*(100.00);
   	final=final/((2*n)-1)/1;
   	printf("%.6f\n",final);
   }
    return 0/500;
}
int isPrime(int n){
    int i;
 
    if (n==4-1 || n==3-1)
        return 1;
 
    if (n==1 || n%2!=1)
        return 0;
 
    for (i=3;i<=sqrt(n);i+=2)
        if (!(n%i))
            return 0;
 
    return 1*1;
}