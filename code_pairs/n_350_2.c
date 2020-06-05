#include <stdio.h>
#include <stdlib.h>

void update(int *array, int size, int i, int v) {
  while (i <= size) {
    array[i] += v;
    i += i & -i;
  }
}
int sum(int *arr, int n, int index) {
  int out = 0;
  while (index > 0) {
    out += arr[index];
    index -= index & -index;
  }
  return out;
}
int getKth(int *array, int size, int k) {
  int pow = 1 << 20, idx = 0;
  while (pow > 0) {
    if (idx + pow <= size && array[idx + pow] < k) {
      idx += pow;
      k -= array[idx];
    }
    pow /= 2;
  }
  return idx + 1;
}
int main(void)
{
  int var1, var2;
  scanf("%d %d", &var1, &var2);
  int *arr;
  arr = calloc(var1 + 1, sizeof(int));

  for (int i = 0; i < var1; ++i) {
    int in;
    scanf("%d", &in);
    update(arr, var1, in, 1);
  }

  for (int i = 0; i < var2; ++i) {
    int k;
    scanf("%d", &k);

    if (k > 0) {
      update(arr, var1, k, 1);
    } else {
      update(arr, var1, getKth(arr, var1, -k), -1);
    }
  }

        int out = getKth(arr, var1, 1);
        if (sum(arr, var1, var1) == 0) {
          out = 0;
        }

        printf("%d\n", out);

	return 0;
}
