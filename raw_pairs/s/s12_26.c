#include <stdio.h>
#include <stdlib.h>
#define R 1000000007
typedef unsigned long long ull;
void get(int *z)
{
    char c=getchar_unlocked();
    for(*z=0;c>47 && c<58;c=getchar_unlocked())
        *z=*z*10+c-'0';
}
int main()
{
    int n, k, i;
    get(&n);
    get(&k);
    int a[n];
    for (i = 0; i < n; i++)
        get(a+i);
    long long int s, d, e;
    s = 0;
    d = 0;
    e = 0;
    for (i = 0; i < k; i++)
    {
        s += a[i] * (((long long int)i + 1) * (i + 1) % R);
        s %= R;
        
        d += a[i] * ((long long int)2 * i + 1);
        d %= R;
        
        if (i == 0)
        {
            continue;
        }
        e += 2 * a[i];
        e %= R;
    }
    
    printf("%lld ", s);
    
    for (i = 1; i < n - k + 1; i++)
    {
        long long int sqr = k;
        sqr *= k;
        sqr %= R;
        s = (s - d + (sqr * a[k + i - 1]));
        while (s < 0)
        {
            s += R;
        }
        s %= R;
        d = (d - e - a[i - 1] + ((long long int)2 * k - 1) * a[k + i - 1]);
        while (d < 0)
        {
            d += R;
        }
        d %= R;
        e = (e + 2 * (a[k + i - 1] - a[i]));
        while (e < 0)
        {
            e += R;
        }
        e %= R;
        printf("%lld ", s);
    }
}