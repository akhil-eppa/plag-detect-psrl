 
    #include <stdio.h>
    #define MAX 100001
    #define ONE 1
    #define FIVE 5
    #define TWO 2
     
    int main()
    {
        int a[MAX] = {0}, i = ONE, c, x, l, r, n;
        for (i = ONE; i <= MAX - 1; i++) {
            c = ONE;
            x = i;
            while (x > 0 && x % FIVE == 0) {
                x /= FIVE;
                ++c;
            }
            a[i] = a[i-ONE] + c;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            l = 0;
            r = FIVE * 10000;
            c = MAX - ONE;
            while (l <= r) {
                if (x == a[c]) {
                    printf("5\n%d %d %d %d %d\n", FIVE * c, FIVE * c + ONE, 5 * c + 2 * ONE, FIVE * c + 3 * ONE, 5 * c + 4 * ONE);
                    break;
                } else
                if (x < a[c]) {
                    r = c - ONE;
                    c = (l + r) / TWO;
                } else {
                    l = c + ONE;
                    c = (l + r) / TWO;
                }
            }
            if (l > r) printf("0\n");
        }
        return 0;
    }
