 //Comments are added in this file
#include <stdio.h>
     
int main()
{
    //All the variables used in the function are declared here.
    int a[100001] = {0}, i = 1, c, x, l, r, n;
    //'a' is an array which initially holds the value 0
    /*
        The main program is present in the following lines
        Two for loops are used which are not nested.
    */
    for (i = 1; i <= 100000; i++) { //This loop is run 100000 times.
        c = 1; //c is reset to 1
        x = i; // x is reset to i
        while (x > 0 && x % 5 == 0) {
            x /= 5; //x is divided by 5
            ++c; //c value is pre-incremented
        }
        a[i] = a[i-1] + c; //a[i] value is set
    }
    scanf("%d", &n); //Input is taken from the console for the value of n
    for (i = 0; i < n; i++) { //This for loop is run n times
        scanf("%d", &x); //Value of x is taken from stdin as input
        l = 0; //l value is reset to 0
        r = 50000; //r is set to 50000
        c = 100000; //c is set to 1000000
        while (l <= r) { //loop continues till left is leser than right
            if (x == a[c]) {
                printf("5\n%d %d %d %d %d\n", 5 * c, 5 * c + 1, 5 * c + 2, 5 * c + 3, 5 * c + 4); //Output is printed
                //break out of while loop after printing
                break;
            } else
            if (x < a[c]) {
                r = c - 1;
                c = (l + r) / 2;
            } else {
                l = c + 1;
                c = (l + r) / 2;
            }
        }
        //End of while loop
        if (l > r) printf("0\n"); //Add an extra zero
    }
    return 0; //end of execution
}
