#include<stdio.h>
# define X 1000001
#define ll long long
int prime[1000001];
ll sum[1000001];
void seive()
{
    prime[0]=1;
    prime[1]=1;
    int i,j;
    for( i=2;i*i<X;i++)
    {
        if(prime[i]==0)
        {
            for( j=i*i;j<X;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
void sumcount()
{
    sum[0]=0;
    int i;
    for( i=1;i<X;i++)
    {
        if(prime[i]==0)
        sum[i]=i+sum[i-1];
        else
        sum[i]=sum[i-1];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    seive();
    sumcount();
    int i;
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ll x=sum[r]-sum[l-1];
        printf("%ld\n",x);
    }
    return 0;
}