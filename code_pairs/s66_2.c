 
    #include <stdio.h>

    void first_for_loop(int a[100001])
    {
        int c, x;
        for (int i = 1; i <= 100000; i++) {
            c = 1;
            x = i;
            while (x > 0 && x % 5 == 0) {
                x /= 5;
                ++c;
            }
            a[i] = a[i-1] + c;
        }
    }

    void check(int *a, int *l, int *r, int *c, int *x)
    {
        while (*l <= *r) {
                if (*x == a[*c]) {
                    printf("5\n%d %d %d %d %d\n", 5 * (*c), 5 * (*c) + 1, 5 * (*c) + 2, 5 * (*c) + 3, 5 * (*c) + 4);
                    break;
                } else
                if (*x < a[*c]) {
                    *r = *c - 1;
                    *c = (*l + *r) / 2;
                } else {
                    *l = *c + 1;
                    *c = (*l + *r) / 2;
                }
            }
    }
     
    int main()
    {
        int a[100001] = {0}, x, c, l, r, n;

        first_for_loop(a);
        
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            l = 0;
            r = 50000;
            c = 100000;
            check(a, &l, &r, &c, &x);
            if (l > r) printf("0\n");
        }
        return 0;
    }
