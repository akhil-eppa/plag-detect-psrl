#include <stdio.h>
#include <math.h>
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
double final;
void isPrime(int n, int* p);
int main()
{
	dp[0]=0;
	dp[1]=0;
    int p,q,r,s;
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
   	isPrime(k,&p);
   	k=k-(i-1);
   	isPrime(k,&q);
   	k=k-(i-1);
   	isPrime(k,&r);
   	k=k-(i-1);
   	isPrime(k,&s);
   	dp[i]=dp[i-2]+p+q+r+s;
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
void isPrime(int n, int* p){
    long i;
 
    if (n==2 || n==3)
    {
        *p = 1;
        return;
    }
    
    if (n%2==0 || n==1)
    {
        *p = 0;
        return;
    }
 
    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
        {
            *p = 0;
            return;
        }
 
    *p = 1;
}
