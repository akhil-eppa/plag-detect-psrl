#include <stdio.h>
#include <stdlib.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
lint get_lint() {
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void put_lint (lint li, char lc) {
	if (0 == li) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24];
	auto idx =0;
	for (; li; idx++) {
		s[idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx-1; jdx>=0; jdx--)
		pcx(s[jdx]);
	if(lc) pcx(lc);
}
int cmp(const void *p, const void *q) {
	return (*(const lint*)p > *(const lint*)q);
}
int main () {
	lint T = get_lint();
	while(T--) {
        lint Bz[10000];
        lint Wz[10000];
        lint B = get_lint();
        lint W = get_lint();
        lint X = get_lint();
        for (auto bi=0; bi<B; bi++)
            Bz[bi] = get_lint();
        qsort (Bz, B, sizeof(lint), cmp);
 
        for (auto wi=0; wi<W; wi++)
            Wz[wi] = get_lint();
        qsort (Wz, W, sizeof(lint), cmp);
        
        lint boxCnt =0;
        for (auto wi=0, bi=0; wi<W && bi<B;) {
            if (Wz[wi] < Bz[bi]) {
                wi++; continue;
            }
            if (Wz[wi] > (Bz[bi] +X)) {
                bi++; continue;
            }
            boxCnt++; wi++; bi++;
        }
        put_lint(boxCnt, '\n');
	}
	return 0;
}