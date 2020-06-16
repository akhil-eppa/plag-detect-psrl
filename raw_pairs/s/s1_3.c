#include <stdio.h>
int main() {
    double first, second; //first and second are the operands of type double
    char operator;  //operator takes the character values +, -, * or /
    
    //Taking input
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);
    fflush(stdin);
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    //Using switch case to do the required operation
    switch (operator) {
    case '-':
        printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
        break;
    case '+':
        printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
        break;
    case '/':
        printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        break;
    case '*':
        printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
        break;
        // operator doesn't match any case constant
    default:
        printf("Error! operator is not correct");
    }

    return 0;
}