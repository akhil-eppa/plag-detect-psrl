#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    char operator;  //operator takes the character values +, -, * or /
    double first, second; //first and second are the operands of type double
    int is_correct = 0;

    for(int i=0; i<9; ++i)
    {
        if(is_correct)
           printf("It is correct");
    }
    
    //Taking input
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    if(operator == '+')
        printf("Addition has to be done\n");
    else if(operator == '-')
        printf("Subtraction has to be done\n");
    else if(operator == '*')
        printf("Multiplication has to be done\n");
    else if(operator == '/')
        printf("Division has to be done\n");
    else
    {
        printf("Error! operator is not correct");
        exit(0);
    }
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);
    printf("The operands have been successfully entered as: %.1lf and %.1lf\n", first, second);

    //Using switch case to do the required operation
    switch (operator) {
    case '+':
        printf("The sum of the two numbers is: ");
        printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
        break;
    case '-':
        printf("The difference of the two numbers is: ");
        printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
        break;
    case '*':
        printf("The product of the two numbers is: ");
        printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
        break;
    case '/':
        printf("The quotient of the two numbers is: ");
        printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        break;
    }

    return 0;
}