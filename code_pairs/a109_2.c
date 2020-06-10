#include <stdio.h>
int main() {
    int i, n, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2;n/2 >= i; i++) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (1==n) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag == 0)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}