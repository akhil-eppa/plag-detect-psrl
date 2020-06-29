#include<stdio.h>
int factorial(int n) 
{ 
    int res_ult = 1, index; 
    for (index = 2; index <= n; index++) 
        res_ult *= index; 
    return res_ult; 
} 
  
int main() 
{ 
    int numero = 5; 
    //this is a comment
    printf("Factorial of %d is %d", numero, factorial(numero)); 
    return 0; 
} 
