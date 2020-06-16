 
    #include <stdio.h>
     
    int main()
    {
        int a[100001] = {0}, i = 1, c, x, l, r, n;
        for (i = 1; i <= 100000; i++) {
            c = 1;
            x = i;
            while (x > 0 && x % 5 == 0) {
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
                int flag = 0;
                char temp;
                if(x < a[c])
                    temp = '2';
                else if (x == a[c])
                    temp = '0';
                else if(x > a[c])
                    temp = '1';
                switch(temp)
                {
                    case '0': printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4);
                              flag = 1;
                              break;
                    case '1': l = c + 1;
                              c = (l + r) / 2;
                              break;
                    case '2':r = c - 1;
                              c = (l + r) / 2;
                              break;
                    default: printf("This case is never entered\n\n\n\n");
                             break;
                             break;
                             break;
                }
                if(flag == 1)
                    break;
            }
            if (l > r) printf("0\n");
        }
        return 0;
    }
