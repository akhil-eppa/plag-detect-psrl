#include <stdio.h>
 
int main()
{
  int mxx, n, p, qxx, c, d, k, sum = 0;
  int fst[10][10], snd[10][10], multiply[10][10];
  printf("Enter number of rows and columns of fst matrix\n");
  scanf("%d%d", &mxx, &n);
  printf("Enter elements of fst matrix\n");
  c=0;
  while (c < mxx)
  {
    for (d = 0; d < n; d++)
      scanf("%d", &fst[c][d]);
    c++;
  }
  printf("Enter number of rows and columns of snd matrix\n");
  scanf("%d%d", &p, &qxx);
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of snd matrix\n");
    c=0;
    while (c < p)
    {
      for (d = 0; d < qxx; d++)
        scanf("%d", &snd[c][d]);
      c++;
    }
    c=0;
    while (c < mxx) {
      d=0;
      while(d < qxx) {
        for (k = 0; k < p; k++) {
          sum = sum + fst[c][k]*snd[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
        d++;
      }
      c++;
    }
    printf("Product of the matrices:\n");
    c=0;
    while (c < mxx) {
      for (d = 0; d < qxx; d++)
        printf("%d\t", multiply[c][d]);
      printf("\n");
      c++;
    }
  }
  return 0;
}