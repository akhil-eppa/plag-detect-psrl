#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T, N, K;
	int i, count;
	scanf ("%d", &T);
	int final[T];
	for (int j=0; j<T; j++) {
	    scanf ("%d", &N);
	    int playlist[N];
	    for (i=0; i<N; i++) {
	        scanf("%d", &playlist[i]);
	    }
	    scanf ("%d", &K);
	    count=0;
	    for (i=0; i<N; i++) {
	        if (playlist[K-1] < playlist[i]) {
	            count++;
	        }
	    }
	    final[j]=N-count;
	}
	for (i=0; i<T; i++) {
	    printf ("%d\n", final[i]);
	}
	return 0;
}

