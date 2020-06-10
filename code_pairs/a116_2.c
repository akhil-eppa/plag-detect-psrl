#include <stdio.h>
int main() {
    int x, ttt, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &x);

    for (ttt = 2; ttt <= x / 2; ++ttt) {

        // condition for non-prime
        if (x % ttt == 0) {
            flag = 1;
            break;
        }
    }

    if (x == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag != 0)
            printf("%d is not a prime number.", x);
        else
			printf("%d is a prime number.", x);
    }

    return 0;
}