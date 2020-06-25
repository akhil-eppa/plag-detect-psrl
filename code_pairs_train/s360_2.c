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
inline void putli (lint n, char lc) {
	if (0 == n) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24]; lint rdi =-1;
	while (n) {
		s[++rdi] = '0' + n % 10;
		n /= 10;
	}
	while (rdi>=0) pcx(s[rdi--]);
	if(lc) pcx(lc);
}
 
int main () {
	lint N = getli() +1;
    lint BF[N][N]; memset(BF, 0, sizeof(BF));
    lint Q = getli() +1;
    while (--Q) {
        lint P = getli();
        lint Ax = getli(); lint Zx = getli();
        lint Ay = getli()+1; lint Zy = getli() +1;
        for (lint ri=Ax; ri<Ay; ++ri) {
            BF[ri][Zx] ^= P;
            BF[ri][Zy] ^= P;
        }
    }
    for (lint ri=1; ri<N; ++ri) {
        lint ans =0;
        for (lint ci=1; ci<N; )
            putli (ans^=BF[ri][ci++], ' ');
        pcx('\n');
    }
	return 0;
}