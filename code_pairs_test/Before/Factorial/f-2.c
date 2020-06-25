#include<stdio.h>
int main() 
{   int res = 1;
    int i;
    int num = 5; 
    for(i=1;i<=num;i++) res*=i;
    printf("Factorial of %d is %d", num, res); 
    return 0; 
} 
