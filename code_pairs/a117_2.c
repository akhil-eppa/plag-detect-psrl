#include <stdio.h>
int main() {
    int i, n, temp = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2; n / 2>=i; i++) {

        // condition for non-prime
        if (n % i == 0) {
            temp = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (0 == temp)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}