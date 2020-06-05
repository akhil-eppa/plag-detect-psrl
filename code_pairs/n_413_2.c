#include<stdio.h>
int main()
{
  int new;
  scanf("%d", &new);

  while (new --) {
    long size;
    scanf("%ld", &size);

    if (((size / 2) % 2) == 1) {
      printf("NO\n");
      continue;
    } else
      printf("YES\n");

    for (int i = 1; i <= (size / 2); i++) {
      printf("%ld ", 2 * i);
    }
    for (int temp = 1; temp <= (size / 2); temp++) {
      if (temp != size / 2)
        printf("%ld ", ((2 * temp) - 1));
      else
        printf("%ld ", ((2 * temp) - 1 + (size / 2)));
    }

    printf("\n");
  }
}
