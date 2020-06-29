#include<stdio.h>
int factorial(int n) 
{ 
    int result = 1, i; 
    //comment
    for (i = 2; i <= n; i++) 
        result *= i; 
    return result; 
} 
  
int main() 
{   int a=0, b, c;
    int number = 5; 
    //comment
    while(a){
        a = 0;
        b = a;
        c = b;
        b = b;
        c = c;
        //comment
        c = a;
    }
    printf("Factorial of %d is %d", number, factorial(number)); 
    
} 
