#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FI(i,s,n) for(i=s;i<=n;i++)
#define FD(i,n,s) for(i=n;i>=s;i--)
#define MA 1000000000000000000 // 1e18
#define M  1000000007
#define MM 2000000000
#define N  100005
#define K  100005
 
typedef long long ll;
typedef long double ld;
 
typedef struct { ll p, m; } ll2;
ll n,m;
ll a[K];
ll b[K];
 
char p[K];
ll pr[K],pc;
ll s[K];
 
void prime() {
  ll i, j;
  memset(p, 1, K);
 
  p[0]=p[1]=0;
  for(i=2;i*i<K;i++) {
    if (p[i]) {
      for(j=i+i;j<K;j+=i)
        p[j]=0;
    }
  }
 
  pc=0; pr[pc++]=2;
  for(i=3;i<K;i+=2) {
    if (p[i])
      pr[pc++]=i;
  }
}
 
int compare(const void* a, const void* b) {
  ll l = *((ll *)a);
  ll r = *((ll *)b);
 
  return l - r;
}
 
ll modpow(ll a, ll b, ll m) {
  ll r=1;
 
  while(b>0) {
    if (b%2==1) r=r*a % m;
    a=a*a % m;
    b=b>>1;
  }
 
  return r;
}
 
ll isPrime(ll n) {
  ll i;
  FI(i, 0, pc-1) {
    if (n%pr[i]==0) {
      return 0;
    }
  }
  return 1;
}
 
ll find(ll n) {
  ll i=1,r=0, k;
 
  while(n>0) {
    k=n%9;
    r+=k*i;
    n=n/9;
    i*=10;
  }
  return r;
}
 
ll gcd(ll a, ll b) {
  if (b==0) return a;
 
  return gcd(b, a%b);
}
 
int main() {
  ll t;
  ll i,j,k,d,l,r,x,y,z,p, q;
 
  char cc[80];
  //ll c,h;
 
  t=1;
  //prime();
  //scanf("%lld", &t);
 
  while(t--) {
    scanf("%lld", &n);
 
    FI(i,0,n-1) {
      scanf("%lld", a+i);
    }
 
    qsort(a, n, sizeof(ll), compare);
 
    p = a[n-1] - a[0];
    FI(i,1,n-1) {
      x = a[i]-a[i-1];
      p = gcd(MAX(x,p), MIN(x,p));
    }
 
    r = sqrt(p); j=0;
    FI(i,2,r) {
      if (p%i==0) {
        b[j++]=i;
        if (i*i!=p)
          b[j++]=p/i;
      }
    }
    b[j++]=p;
    qsort(b, j, sizeof(ll), compare);
    FI(i,0,j-1) {
      printf("%lld ", b[i]);
    }
    puts("");
  }
}