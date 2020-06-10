#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
#define MAX_HTBKT (1<<16)
typedef long int lint;
 
lint getl () {
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void putl (lint n, char lc) {
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
 
typedef struct htn {
    lint idx;
    int str;
    int fgt;
    struct htn* nxt;
} HT_t;
 
HT_t *gHTBkt[MAX_HTBKT], *gNodePool;
lint gNPIdx =0;
 
HT_t* insHTval (lint X, int S) {
	lint bid = X & (MAX_HTBKT -1);
	HT_t *node = gNodePool + gNPIdx++;
    node->idx = X;
    node->str = S;
    node->fgt = 0;
    node->nxt = gHTBkt[bid];
    gHTBkt[bid] = node;
    return gHTBkt[bid];
}
 
lint getFgtCnt (lint X) {
    lint bid = X & (MAX_HTBKT -1);
    HT_t* node = gHTBkt[bid];
    while (node && (X != node->idx)) node = node->nxt;
    return (lint)node->fgt;
}
 
int main () {
    lint N = getl();
    gNodePool = (HT_t*) malloc (N * sizeof(HT_t));
    HT_t *FGT[N+1];
    lint Q = getl() +1;
    for (lint ni=1; ni<=N; ++ni) FGT[ni] = insHTval (ni, (int)getl());
    lint NF = N;
    while (N>1) {
        lint wi =0; //winner 
        for (lint ni=1; ni<N; ni+=2) {
            ++FGT[ni]->fgt; ++FGT[ni+1]->fgt;
            FGT[++wi] =(FGT[ni]->str > FGT[ni+1]->str)? FGT[ni] :FGT[ni+1];
        }
        if (N%2) FGT[++wi] = FGT[N];    // a walk-over
        N = wi; //winners of last round
    }
    while (--Q) putl(getFgtCnt(getl()), '\n');
	return 0;
}