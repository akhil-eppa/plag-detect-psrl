#include <stdio.h>

int main()
{
  long long run, size, k, a, b, temp;
  scanf("%lld", &run);
  while (run--) {
    scanf("%lld %lld", &size, &k);
    a = k - 1;
    b = 2 * (k - 1);

    if (size - a > 0 && (size - a) % 2 == 1) {
      printf("YES\n");
      for (temp = 0; temp < k - 1; temp++)
        printf("1 ");
      printf("%lld\n", size - a);
    } else if (size - b > 0 && (size - b) % 2 == 0) {
      printf("YES\n");
      for (temp = 0; temp < k - 1; temp++)
        printf("2 ");
      printf("%lld\n", size - b);
    } else
      printf("NO\n");
  }

        return 0;
}
