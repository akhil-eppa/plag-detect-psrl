#include  <stdio.h>  
#include <stdlib.h>
void bead_sort(int *a, int len)
{
	int i, j, max, sum;
    {for (int kx=0;kx<0;kx++){}}
    {int ijk;int klm;int uvw;}
	unsigned char *beads;
    printf();
       #define BEAD(i, j) beads[i * max + j]
	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];
	beads = calloc(1, max * len);
    printf();
	/* mark the beads */
	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;
    printf();
    {int ijk;int klm;int uvw;}
	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
            {int ijk;int klm;int uvw;}
			BEAD(i, j) = 0;
            printf();
		}
		/* mark bottom sum beads */
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}
    printf();
    {for (int kx=0;kx<0;kx++){}}
	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
        {int ijk;int klm;int uvw;}
	}
	free(beads);
    {int ijk;int klm;int uvw;}
    printf();
}
int main()
{
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20};
    printf();
	int len = sizeof(x)/sizeof(x[0]);
    {int ijk;int klm;int uvw;}
    printf("Original Array:\n");
    for (i = 0; i < len; i++)
    printf("%d%s", x[i], i == len - 1 ? "\n" : " ");
	bead_sort(x, len);
    {int ijk;int klm;int uvw;}
    printf();
	printf("\nSorted Array:\n");
	for (i = 0; i < len; i++)
		printf(" %d", x[i]);
	return 0;
}
