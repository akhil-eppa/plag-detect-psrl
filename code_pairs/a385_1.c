/*
    Autor: Humberto Gonzalez Sanchez 
    Matricula: A00822594
    Fecha: 14/05/2020
    
    MARBLES
    Rohit dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. 
    There are marbles of k different colors. 
    From each color there are also infinitely many marbles. Rohit wants to have at least one marble of each color, 
    but still there are a lot of possibilities for his selection. 
    In his effort to make a decision he wakes up. Now he asks you how many possibilities for his selection he would have had. 
    Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.
*/

#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a>b?b:a)
int main()
{
    int tCases, n, k, i, divisor, mul;
    unsigned long long int result;
    scanf("%d", &tCases);
    while(tCases--)
    {
        scanf("%d%d", &n, &k);
        result = 1LL;

        if (n < k) {
            result = 0;
        }
        else if (n==k) {
            result = 1;
        }
        else {
            n = n - 1;
            k = k - 1;
            k = min((n - k), k);
            divisor = 1;
            mul = n;
            while (divisor <= k) {
                result = (result * mul--) / (divisor++);
            }

        }
        printf("%llu\n", result);
    }
    return 0;

}