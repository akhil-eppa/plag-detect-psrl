#include<stdio.h>
long int power(long int x,long int n)
{
    long int mod=1e9+7;
    if(n==0)
        return 1;
    else if(n%2==0)
        return power((x%mod*x%mod)%mod,n/2);
    else 
        return (x%mod*power((x%mod*x%mod)%mod,n/2)%mod)%mod;
}
int main()
{
    long int mod=1e9+7;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long int arr[n];
        long int a[n-1];
        
        for(int i=0;i<n;i++)
            scanf("%ld",&arr[i]);
        
        for(int i=0;i<n-1;i++)
            a[i]=(arr[i+1]*power(arr[i],mod-2))%mod;
            
        long int f=0;
        for(int i=0;i<n-1;i++)
            f=(f + ((a[i]%mod*(a[i]+1)%mod)*power(2,mod-2)%mod)%mod)%mod;
        
        long int q=((f%mod*(f+1)%mod)*power(2,mod-2))%mod;
        printf("%ld\n",q);
    }
}