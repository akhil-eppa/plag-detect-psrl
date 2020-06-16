#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
typedef long long ll;
ll f[1000005],ifact[1000005],mod=1e9+7;
 
long long mul(long long x,long long y,long long z){
	long long res =0;
	while(y){
		if(y&1) res = (res+x)%z;
		x =(2*x)%z;
		y/=2;
	}
	return res;
}
 
ll power(ll x, ll y, ll p)
{
    ll res = 1;      
   
     x=x%p;           
 
    while (y )
    {
        
        if (y & 1)
            res = mul(res,x,p)%p ;
 
        x=mul(x,x,p)%p;
        y/=2;
    }
    return res;
}
 
 
 
bool prime[1000001]; 
    
void sieve() 
{ 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=1000000; p++) { 
        
        if (prime[p] == true){ 
            for (int i=p*p; i<=1000000; i += p) 
                prime[i] = false; 
        } 
    } 
    
} 
  
long long pre_ncr[1005][1005];
void preNCR(){
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if (j==0||j==i||i==0)
                pre_ncr[i][j]=1;
            else
                pre_ncr[i][j]=pre_ncr[i-1][j-1]+pre_ncr[i-1][j];
            pre_ncr[i][j]%=mod;
        }
    }
  }
int main()
{
    preNCR();
    //fact();
    sieve();
    ll t,n,P=0,i;
    ll pow2[1100];
    pow2[0]=1;
    for(i=1;i<=1000;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
    }
    scanf("%lld",&t);
    while(t--){
        P=0;
        ll a[2000];
        scanf("%lld ",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            
            if(prime[a[i]]==true){
                P++;
            }
        }
        ll sum=1,x,y;
        for(i=0;i<=P;i++){
            x=pre_ncr[P][i];
            y=pow2[n-P];
            sum=(sum*power(i+2,x*y,mod))%mod;
        }
        printf("%lld\n",sum);
        
    }
}