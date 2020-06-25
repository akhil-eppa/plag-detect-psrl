#include<stdio.h>
int main()
{
  int mult;
  scanf("%d", &mult);
  while (mult--) {
    int num, size;
    scanf("%d%d", &num, &size);
    long int arr[num + 1];
    for (int temp = 1; temp <= num; temp++)
      scanf("%ld", &arr[temp]);
    int peak[num + 1];
    for (int i = 0; i <= num; i++)
      peak[i] = 0;
    for (int temp = 2; temp < num; temp++) {
      if (arr[temp] > arr[temp + 1] && arr[temp] > arr[temp - 1])
        peak[temp] = 1;
    }
    int sum = 0;
    int pos = 1;
    for (int temp = 2; temp <= size - 1; temp++) {
      sum += peak[temp];
    }
    int max = sum;

    for (int temp2 = 2; temp2 <= num - size + 1; temp2++) {

      sum = sum - peak[temp2] + peak[temp2 + size - 2];
      if (max < sum) {
        max = sum;
        pos = temp2;
      }
    }
    printf("%d %d\n", max + 1, pos);
  }
        return 0;

}
