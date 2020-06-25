#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){ return *((int * )a) - *((int *)b);}

int main(void) {
	unsigned T;
	scanf(" %u", &T);
	
	unsigned N, jpos;
	int lenghts[100], j;
	while(T--){
	    //Main Loop
	    scanf(" %u", &N);
	    for(unsigned i = 0; i < N; i++) scanf(" %d", &lenghts[i]);
	    scanf(" %u", &jpos);
	    j = lenghts[jpos - 1];
	    qsort(lenghts, N, sizeof(int), cmp);
	    jpos = 0;
	    while(lenghts[jpos] != j) jpos++;
	    printf("%u\n", jpos + 1);
	}
	return 0;
}

