#include <stdio.h>
#include <stdlib.h>
typedef long int lint;
 
lint get_lint() { //Positive
	lint n =0;
	register int c = getchar_unlocked();
	while(c<'0' || c>'9') c = getchar_unlocked();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';  c = getchar_unlocked();
    }
	return n;
}
void put_lint (lint li, char lc) {//Negative
	if (0 == li) {
		putchar_unlocked((int)'0');
		putchar_unlocked((int)lc);
		return;
	}
	char s[24];
	auto idx =0;
	for (; li; idx++) {
		s[idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx-1; jdx>=0; jdx--)
		putchar_unlocked((int)s[jdx]);
	if(lc) putchar_unlocked((int)lc);
	return;
}
 
int main () {
	lint N = get_lint();
	int BA[N+1];
	BA[0] = 0;
	for (auto idx=1; idx<=N; idx++)
	    BA[idx] = get_lint();
	int TA[N+2];
	for (auto idx=0; idx<=N+1; idx++) TA[idx] =0;
	
	lint Q = get_lint();
	for (auto idx=0; idx<Q; idx++) {
	    lint L = get_lint();
	    TA[L] ^= 1;
	    lint R = get_lint();
	    TA[R+1] ^= 1;
	}
    lint bitSum =0;
    for (auto idx=1; idx<=N; idx++) {
        TA[idx] ^= TA[idx-1];
        BA[idx] ^= TA[idx];
        bitSum += BA[idx];
    }
    put_lint(bitSum, '\n');
    for (auto idx=1; idx<=N; idx++)
        put_lint (BA[idx], ' ');
    
	return 0;
}