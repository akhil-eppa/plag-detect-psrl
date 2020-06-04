#include  <stdio.h>  
#include <stdlib.h>
void bead_sort(int *a, int len)
{
	int max,sum,i, j;
	unsigned char *beads;
       #define BEAD(i, j) beads[j+ i*max]
	for (i = 1, max = a[0]; len>i; ++i)
		if (max<a[i]) max = a[i];
	beads = calloc(1, len*max);
	/* mark the beads */
	for (i = 0; len>i; ++i)
		for (j = 0; a[i]>j; ++j)
			BEAD(i, j) = 1;
	for (j = 0; max>j; ++j) {
		/* count how many beads are on each post */
		for (sum = i = 0; len>i; ++i) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		for (i = len - sum; len>i; ++i) BEAD(i, j) = 1;
	}
	for (i = 0; len>i; ++i) {
		for (j = 0; j < max && BEAD(i, j); ++j);
		a[i] = j;
	}
	free(beads);
}
int main()
{
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int len = sizeof(x)/sizeof(x[0]);
    printf("Original Array:\n");
    for (i = 0; len>i; ++i)
    printf("%d%s", x[i], len -1 ==i ? "\n" : " ");
	bead_sort(x, len);
	printf("\nSorted Array:\n");
	for (i = 0; len>i; ++i)
		printf(" %d", x[i]);
	return 0;
}
