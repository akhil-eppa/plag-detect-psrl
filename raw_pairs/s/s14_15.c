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
inline lint isPrime (lint X) {
    if (X < 4) return (X > 1);
    if (!(X%2) || !(X%3)) return 0;
    for (lint n=5; n <= sqrt(X); n+=2) if (!(X%n)) return 0;
    return 1;
}
 
int main () {
    lint dpCnt[10000] = {0};
    lint pCnt =0;
    lint seed =1;
    for (lint si=2; si<10000; si+=2) {
        dpCnt[si+1] = dpCnt[si-1]+isPrime(seed+si)+isPrime(seed+2*si)
                        +isPrime(seed+3*si)+isPrime(seed+(si<<2));
        seed +=si<<2;
    }
        
	lint T = getli() +1;
	while(--T) {
        lint N = getli();
        printf ("%f\n", dpCnt[N]*100.0/(2.0*N-1));
	}
	return 0;
}