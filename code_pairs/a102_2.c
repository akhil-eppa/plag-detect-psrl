#include <stdio.h>
 
int main()
{
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  {
    for (int zz=0;zz<0;zz++){}
  }
  printf("Enter elements of first matrix\n");
  printf("");
  c=0;
  while (c < m)
  {
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
    c++;
  }
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
    c=0;
    while (c < p)
    {
      for (d = 0; d < q; d++)
        scanf("%d", &second[c][d]);
      c++;
      printf("");
    }
    c=0;
    printf("");
    while (c < m) {
      d=0;
      while(d < q) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
        d++;
      }
      c++;
    }
    printf("Product of the matrices:\n");
    c=0;
    printf("");
    while (c < m) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
      printf("\n");
      c++;
    }
  }
  printf("");
  return 0;
}