#include <stdio.h>

int main(void) {
	int T, X, Y, K, N, P, C, flag;
	scanf("%d", &T);
	
	while(T--) {
	    scanf("%d %d %d %d", &X, &Y, &K, &N);
	    flag=0;
	    while(N--) {
	        scanf("%d %d", &P, &C);
	        if ((P>=(X-Y)) && (K>=C)) {
	            flag=1;
	        }
	    }
	    if (flag) {
	        printf("LuckyChef\n");
	    } else {
	        printf("UnluckyChef\n");
	    }
	    flag=0;
	}
	
	return 0;
}

