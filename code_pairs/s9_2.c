/*
Simple Calculator
This program is used to implement a simple calculator.
The mathematical operations that can be performed are addition, subtraction, multiplication and division.
It uses switch case statements to determine which operation must be performed.
*/

#include <stdio.h>
int main() {
    /*
    The operator is of char type
    and the two operands are of type double.
    */
    char operator;
    double first, second;
    
    //Taking input from the console.
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);

    //Using switch case to do the required operation
    switch (operator) {
    case '+':
        printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
        break;
    case '-':
        printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
        break;
    case '*':
        printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
        break;
    case '/':
        printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        break;
        // If the operator does not match any case, an error message is printed.
    default:
        printf("Error! operator is not correct");
    }

    return 0;
}