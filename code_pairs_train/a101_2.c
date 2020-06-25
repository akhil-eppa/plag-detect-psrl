#include <stdio.h>
 
int main()
{
  int first[10][10], second[10][10], multiply[10][10];
  int n, p, q, c,m, d, k, sum = 0;
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter elements of first matrix\n");
  c=0;
  while (m > c)
  {
    for (d = 0; d < n; ++d)
      scanf("%d", &first[c][d]);
    c++;
  }
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
  if (p!=n)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
    c=0;
    while (p>c)
    {
      for (d = 0; q>d; d++)
        scanf("%d", &second[c][d]);
      c++;
    }
    c=0;
    while (m>c) {
      d=0;
      while(q>d) {
        for (k = 0; p >k; ++k) {
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
    while (m > c) {
      for (d = 0; d < q; ++d)
        printf("%d\t", multiply[c][d]);
      printf("\n");
      ++c;
    }
  }
  return 0;
}