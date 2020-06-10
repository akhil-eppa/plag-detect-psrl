#include <stdio.h>

int check_prime(int x);

int main()
{
    // n is the number to be checked
    int n;

    //Taking input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int is_prime = check_prime(n);

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (is_prime)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}

int check_prime(int x)
{
    int flag = 1;
    for (int i = 2; i <= x / 2; i++) {

        // condition for non-prime
        if (x % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}