#include<stdio.h>
#define ll long long
int main(){
	long t;
	scanf("%ld",&t);
	ll a,k;
	while(t--) {
		scanf("%lld%lld",&a,&k);
		k--;
		while(k--) {
			ll aa=a;
			long maxn=-1,minn=10;
			while(aa) {
				ll n=aa%10;
				if(maxn<n) maxn=n;
				if(minn>n) minn=n;
				aa/=10;
			}
			if(minn==0) break;
			a+=maxn*minn;
		}
		printf("%lld\n",a);
	}
	return 0;
}
