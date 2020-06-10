#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
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
lint getsx (char *Str, int sLen) {
	register int iCh = gcx();
	lint sl =-1;
	while(islower(iCh) && sl<sLen) {
		Str[++sl] = (char) iCh;
		iCh = gcx();
	} Str[++sl] = '\0';
	return sl;
}
int main () {
    lint R = getl();
    lint C = getl();
    char S[R][C+1];
    for (lint si=0; si<R; ) getsx(S[si++], C);
    
    lint opCnt =0;
    for (lint ci=0; ci<C; ++ci) {
        
        bool sChar =true;
        for (lint ri=1; ri<R && sChar; ++ri)
            if(S[ri][ci] != S[ri-1][ci])
                sChar =false;
        if (sChar) continue; //next column
        
        bool delCol =false;
        for (lint ri=1; ri<R && !delCol; ++ri)
            if (S[ri][ci] < S[ri-1][ci])
                delCol = true;
        if (delCol) ++opCnt;
        else break;
    }
    
    putl(opCnt, 0);
	return 0;
}