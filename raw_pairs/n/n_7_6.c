#include<stdio.h>
#include<stdlib.h>

int h[100005];

int cmpfn(const void *_a, const void *_b){
	int *a = (int *)_a;
	int *b = (int *)_b;
	return (*a) - (*b);
}

int main(){
	int n;
	int a;
	int r;
	int m;
	long long ans;
	scanf("%d %d %d %d", &n, &a, &r, &m);
	if(n == 1){
		printf("0\n");
		return 0;
	}
	if (m > a + r) m = a + r;
	int i;
	for(i = 0;i < n;i++)scanf("%d", h + i);
	qsort(h, n, sizeof(int), cmpfn);
	long long sumL;
	long long tot;
	for(i = 0, tot = 0;i < n;i++)tot += h[i];
	ans = tot*r;
	sumL = 0;
	for(i = 0;i < n - 1;i++){
		long long addL;
		long long addR;
		long long delL;
		long long delR;
		sumL += h[i];
		addL = (i + 1)*1ll*h[i] - sumL;
		addR = (i + 1)*1ll*h[i + 1] - sumL;
		delL = (tot - sumL) - (n - (i + 1))*1ll*h[i];
		delR = (tot - sumL) - (n - (i + 1))*1ll*h[i + 1];
		long long movL, movR;
		movL = addL < delL ? addL : delL;
		movR = addR < delR ? addR : delR;

		long long costL;
		long long costR;
		costL = (addL - movL)*1ll*a + (delL - movL)*1ll*r + movL*1ll*m;
		costR = (addR - movR)*1ll*a + (delR - movR)*1ll*r + movR*1ll*m;
		if(ans > costL) ans = costL;
		if(ans > costR) ans = costR;

		// meeting point
		if (addL <= delL && addR >= delR) {
			int x = tot/n;
			if (x >= h[i] && x <= h[i + 1]){
				long long add;
				long long del;
				long long mov;
				add = (i + 1)*1ll*x - sumL;
				del = (tot - sumL) - (n - (i + 1))*1ll*x;
				mov = add < del ? add : del;
				long long cost = (add - mov)*1ll*a + (del - mov)*1ll*r + mov*1ll*m;
				if (ans > cost) ans = cost;
			}
			x++;
			if (x >= h[i] && x <= h[i + 1]){
				long long add;
				long long del;
				long long mov;
				add = (i + 1)*1ll*x - sumL;
				del = (tot - sumL) - (n - (i + 1))*1ll*x;
				mov = add < del ? add : del;
				long long cost = (add - mov)*1ll*a + (del - mov)*1ll*r + mov*1ll*m;
				if (ans > cost) ans = cost;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
