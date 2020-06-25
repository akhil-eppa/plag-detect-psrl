#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[2000];
    scanf("%s",s);
    int n[10];
    for(int i=0;i<10;i++)
        n[i] = 0;
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case '0': n[0]++;
                    break;
            case '1': n[1]++;
                    break;
            case '2': n[2]++;
                    break;
            case '3': n[3]++;
                    break;
            case '4': n[4]++;
                    break;
            case '5': n[5]++;
                    break;
            case '6': n[6]++;
                    break;
            case '7': n[7]++;
                    break;
            case '8': n[8]++;
                    break;
            case '9': n[9]++;
                    break;
        }
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ", n[i]);
    }
    return 0;
}
