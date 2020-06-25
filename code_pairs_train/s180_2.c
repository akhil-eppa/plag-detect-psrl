#include <stdio.h>
#include <math.h>
#define MAX 10000
#define D k=
#define COMMA ,
#define W scanf
int dp[MAX] COMMA ans COMMA ans2 COMMA ans3 COMMA ans4 COMMA n COMMA t COMMA i COMMA k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0;
	dp[1]=0;
   for(i=3;i<=MAX;i=i+2){
   	D i*i;
   	ans=isPrime(k);
   	D k-(i-1);
   	ans2=isPrime(k);
   	D k-(i-1);
   	ans3=isPrime(k);
   	D k-(i-1);
   	ans4=isPrime(k);
   	dp[i]=dp[i-2]+ans+ans2+ans3+ans4;
   }
   W("%d",&t);
   while(t--){
   	W("%d",&n);
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