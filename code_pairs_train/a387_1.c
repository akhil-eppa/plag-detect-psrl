#include <stdio.h>
double n, k;
double nck()
{
       if (n == k) return 1.0;
       n--, k--;
       if (k > n/2) k = n-k;
       double x = 1.0, r = n-k;
       while (k > 1)
             x *= (n/k), k--, n--;
       while (n > r)
               x *= (n/k), n--;
       return x;
}

int main()
{
    int t;
    double x;
    scanf("%d", &t);
    while (t>0)
    {
          scanf("%lf %lf", &n, &k);
          x = nck();
          printf("%.0lf\n", x);
          t--;
    }
    return 0;
}