#include<stdio.h>
#define max(a,b) ((a>b)?(a):(b))

long long ways[1000006];

int main() {
  int var1, var2, var3, var4;
  scanf("%d%d%d%d", &var1, &var2, &var3, &var4);
  int t_x = var2 - var1, t_y = var3 - var2, l_z = var3 - var1 - var2,
      r_z = var4 - var1 - var2;
  long long answer = 0;
  for (int z = 0; z <= r_z; ++z) {
    int l = 0, r = z;
    if (r > t_x)
      r = t_x;
    // ( z - r, z - l )
    if (z - l > t_y)
      l = z - t_y;
    ways[z] = max(0, r - l + 1);
    if (z > 0)
      ways[z] += ways[z - 1];
  }
  for (int z = max(0, l_z); z <= r_z; ++z) {
    answer += ways[z];
  }
  printf("%lld\n",
         (((1ll * (var2 - var1 + 1)) * (var3 - var2 + 1)) * (var4 - var3 + 1)) -
             answer);
}
