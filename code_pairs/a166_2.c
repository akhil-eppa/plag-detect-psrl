#include  <stdio.h>  
#include <stdlib.h>
void bead_sort(int *a, int length)
{
	int ip, jp, maximum, total;
	unsigned char *bds;
       #define BEAD(ip, jp) bds[ip * maximum + jp]
	for (ip = 1, maximum = a[0]; ip < length; ip++)
		if (a[ip] > maximum) maximum = a[ip];
	bds = calloc(1, maximum * length);
	/* mark the bds */
	for (ip = 0; ip < length; ip++)
		for (jp = 0; jp < a[ip]; jp++)
			BEAD(ip, jp) = 1;
	for (jp = 0; jp < maximum; jp++) {
		/* count how many bds are on each post */
		for (total = ip = 0; ip < length; ip++) {
			total += BEAD(ip, jp);
			BEAD(ip, jp) = 0;
		}
		/* mark bottom total bds */
		for (ip = length - total; ip < length; ip++) BEAD(ip, jp) = 1;
	}
	for (ip = 0; ip < length; ip++) {
		for (jp = 0; jp < maximum && BEAD(ip, jp); jp++);
		a[ip] = jp;
	}
	free(bds);
}
int main()
{
	int ip, xarr[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int length = sizeof(xarr)/sizeof(xarr[0]);
    printf("Original Array:\n");
    for (ip = 0; ip < length; ip++)
    printf("%d%s", xarr[ip], ip == length - 1 ? "\n" : " ");
	bead_sort(xarr, length);
	printf("\nSorted Array:\n");
	for (ip = 0; ip < length; ip++)
		printf(" %d", xarr[ip]);
	return 0;
}
