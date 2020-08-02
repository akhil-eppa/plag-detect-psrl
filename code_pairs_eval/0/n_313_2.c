#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main(){
	int t, n, a, a_;
	scanf("%d", &t);

	while(t--){

		long long ans = 0;

		scanf("%d%d", &n, &a_);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a);

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
