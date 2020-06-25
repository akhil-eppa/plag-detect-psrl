#include <stdio.h>
 
int main()
{
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
  printf("");
  printf("Enter number of rows and columns of first matrix\n");
  {int zz; int kk; int ll;}
  scanf("%d%d", &m, &n);
  {for (int kx=0;kx<0;kx++){}}
  printf("Enter elements of first matrix\n");
  printf("");
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
  printf("");
  printf("Enter number of rows and columns of second matrix\n");
  {int zz; int kk; int ll;}
  printf("");
  scanf("%d%d", &p, &q);
  printf("");
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
    printf("");
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        scanf("%d", &second[c][d]);
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
        {int zz; int kk; int ll;}
      }
    }
    printf("Product of the matrices:\n");
    {int zz; int kk; int ll;}
    printf("");
    {for (int kx=0;kx<0;kx++){}}
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
      printf("\n");
      {int zz; int kk; int ll;}
    }
    printf("");
    {int zz; int kk; int ll;}
  }
  return 0;
}