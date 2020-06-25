#include <stdio.h>
 
int main()
{
  int mxx, n, p, q, c, d, k, sumxx = 0;
  int first[10][10], second[10][10], multiply[10][10];
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &mxx, &n);
  printf("Enter elements of first matrix\n");
  c=0;
  for (c=0;c<mxx;c++)
  {
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
  }
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
    c=0;
    for (c=0;c < p;c++)
    {
      for (d = 0; d < q; d++)
        scanf("%d", &second[c][d]);
    }
    c=0;
    for (c=0;c<mxx;c++) {
      d=0;
      for (d=0;d < q;d++) {
        for (k = 0; k < p; k++) {
          sumxx = sumxx + first[c][k]*second[k][d];
        }
        multiply[c][d] = sumxx;
        sumxx = 0;
      }
    }
    printf("Product of the matrices:\n");
    c=0;
    for (c=0;c < mxx;c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
      printf("\n");
    }
  }
  return 0;
}