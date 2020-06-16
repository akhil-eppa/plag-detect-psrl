#include <stdio.h>
#include <stdlib.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
lint get_lint() { //Negative
	lint n =0;
    auto neg =0;
	register int c = gcx();
	if ('-' == c) { neg =1; c = gcx(); }
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	if(neg) n *= -1;
	return n;
}
void put_lint (lint li, char lc) {//Positive
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
int cmp(const void *p, const void *q) { //ASC Order
	return (*(const lint*)p > *(const lint*)q);
}
inline lint min (lint A, lint B) {
	return (A < B ? A : B);
}
int main () {
	lint N = get_lint();
    lint X[N], Y[N];
    for (auto pi=0; pi<N; pi++) {
        X[pi] = get_lint();
        Y[pi] = get_lint();
    }
    qsort (X, N, sizeof(lint), cmp);
    qsort (Y, N, sizeof(lint), cmp);
    lint medX, medY;
    if (N %2) {
        medX = (N+1)/2 -1;
        medY = Y[medX];
        medX = X[medX];
    } else {
        medX = N/2 -1;
        medY = (Y[medX]+Y[medX+1]) /2;
        medX = (X[medX]+X[medX+1]) /2;
    }
    //printf ("mx:%ld my:%ld\n", medX, medY);
    lint xDiff =0, yDiff =0;
    for (auto pi=0; pi<N; pi++) {
        xDiff += labs(medX - X[pi]);
        yDiff += labs(medY - Y[pi]);
    }
    put_lint(min(xDiff, yDiff), 0);
    
	return 0;
}