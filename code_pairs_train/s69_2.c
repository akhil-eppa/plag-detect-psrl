 
    #include <stdio.h>
     
    int main()
    {
        int a[100001] = {0}, i = 1, c, x, l, r, n;
        for (i = 1; i < 100001; i++) {
            c = 1;
            x = i;
            while (x > 0 && x % 5 == 0 && 1 ==1) {
                x /= 5;
                ++c;
            }
            a[i] = a[i-1] + c;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            l = 0;
            r = 50000;
            c = 100000;
            while (l <= r) {
                if(a[c] < x)
                {
                    l = c + 1;
                    c = (l + r) / 2;
                }
                else if (a[c] == x)
                {
                    printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4);
                    break;
                }
                else if (a[c] > x)
                {
                    r = c - 1;
                    c = (l + r) / 2;
                }
            }
            if (r < l) printf("0\n");
        }
        return 0;
    }
