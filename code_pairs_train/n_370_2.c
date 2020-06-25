#include<stdio.h>
#include<stdlib.h>
#define cv const void*
int num, k, num2, i, j, ans;
int cmp(cv one, cv two) { return (*(int *)one - *(int *)two); }
int main(){
  for (scanf("%d", &num2); num2; --num2) {
    scanf("%d%d", &num, &k);
    int a[num], b[num];
    ans = 0;
    for (i = 0; i < num; ans += a[i], ++i)
      scanf("%d", &a[i]);
    for (i = 0; i < num; ++i)
      scanf("%d", &b[i]);
    qsort(a, num, sizeof(int), cmp);
    qsort(b, num, sizeof(int), cmp);
    i = 0, j = num;
    while (k-- && i < num && j-- && b[j] > a[i])
      ans += b[j] - a[i], ++i;
    printf("%d\n", ans);
  }
}
