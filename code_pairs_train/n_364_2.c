#include<stdio.h>
main()
{
  int loops, num1, num2, i, j, sum, q, arr1[30], arr2[30];
  scanf("%d", &loops);
  while (loops != 0) {
    scanf("%d%d", &num1, &num2);
    sum = 0;
    for (i = 0; i < num1; i++)
      scanf("%d", &arr1[i]);
    for (i = 0; i < num1; i++)
      scanf("%d", &arr2[i]);
    for (i = 0; i < num1 - 1; i++) {
      for (j = i + 1; j < num1; j++) {
        if (arr1[i] > arr1[j]) {
          q = arr1[i];
          arr1[i] = arr1[j];
          arr1[j] = q;
        };
        if (arr2[i] < arr2[j]) {
          q = arr2[j];
          arr2[j] = arr2[i];
          arr2[i] = q;
        };
      }
    };
    q = 0;
    while (q != num2) {
      if (arr1[q] < arr2[q])
        arr1[q] = arr2[q];
      q++;
    }
    for (i = 0; i < num1; i++)
      sum = sum + arr1[i];
    printf("%d\n", sum);
    loops--;
  }
}
