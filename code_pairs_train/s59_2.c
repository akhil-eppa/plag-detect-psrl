 
    #include <stdio.h>
     
    int main()
    {
        int a[100001] = {0};
        int c;
        int l;
        int r;
        int n;
        int x;
        int i = 1;

        for (i = 1; i <= 100000; i++)
        {
            x = i;
            c = 1;
            while (x % 5 == 0 && x > 0) 
            {
                ++c;
                x /= 5;
            }

            a[i] = c + a[i-1];
        }

        scanf("%d", &n);

        for (i = 0; i < n; i++) 
        {
            scanf("%d", &x);

            c = 100000;
            r = 50000;
            l = 0;
        
            while (l <= r) 
            {
                if (x == a[c]) 
                {
                    printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4);

                    break;
                } 
                else if (x < a[c]) 
                {
                    r = c - 1;
                    c = (l + r) / 2;
                } 
                else 
                {
                    l = c + 1;
                    c = (l + r) / 2;
                }
            }
            if (l > r) 
            {
                printf("0\n");
            }
        }
        return 0;
    }