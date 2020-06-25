#include <stdio.h>

// n is the n to be checked
int n, i, flag = 0; //flag is initially set to zero

int main()
{


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

    if (n != 1) {
        if (flag == 1)
            printf("%d is not a prime number.", n);
        else
            printf("%d is a prime number.", n); 
    }
    else {
        printf("1 is neither prime nor composite.");
    }

    return 0;
}