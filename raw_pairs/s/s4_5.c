#include <stdio.h>

int main()
{
    // n is the number to be checked
    unsigned long int n;
    int i;
    char flag = 'P';

    //Taking input
    printf("Enter a positive integer: ");
    scanf("%lu", &n);

    for (i = 2; i <= n / 2; i++) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 'N';
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag == 'P')
            printf("%lu is a prime number.", n);
        else
            printf("%lu is not a prime number.", n);
    }

    return 0;
}