#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FI(i,s,n) for(i=s;i<=n;i++)
#define FD(i,n,s) for(i=n;i>=s;i--)
#define SLL(a) scanf("%lld", &a)
#define PLL(a) printf("%lld ", a)
//#define MA 1000000000000000000 // 1e18
#define MA 1000000000000000LL // 1e15
#define M  1000000009
#define MM 2000000000
#define N  1000005
#define K  1000005
 
typedef long long ll;
typedef long double ld;
 
typedef struct { ll n, i; } ll2;
ll n,m;
ll a[N];
ll b[N];
 
char p[K];
ll pr[K],pc;
 
void prime() {
  ll i, j;
  memset(p, 1, K);
 
  p[0]=p[1]=0;
  for(i=2;i*i<K;i++) {
    if (p[i]) {
      for(j=i+i;j<K;j+=i) {
        p[j]=0;
      }
    }
  }
 
  pc=0; pr[pc++]=2;
  for(i=3;i<K;i+=2) {
    if (p[i])
      pr[pc++]=i;
  }
}
 
int compare(const void* a, const void* b) {
  ll2 l = *((ll2 *)a);
  ll2 r = *((ll2 *)b);
 
  if (l.n==r.n)
    return l.i - r.i;
  return l.n - r.n;
}
 
ll modpow(ll a, ll b, ll m) {
  ll r=1;
  a=a%m;
  while(b>0) {
    if (b%2==1) r=r*a % m;
    a=a*a % m;
    b=b>>1;
  }
 
  return r;
}
 
ll gcd(ll a, ll b) {
  if (b==0) return a;
 
  return gcd(b, a%b);
}
 
ll ggcd(ll a, ll b) {
  return gcd(MAX(a,b), MIN(a,b));
}
 
ll lcd(ll a, ll b) {
  return a*b / gcd(a, b);
}
 
int main() {
  ll t;
  ll i,j,k,d,l,r,x,y,z,q;
 
  char cc;
 
  t=1;
//  prime();
  scanf("%lld", &t);
 
  while(t--) {
    scanf("%lld", &n);
 
    r = (modpow(10, n-1, M) * 5 % M - modpow(8, n-1, M) * 4 % M + M)%M;
    printf("%lld\n", r);
  }
}