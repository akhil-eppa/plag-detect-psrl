 
    #include <stdio.h>
     
    int main()
    {
        int array[100001] = {0}, Ivalue = 1, Cvalue, x, left, right, number;
        for (Ivalue = 1; Ivalue <= 100000; Ivalue++) {
            Cvalue = 1;
            x = Ivalue;
            while (x > 0 && x % 5 == 0) {
                x /= 5;
                ++Cvalue;
            }
            array[Ivalue] = array[Ivalue-1] + Cvalue;
        }
        scanf("%d", &number);
        for (Ivalue = 0; Ivalue < number; Ivalue++) {
            scanf("%d", &x);
            left = 0;
            right = 50000;
            Cvalue = 100000;
            while (left <= right) {
                if (x == array[Cvalue]) {
                    printf("5\n%d %d %d %d %d\n", 5 * Cvalue, 5 * Cvalue + 1, 5 * Cvalue + 2, 5 * Cvalue + 3, 5 * Cvalue + 4);
                    break;
                } else
                if (x < array[Cvalue]) {
                    right = Cvalue - 1;
                    Cvalue = (left + right) / 2;
                } else {
                    left = Cvalue + 1;
                    Cvalue = (left + right) / 2;
                }
            }
            if (left > right) printf("0\n");
        }
        return 0;
    }
