#include <stdio.h>

int main()
{
    // number is the number to be checked
    int number, divisor, temp = 0; //temp is initially set to zero

    //Taking input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    for (divisor = 2; divisor <= number / 2; divisor++) {

        // condition for non-prime
        if (number % divisor == 0) {
            temp = 1;
            break;
        }
    }

    if (number == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (temp == 0)
            printf("%d is a prime number.", number);
        else
            printf("%d is not a prime number.", number);
    }

    return 0;
}