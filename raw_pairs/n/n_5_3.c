#include<stdio.h>
int main()
{
  long long new;
  scanf("%lld", &new);
  while (new --) {
    long long new2;
    scanf("%lld", &new2);
    int x = 1, y = 1;
    for (int i = 1; i <= new2; i++) {
      x = x * 2;
      y = y + x;
      if (new2 % y == 0) {
        printf("%lld\n", new2 / y);
        break;
      }
    }
  }
}
