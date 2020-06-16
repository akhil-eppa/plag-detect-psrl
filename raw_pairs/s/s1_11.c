/***************************************************************
 Program to simulate a simple calculator using switch statement
 * 
 * Enter an expression: 100+50
 * Result: 150
 * 
 * Enter an expression: 21*21
 * Result: 441
 **************************************************************/
 
#include<stdio.h> // include stdio.h library
 
int main(void)
{       
    int a, b, result;
    char op; // to store the operator
    
    printf("Enter an expression: ");
    scanf("%d%c%d", &a, &op, &b);
 
    switch(op)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;              
    }
    
    printf("Result = %d", result);
    
    return 0; // return 0 to operating system
}