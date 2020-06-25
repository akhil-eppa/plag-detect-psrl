#include <stdio.h>

int main() {
  int times;
  scanf("%d", &times);
  while (times--) {
    int n, var, arr[100] = {}, arr2[105] = {}, c = 0, arr3[102] = {};
    scanf("%d%d", &n, &var);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      arr2[arr[i]] = arr[i];
    }
    for (int i = 1; i <= 100; i++) {
      if (arr2[i] != 0) {
        c++;
        arr3[c - 1] = arr2[i];
      }
    }
    if (c > var) {
      printf("-1");
    } else {
      printf("%d\n", n * var);
      while (n--) {
        for (int p = 0; p < var; p++) {
          printf("%d ", arr3[p % c]);
        }
      }
    }
    printf("\n");
  }
        return 0;
}
