#include <stdio.h>
#define ll long long int
int find(ll a[],ll i,ll k)
{ll n=0,s=0,f=0;

    while(i>0)
    {
        if(i&1)
        {
         s=s+a[n]; 
        }
        i=i>>1;
        n++;
        if(s==k)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main(void) {
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll a[n];
   ll l=1<<n;
   
    for (ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ll x=0;
    for(ll i=1;i<l;i++)
    {
       x=find(a,i,k);
       if(x==1)
       {
           break;
       }
    }
    if(x==1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}	return 0;
}

