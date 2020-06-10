#include <stdio.h>
int main() {
   int i; double flag=0;
   int n;
    printf("Enter a positive integer: ");
    scanf("%f", &n);

    for (i = 2; i <= n / 2; ++i) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n != 1) {
         if (flag == 0)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }
    else {
        printf("1 is neither prime nor composite.");
    }

    return 0;
}