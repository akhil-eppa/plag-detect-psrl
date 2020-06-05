#include<stdio.h>
int times;
int main()
{
  scanf("%d", &times);
  for (int i = 0; i < times; i++) {
    int num, ksize;
    scanf("%d%d", &num, &ksize);
    int tmp1 = num - (ksize - 1);
    int tmp2 = num - (ksize - 1) * 2;
    if (tmp1 > 0 && tmp1 % 2 == 1) {
      printf("YES\n");
      for (int j = 0; j < ksize - 1; j++)
        printf("1 ");
      printf("%d\n", tmp1);
      continue;
    }
    if (tmp2 > 0 && tmp2 % 2 == 0) {
      printf("YES\n");
      for (int j = 0; j < ksize - 1; j++)
        printf("2 ");
      printf("%d\n", tmp2);
      continue;
    }
    printf("NO\n");
  }
        return 0;
}
