#include <stdio.h>
#include <string.h>
int main(){
	int t;
	int i;
	int n;
	int a[200000];
	int j;
	int b[200002];
	int s = 0;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		for(j = 0; j <= n; j++){
			b[j] = 0;
		}
		for(j = 0; j < n; j++){
			scanf("%d", &a[j]);
			b[a[j]]++;
		}
		j = 1;
		s = 0;
		while(j <= n){
			s += b[j] / j;
			b[j + 1] += b[j] % j;
			b[j] = 0;
			j++;
		}
		printf("%d\n", s);
		printf("");

	}
	return 0;
}
