#include <stdio.h>
#include<stdlib.h>

long long int gcd(long long int first, long long int second) {
  if (first == 0)
    return second;

  return gcd(second % first, first);
}
long long int lcm(long long int first, long long int second) {
  return first * second / gcd(first, second);
}
int main()
{
  long long int i, temp, k, num, min, *arr, s, calc;
  // printf("%d",gcd(1,1));
  scanf("%lld", &num);
  arr = (long long int *)malloc(sizeof(long long int) * num);

  for (i = 0; i < num; i++) {
    scanf("%lld", &arr[i]);
  }
        k=0;
        calc = gcd(arr[0], arr[1]);
        s = lcm(arr[0], arr[1]);

        for (i = 2; i < num; i++) {
          s = gcd(s, lcm(calc, arr[i]));
          calc = gcd(calc, arr[i]);
        }
        printf("%lld", s);
        return 0;
}
