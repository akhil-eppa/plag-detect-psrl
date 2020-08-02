#include <stdio.h>
int main(){
	int t, i, n, a[200000], j, b[200002], s = 0;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		j=0;
		while(j <= n){
			b[j++] = 0;
		}
		j=0;
		while(j < n){
			scanf("%d", &a[j]);
			b[a[j++]]++;
		}
		s = 0;
		for(j=1;j<=n;++j){
			s += b[j] / j;
			b[j + 1] += b[j] % j;
			b[j] = 0;
		}
		printf("%d\n", s);

	}
	return 0;
}
