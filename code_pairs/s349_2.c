#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FI(i,s,n) for(i=s;i<=n;i++)
#define FD(i,n,s) for(i=n;i>=s;i--)
#define SLL(a) scanf("%d", &a)
#define PLL(a) printf("%d ", a)
#define PLLN(a) printf("%d\n", a)
#define MA 1000000000000000000 // 1e18
//#define MA 1000000000000000LL // 1e15
#define M  1000000007
#define MM 2000000000
#define N  100005
#define K  100005
 
typedef int ll;
typedef long double ld;
 
typedef struct { ll n, i; } ll2;
ll n,m;
ll a[N];
ll b[N];
ll c[N];
//char s[N];
 
char p[K];
ll pr[K],pc;
 
void prime() {
  ll i, j;
  FI(i,0,K-1) {
    p[i]=1;
    b[i]=M;
  }
  b[1]=1;
 
  p[0]=p[1]=0;
  for(i=2;i*i<K;i++) {
    if (p[i]) {
      b[i]=i;
      for(j=i+i;j<K;j+=i) {
        p[j]=0;
        if (b[j]>i) b[j]=i;
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
  ll l = *((ll *)a);
  ll r = *((ll *)b);
 
//  if (l.n==r.n)
//    return l.i - r.i;
  return l - r;
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
 
ll combi(ll n, ll k) {
  ll i, r=1;;
  FD(i, n, n-k+1) {
    r*=i;
  }
  FD(i, k, 2) {
    r/=i;
  }
  return r;
}
 
ll isPrime(ll n) {
  ll i;
  for(i=0;pr[i]*pr[i]<=n;i++) {
    if (n%pr[i]==0)
      return 0;
  }
  return 1;
}
 
int main() {
  ll t;
  ll i,j,k,l,r,x,y,z, q;
  long double d;
 
  //ll c[26], cc;
 
  t=1;
  prime();
  SLL(t);
 
  a[1]=0; k=2; q=1;
  for(i=3;i<10000;i+=2) {
    a[i]=a[i-2];
    for(j=0;j<4;j++) {
      q+=k;
      //PLL(q);
      if (isPrime(q)) a[i]++;
    }
    k+=2;
  }
  while(t--) {
    SLL(n);
 
    k = 1 + (n/2) * 4;
    d = (long double) (a[n] * 100) / (long double) k;
    printf("%.6Lf\n", d);
  }
}