#include<stdio.h>
long long gcd(long long first, long long second) {
  return second == 0 ? first : gcd(second, first % second);
}
int main()
{
  long long arr[100010];
  long long size, lcm = 0, gcd1 = 0;
  long long arr2[100010];
  scanf("%lld", &size);
  for (int i = 0; i < size; i++) {
    scanf("%lld", &arr2[i]);
  }
  for (long long j = size - 1; j >= 0; j--)
    arr[j] = gcd(arr[j + 1], arr2[j]);
  for (int i = 0; i < size; i++) {
    gcd1 = gcd(arr2[i] * arr[i + 1] / gcd(arr2[i], arr[i + 1]), gcd1);
  }

        printf("%lld",gcd1);
	return 0;
}
