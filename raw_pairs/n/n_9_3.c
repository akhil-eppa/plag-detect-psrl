#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main(){
	long t, n, a, a_;
	scanf("%ld", &t);

	while(t--){

		long long ans = 0;

		scanf("%ld%ld", &n, &a_);
		while(--n){
			scanf("%ld", &a);

			if((a_ > 0) == (a > 0)){
				a_ = max(a, a_);
			}
			else{
				ans += a_, a_ = a;
			}
		}
		ans += a_;
		printf("%lld\n", ans);
	}

	return 0;
}
