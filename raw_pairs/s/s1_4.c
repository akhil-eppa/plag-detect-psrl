#include <stdio.h>
int main() {
    char operator;  //operator takes the character values +, -, * or /
    float first, second; //first and second are the operands of type float
    
    //Taking input
    printf("ENTER AN OPERATOR: ");
    scanf("%c", &operator);
    printf("ENTER THE TWO SPACE-SEPARATED OPERANDS: ");
    scanf("%f %f", &first, &second);

    //Using switch case to do the required operation
    switch (operator) {
    case '+':
        printf("%.1f + %.1f = %.1f", first, second, first + second);
        break;
    case '-':
        printf("%.1f - %.1f = %.1f", first, second, first - second);
        break;
    case '*':
        printf("%.1f * %.1f = %.1f", first, second, first * second);
        break;
    case '/':
        printf("%.1f / %.1f = %.1f", first, second, first / second);
        break;
        // operator doesn't match any case constant
    default:
        printf("THE OPERATOR MUST BE +, -, * OR /");
    }
    return 0;
}