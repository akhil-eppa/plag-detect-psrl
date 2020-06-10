#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int foo(char x)
{
    int q = 0;
    return q;
}

int main()
{
    // n is the number to be checked
    int n;
    int flag = 0;
    int i;
    char name[20] = "abcd";

    //Taking input
    do
    {
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    }while(n<=0);


    for (i = 2; i <= n / 2; i++) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
        else
            continue;
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag == 0)
            printf("%d is a prime number.", n);
        else if (flag == 1)
            printf("%d is not a prime number.", n);
        else
        {
            for(int j = 1; j<=2000; ++j)
            {
                printf("0\n\n\n");
            }
        }
    }

    int ch = 34;
    ch = ch + 293;
    return 0;

    printf("This line is not printed");
}