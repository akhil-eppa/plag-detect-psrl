#include<stdio.h>
typedef long long ll;
int main(){
  int cycles;
  scanf("%d", &cycles);
  ll var1, var2;
  while (cycles--) {
    scanf("%lld%lld", &var1, &var2);
    var2--;
    while (var2--) {
      ll var3 = var1;
      int maxn = -1, minn = 10;
      while (var3) {
        ll n = var3 % 10;
        if (maxn < n)
          maxn = n;
        if (minn > n)
          minn = n;
        var3 /= 10;
      }
      if (minn == 0)
        break;
      var1 += maxn * minn;
    }
    printf("%lld\n", var1);
  }
        return 0;
}
