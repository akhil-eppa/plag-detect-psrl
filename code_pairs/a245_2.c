#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void) {
	int T, N, i, j;
	int min;
	scanf("%d", &T);
	for (i=0; i<T; i++) {
	    scanf ("%d", &N);
	    int S[N];
	    for (j=0; j<N; j++){
	        scanf ("%d", &S[j]);
	    }
	    qsort(S, N, sizeof(int), cmpfunc);
	    min=1000000000;
	    for (j=1; j<N; j++){
	        if (min > (S[j]-S[j-1])) {
	            min = (S[j]-S[j-1]);
	        }
	    }
	    printf("%d\n", min);
	}
	return 0;
}

