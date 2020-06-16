#include <stdio.h>
#include <stdlib.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
inline lint getli () {
	lint n =0;
	int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	} return n;
}
inline void putnli (lint n, char lc) {
	if (0 == n) {
        pcx('0'); if(lc) pcx(lc); return;
	} else if (n < 0) {
        pcx ('-'); n = ~n +1;
	}
	char s[24]; lint rdi =-1;
	while (n) {
		s[++rdi] = '0' + n % 10;
		n /= 10;
	}
	while (rdi>=0) pcx(s[rdi--]);
	if(lc) pcx(lc);
}
#define PLTsz   1000001
 
int main () {
    char plt [PLTsz];
    memset (plt, 1, sizeof(plt)); plt[0] = plt[1] =0;
    for (lint pn=4; pn<PLTsz; pn+=2) plt[pn] =0;
    for (lint pn=3; pn*pn<PLTsz; pn+=2) {
        if (plt[pn]) {
            for (lint ni=pn*pn; ni<=PLTsz; ni += pn)
                plt[ni] = 0;
        }
    }
	lint N = getli() +1;
	lint pMin =9999999, pMax =0;
	while(--N) {
        lint X = getli();
        if (plt[X]) {
            if (X<pMin) pMin =X;
            if (X>pMax) pMax =X;
        }
	}
	if (pMax) putnli(pMax-pMin, 0);
	else putnli (-1, 0);
	return 0;
}