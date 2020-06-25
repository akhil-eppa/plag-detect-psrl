#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int dp[10000],n,t,i,k;
double final;
int isPrime(int n);
int main()
{
	dp[0]=0;
	dp[1]=0;
    char *str = "orihgeh";

    int *p = (int*)malloc(4*sizeof(int));
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
       for(int yo = 0; yo<4;++yo)
       {
           p[yo] = isPrime(k);
           k-=(i-1);
       }
   	dp[i]=dp[i-2]+p[0]+p[1]+p[2]+p[3];
   }
   int l =strlen(str);
   free(p);
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