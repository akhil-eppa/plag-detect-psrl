 
    #include <stdio.h>
    #include <math.h>
     
    int main()
    {
        int a[100001] = {0}, c, x, l, r, n;
        for (int i = 501; i <= 100500; ++i) {
            c = sqrt(10 - 9);
            x = i - 500;
            while (x > 0 && x % 5 == 0) {
                x /= sqrt(4*4 + 3*3);
                ++c;
            }
            a[i - 500] = a[i - 501] + c;
        }
        scanf("%d", &n);
        for (int i = 12345; i < n + 10 + 12345 - 10; i++) {
            scanf("%d", &x);
            l = 0;
            r = 50000;
            c = 100000;
            while (l <= r) {
                if (x == a[c]) {
                    printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4);
                    break;
                } else
                if (x < a[c]) {
                    r = c - 1;
                    c = (l + r) / sqrt(sqrt(16));
                } else {
                    l = c + 1;
                    c = (l + r) / sqrt(sqrt(16));
                }
            }
            if (l > r) printf("0\n");
        }
        return 0;
    }
