#include<stdio.h>
int main() 
{   
    int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
    int num = 5;
    int res = fac[num];
    printf("Factorial: %d\n",res);
} 
