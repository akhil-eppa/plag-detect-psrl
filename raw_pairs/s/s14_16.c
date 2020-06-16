#include<stdio.h>
short int prime[100000000]={0};
int freq[10001]={0};
int main(void)
{
    int t,n,total;
    long long sum1,sum2,sum3,sum4;
    int i,j;
    int count;
    for(i=2;i<=sqrt(100000000);i++)
    {
        if(prime[i]==0)
        for(j=i*i;j<=100000000;j+=i)
        prime[j]=1;
    }
    
    for(i=2;i<10000;i+=2)
    {
        count=0;
        sum1=(i+1)*(i+1);
        sum2=sum1-i;
        sum3=sum2-i;
        sum4=sum3-i;
        if(prime[sum1]==0)
        count++;
        if(prime[sum2]==0)
        count++;
        if(prime[sum3]==0)
        count++;
        if(prime[sum4]==0)
        count++;
        freq[i+1]=count;
    }
    for(i=1;i<=10000;i++)
    freq[i]=freq[i]+freq[i-1];
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        total=n+n-1;
        printf("%f\n",(freq[n]*100.0/total));
    }
    
}