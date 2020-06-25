#include<stdio.h>
typedef long long ll;
const ll mod=1e9+7;
ll m[1005][1005];
ll cal(ll n,ll r,ll k)
{
    if(m[n][r]==0)
    {
        if(n==r||r==0)
        m[n][r]=1;
        else
        m[n][r]=(((cal(n-1,r-1,k))%k)+(cal(n-1,r,k)%k))%k;
    }
    return m[n][r];
}
ll modinv(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
ll fermat(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        res=(res*a)%c;
        a=(a*a)%c;
        b/=2;
    }
    return res;
}
int main()
{
    ll i,x,j,t,n,q,p;
    ll v[1000001];
    memset(v,1,sizeof(v));
    for(i=2;i*i<1000001;i++)
    if(v[i])
    for(j=2*i;j<1000001;j+=i)
    v[j]=0;
    v[0]=0;
    v[1]=0;
    memset(m,0,sizeof(m));
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        p=0;
        q=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(v[x])
            p++;
            else
            q++;
        }
        ll prod=1;
        for(i=0;i<=p;i++)
        {
            ll u=cal(p,i,mod-1);
            ll v=fermat(2,q,mod-1);
            ll res=(u*v)%(mod-1);
            res=modinv(i+2,res);
            prod=(prod*(res))%mod;
        }
        printf("%lld\n",prod);
    }
    
}