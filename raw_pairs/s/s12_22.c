#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
lint get_str(char *s, int l) {
	register int c = gcx();
	lint sl =0;
	while(isprint(c) && sl<l) {
		s[sl++] = (char)c;
		c = gcx();
	}
	s[sl] = '\0';
	return sl;
}
void put_str (char *s, lint l) {
	for (auto ci=0; ci<l; ci++)
		pcx(s[ci]);
}
int main () {
	lint T = get_lint();
	while(T--) {
        char str[101];
        lint N = get_lint();
        lint sl = get_str(str, sizeof(str));
        lint K = get_lint();
        lint cake[101];
        lint cCnt =0;
        for (auto cid =0; cid<sl;) {
            if ('*'== str[cid]) {
                cake[cCnt++] = cid;
                cid++;
            } else if ('P' == str[cid]) {
                lint tLeft =K;
                if(cCnt) {
                    lint db = cid-cake[0];
                    if (db > K) break;
                    cCnt =0;
                    tLeft = (K-(2*db) >= (K-db)/2) ? K-(2*db) : (K-db)/2; // vortex
                }
                cid++; // next iteration
                while (tLeft>0 && cid<sl) {
                    if ('P'==str[cid]) break;
                    tLeft --; cid++;
                }
            } else {    // '.'
                cid++;
            }
        }
        if (0==cCnt) put_str("YES\n", 4);
        else put_str("NO\n", 3);
	}
	return 0;
}