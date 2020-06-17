#include<stdio.h>
int main()
{
  long long int loop, loop2, loop3, n, k, sum, q, minimum, maximum, b[101];
  char a[101];
  scanf("%lld", &loop);
  while (loop--) {
    scanf("%lld%lld", &n, &k);
    k = k - 1;
    while (k--) {
      loop3 = n;
      maximum = -1;
      minimum = 10;
      while (loop3) {
        q = loop3 % 10;
        if (maximum < q)
          maximum = q;
        if (minimum > q)
          minimum = q;
        loop3 = loop3 / 10;
      }
      if (minimum == 0)
        break;
      n = n + maximum * minimum;
    }
    printf("%lld\n", n);
  }
        return 0;
}
