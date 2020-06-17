#include<stdio.h>
#include <stdlib.h>
int main()
{
  int tcount;
  scanf("%d", &tcount);
  while (tcount--) {
    int num, k, b[10000] = {0}, c[10000] = {0};
    scanf("%d%d", &num, &k);
    int temp, sum = 0, arr[10000], j, loop, mm;
    for (temp = 1; temp <= num; temp++) {
      scanf("%d", &arr[temp]);
      c[arr[temp]]++;
    }
    for (temp = 1; temp <= num; temp++)
      if (c[temp] > 0)
        sum++;
    for (temp = 1, j = 1; temp <= num; temp++)
      if (c[arr[temp]] > 0) {
        b[j++] = arr[temp];
        c[arr[temp]] = 0;
      }
    if (sum > k) {
      printf("-1\n");
      continue;
    }
    if (sum < k) {
      temp = 1;
      mm = k - sum;
      while (mm--) {
        b[j++] = b[temp++];
        if (temp == sum)
          temp = 1;
      }
    }
    printf("%d\n", num * 65);
    for (temp = 1, loop = 1; temp <= num * 65; loop++, temp++) {
      if (loop == j)
        loop = 1;
      printf("%d ", b[loop]);
    }

    printf("\n");
  }
}
