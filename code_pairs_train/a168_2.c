#include  <stdio.h>  
#include <stdlib.h>
void bead_sort(int *a, int len)
{
	unsigned char *beads;
    int i, j, max, sum;
    for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];
       #define BEAD(i, j) beads[i * max + j]
	beads = calloc(1, max * len);
	/* mark the beads */
	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;
	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}
	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
}
int main()
{
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int len = sizeof(x)/sizeof(x[0]);
    printf("Original Array:\n");
    for (i = 0; i < len; i++)
    printf("%d%s", x[i], i == len - 1 ? "\n" : " ");
	printf("\nSorted Array:\n");
    bead_sort(x, len);
	for (i = 0; i < len; i++)
		printf(" %d", x[i]);
	return 0;
}
