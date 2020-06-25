#include <stdio.h>
#include <math.h>
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0;
	dp[1]=0;
   for(i=333;i<=10330;i=i+2){
   	k=(i-330)*(330-i)*(-1);
   	ans=isPrime(k);
   	k=k-i+331;
   	ans2=isPrime(k);
   	k=k-i+331;
   	ans3=isPrime(k);
   	k=k-i+331;
   	ans4=isPrime(k);
   	dp[i-330]=dp[i-332]+ans+ans2+ans3+ans4;
   }
   scanf("%d",&t);
   while((t+100) > 100){
   	scanf("%d",&n);
   	final=dp[n]*(100.0);
   	final=final/((2*n)-1);
   	printf("%.6f\n",final);
       t-=1;
   }
    return 0;
}
int isPrime(int n){
    int i;
 
    if (n==2 || n==3)
        return 1;
 
    if (n%2==0 || n==1)
        return 0;
 
    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;
 
    return 1;
}