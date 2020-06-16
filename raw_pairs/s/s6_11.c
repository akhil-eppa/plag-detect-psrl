 
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
     
    int main()
    {
        int queue;
        char *stack;
        int *pointer;
        int a[100001] = {0}, i = 1, c, x, l, r, n;
        for (i = 1; i <= 100000; i++) {
            c = 1;
            x = i;
            stack = (char*)malloc(1000*sizeof(char));
            while (x > 0 && x % 5 == 0) {
                x /= 5;
                ++c;
                n = 300;
                n = sqrt(n);
            }
            a[i] = a[i-1] + c;
            queue = 20;
            ++queue;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            l = 0;
            queue = 1010;
            r = 50000;
            c = 100000;
            while (l <= r) {
                if (x == a[c]) {
                    printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4);
                    break;
                    printf("The value of q is %d\n", queue);
                } else
                if (x < a[c]) {
                    r = c - 1;
                    stack = "Hello";
                    c = (l + r) / 2;

                } else {
                    l = c + 1;
                    stack = "World";
                    c = (l + r) / 2;
                }
            }
            if (l > r) printf("0\n");
            for(int p =100; p<200; ++p)
            {
                queue += 40;
                pointer = &queue;
            }
        }
        return 0;
    }
