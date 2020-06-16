#include <stdio.h>
#include <math.h>
int prime(int n)
{
    if(n==1 || n%2==0 && n!=2)
    return 0;
    int q=sqrt(n);
    for(int i=3;i<=q;i+=2)
    if(n%i==0)
    return 0;
    return 1;
}
int dsum(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int main()
{ 
        int d[1000001]={0};
        for(int i=1;i<1000001;i++)
        {
           if(prime(i))
           if(prime(dsum(i)))
           d[i]=1;
           d[i]=d[i]+d[i-1];
        }
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",d[b]-d[a-1]);
    }
}