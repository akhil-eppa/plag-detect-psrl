#include<stdio.h>
#define ll long long
int main(){
	int t;
	scanf("%d",&t);
	ll a,k;
	for(int i=0; i<t; i++) {
		scanf("%lld%lld",&a,&k);
		k--;
		while(k--) {
			ll aa=a;
			int maxn=-1,minn=10;
			for(;aa;aa/=10) {
				ll n=aa%10;
				if(maxn<n) maxn=n;
				if(minn>n) minn=n;
			}
			if(minn==0) break;
			a+=maxn*minn;
		}
		printf("%lld\n",a);
	}
	return 0;
}
