#include <stdio.h>
//Comments are added
#include <math.h>
//In every line
int dp[10000],ans,ans2,ans3,ans4,n,t,i,k;
//cc
double final;
//wwcw
int isPrime(int n);
//wqcwc
int main()
{
	dp[0]=0; //dp is zero
	dp[1]=0; //dp[1] is 0
    /*
        long
        multi
        line
        comm
        */
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
       //piece of code
   	ans=isPrime(k);
   	k=k-(i-1);
       //++k;
   	ans2=isPrime(k);
   	k=k-(i-1);////////
   	ans3=isPrime(k);
   	k=k-(i-1);///////
   	ans4=isPrime(k);
   	dp[i]=dp[i-2]+ans+ans2+ans3+ans4;
   }
   scanf("%d",&t);
   while(t--){
   	scanf("%d",&n);///////////
   	final=dp[n]*(100.0);///////////////
   	final=final/((2*n)-1);///////////////////
   	printf("%.6f\n",final);////////////////////////
   }/////////////////////////////////////////////////////
    return 0;
}//////////////////////////////////////////////////////////////
int isPrime(int n){///////////////////////////////////////////////////
    int i;/////////////wewewew
 //////////
    if (n==2 || n==3)
        return 1;
 /////////weweqggvqvytehvw
    if (n%2==0 || n==1)//twhw
        return 0;//hvww
 // 4t   r  t   
    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)//4t
            return 0;//23f
 //sg
    return 1;
}
/**/