#include <stdio.h>
#include <math.h>
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
double final;
int isPrime(int n);
typedef struct 
{
    int a;
    int a2;
    int a3;
    int a4;
}answer;
int main()
{
	dp[0]=0;
	dp[1]=0;
    answer A;
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
   	A.a=isPrime(k);
   	k=k-(i-1);
   	A.a2=isPrime(k);
   	k=k-(i-1);
   	A.a3=isPrime(k);
   	k=k-(i-1);
   	A.a4=isPrime(k);
   	dp[i]=dp[i-2]+A.a+A.a2+A.a3+A.a4;
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
 
    if (n==2 || n==3)
        return 1;
 
    if (n%2==0 || n==1)
        return 0;
 
    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;
 
    return 1;
}