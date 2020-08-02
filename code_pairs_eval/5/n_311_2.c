#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main(){
	int iter, n, a, a_second;
	scanf("%d", &iter);

	while(iter--){

		long long ans = 0;

		scanf("%d%d", &n, &a_second);
		while(--n){
			scanf("%d", &a);

			if((a_second > 0) == (a > 0)){
				a_second = max(a, a_second);
			}
			else{
				ans += a_second, a_second = a;
			}
		}
		ans += a_second;
		printf("%lld\n", ans);
	}

	return 0;
}
