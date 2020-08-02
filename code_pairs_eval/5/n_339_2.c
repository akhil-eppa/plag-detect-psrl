#include <stdio.h>
int main(){
  int num, num2, num3, arr[200000], j, b[200002], sum = 0;
  scanf("%d", &num);
  for (num2 = 0; num2 < num; num2++) {
    scanf("%d", &num3);
    for (j = 0; j <= num3; j++) {
      b[j] = 0;
    }
    for (j = 0; j < num3; j++) {
      scanf("%d", &arr[j]);
      b[arr[j]]++;
    }
    j = 1;
    sum = 0;
    while (j <= num3) {
      sum += b[j] / j;
      b[j + 1] += b[j] % j;
      b[j] = 0;
      j++;
    }
    printf("%d\n", sum);
  }
        return 0;
}
