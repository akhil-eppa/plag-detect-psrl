#include <stdio.h>

int main()
{
    // n is the number to be checked
    int n, i, flag = 0; //flag is initially set to zero

    //Taking input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2; i <= n / 2; i++) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1)
        printf("1 is neither prime nor composite.");
    else 
        flag ? printf("%d is not a prime number.", n) : printf("%d is a prime number.", n);
}