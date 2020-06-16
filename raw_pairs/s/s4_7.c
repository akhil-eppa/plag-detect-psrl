#include <stdio.h>

int main()
{
    // n is the number to be checked
    int n, flag = 0; //flag is initially set to zero
    int i = 2;
    //Taking input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while(i<=n/2)
    {
        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
        i+=1;
    }

    if (n == 1) {
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