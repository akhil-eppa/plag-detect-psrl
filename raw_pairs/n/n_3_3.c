#include <stdio.h>
#include <stdlib.h>

int main()
{
  long long int loop;
  scanf("%lld", &loop);

  do {
    long long int num;
    scanf("%lld", &num);

    long long int arr[num];
    long long int temp;
    for (temp = 0; temp < num; ++temp) {
      scanf("%lld", &arr[temp]);
    }

    long long int sol = 0;
    for (temp = 0; temp < num - 1; ++temp) {
      if (arr[temp] + 1 < arr[temp + 1]) {
        sol = 1;
      }
    }

    if (sol == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }

    --loop;
  } while (loop != 0);
        //system("pause");
}
