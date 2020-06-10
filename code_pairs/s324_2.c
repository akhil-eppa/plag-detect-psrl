#include<stdio.h>
#include<math.h>
 
long long int p[1000501]={0};
 
void prime(long long int n)
{
    p[0]=1;
    p[1]=1;
    long long int i,j;
    
    for(i=2;i<=sqrt(n);i++)
    {
        if(p[i]==0)
        {
            for(j=2;i*j<=n;j++)
                p[i*j]=1;
        }
    }
    p[0]=0;
    p[1]=0;
    for(i=2;i<1000501;i++)
    {
        if(p[i]==0)
            p[i]=p[i-1]+i;
        else
            p[i]=p[i-1];
    }
    
}
 
void sum()
{
    long long int l,r;
    scanf("%lld %lld",&l,&r);
    printf("%lld\n",p[r]-p[l-1]);
}
 
int main()
{
    prime(1000501);
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        sum();
    return 0;
}