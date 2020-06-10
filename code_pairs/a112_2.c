#include <stdio.h>
int main() {
   int tt; double ff=0;
   int n;
    printf("Enter a positive integer: ");
    scanf("%f", &n);

    for (tt = 2; tt <= n / 2; ++tt) {

        // condition for non-prime
        if (n % tt == 0) {
            ff = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (ff == 0)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}