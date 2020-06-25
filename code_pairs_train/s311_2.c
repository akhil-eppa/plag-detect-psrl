#include<stdio.h>
typedef long long int ll;
#define M 1000000007
 
ll gcd_extended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll xx, yy;
    ll gcd1 = gcd_extended(b%a, a, &xx, &yy);
    *y = xx;
    *x = yy - ((b/a) * xx);
    return gcd1;
}
 
ll modular_inverse(ll a,ll b)
{
	ll x,y;
	ll g=gcd_extended(a,b,&x,&y);
	if(g!=1)
		printf("No Solution!");
	return ((x%b)+b)%b;	
}
 
int main()
{
    ll T,n;
    scanf("%lld",&T);
    ll p;
    while(T--)
    {
    	p=0;
    	scanf("%lld",&n);
    	ll arr[n];
    	for(ll i=0;i<n;i++)
    	{
    		scanf("%lld",&arr[i]);
		}
		 
 		ll N,res;
		for(ll i=0;i<n-1;i++)
		{
		    N=(arr[i+1]*modular_inverse(arr[i],M))%M;
			res=((N*(N+1))/2)%M;
			p=(p+res)%M;	
        }	
		printf("%lld\n",((p*(p+1))/2)%M);
	}
	return 0;
}