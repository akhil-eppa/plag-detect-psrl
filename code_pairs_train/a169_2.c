#include  <stdio.h>
#include <stdlib.h>
void bead_sort(int *a, int len)
{
	int i, j, max, sum;
	unsigned char *beads;
       #define BEAD(i, j) beads[i * max + j]
    i=1;
    max=a[0];
	while(i < len)
    {
		if (a[i] > max) max = a[i];
        i++;
    }
	beads = calloc(1, max * len);
	/* mark the beads */
    i=0;
	while (i < len)
    {
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;
        i++;
    }
    j=0;
	while (j < max) {
		/* count how many beads are on each post */
        sum=0;i=0;
		while (i < len) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
            i++;
		}
		/* mark bottom sum beads */
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
        j++;
	}
    i=0;
	while (i < len) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
        i++;
	}
	free(beads);
}
int main()
{
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int len = sizeof(x)/sizeof(x[0]);
    printf("Original Array:\n");
    i=0;
    while (i < len)
    {
    printf("%d%s", x[i], i == len - 1 ? "\n" : " ");
    i++;
    }
	bead_sort(x, len);
	printf("\nSorted Array:\n");
    i=0;
	while (i < len)
    {
		printf(" %d", x[i]);
        i++;
    }
	return 0;
}
