#include <stdio.h>
void take_input(char *operator, double *first, double *second);
void calculate(char operator, double first, double second);

int main()
{
    char operator;  //operator takes the character values +, -, * or /
    double first, second; //first and second are the operands of type double
    
    take_input(&operator, &first, &second);

    calculate(operator, first, second);

    return 0;
}

void take_input(char *operator, double *first, double *second)
{
    //Taking input
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", first, second);
}

void calculate(char operator, double first, double second)
{
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
        // operator doesn't match any case constant
    default:
        printf("Error! operator is not correct");
    }
}