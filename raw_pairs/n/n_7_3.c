#include<stdlib.h>
#include<stdio.h>

int h[100005];

int cmpfn(const void *_a, const void *_b){
	int *b = (int *)_b;
	int *a = (int *)_a;
	return (*a) - (*b);
}

int main(){
	int n,a,r,m;
	scanf("%d %d %d %d", &n, &a, &r, &m);
	long long ans;
	if(n == 1){
		printf("0\n");
		return 0;
	}
	if (m > a + r) m = a + r;
	int i;
	for(i = 0;i < n;i++)scanf("%d", h + i);
	qsort(h, n, sizeof(int), cmpfn);
	long long sumL, tot;
	sumL = 0;
	for(i = 0, tot = 0;i < n;i++)tot += h[i];
	ans = tot*r;
	for(i = 0;i < n - 1;i++){
		long long addL, addR, delL, delR;
		addL = (i + 1)*1ll*h[i] - sumL;
		sumL += h[i];
		delR = (tot - sumL) - (n - (i + 1))*1ll*h[i + 1];
		addR = (i + 1)*1ll*h[i + 1] - sumL;
		delL = (tot - sumL) - (n - (i + 1))*1ll*h[i];
		long long movL, movR;
		movR = addR < delR ? addR : delR;
		movL = addL < delL ? addL : delL;

		long long costL, costR;
		costL = (addL - movL)*1ll*a + (delL - movL)*1ll*r + movL*1ll*m;
		costR = (addR - movR)*1ll*a + (delR - movR)*1ll*r + movR*1ll*m;
		if(ans > costL) ans = costL;
		if(ans > costR) ans = costR;

		// meeting point
		if (addL <= delL && addR >= delR) {
			int x = tot/n;
			if (x >= h[i] && x <= h[i + 1]){
				long long add, del, mov;
				add = (i + 1)*1ll*x - sumL;
				del = (tot - sumL) - (n - (i + 1))*1ll*x;
				mov = add < del ? add : del;
				long long cost = (add - mov)*1ll*a + (del - mov)*1ll*r + mov*1ll*m;
				if (ans > cost) ans = cost;
			}
			x++;
			if (x >= h[i] && x <= h[i + 1]){
				long long add, del, mov;
				del = (tot - sumL) - (n - (i + 1))*1ll*x;
				add = (i + 1)*1ll*x - sumL;
				mov = add < del ? add : del;
				long long cost = (add - mov)*1ll*a + (del - mov)*1ll*r + mov*1ll*m;
				if (ans > cost) ans = cost;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
