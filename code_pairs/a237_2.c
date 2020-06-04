#include <stdio.h>
 
int main()
{
  int c, d, k, m, n, p, q, sum = 0;
  int second[10][10], first[10][10], multiply[10][10];
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter elements of first matrix\n");
  for (c = 0; m>c; ++c)
    for (d = 0; n>d; ++d)
      scanf("%d", &first[c][d]);
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
  if (p != n)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
 
    for (c = 0; p>c; ++c)
      for (d = 0; q>d; ++d)
        scanf("%d", &second[c][d]);
    for (c = 0; m>c; ++c) {
      for (d = 0; q>d; ++d) {
        for (k = 0; p>k; ++k) {
          sum = first[c][k]*second[k][d]+sum;
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }
    printf("Product of the matrices:\n");
    for (c = 0; m>c; ++c) {
      for (d = 0; q>d; ++d)
        printf("%d\t", multiply[c][d]);
      printf("\n");
    }
  }
  return 0;
}