#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int s=0;
    while(n!=0)
    {
        s+=n%10;
        n=n/10;
    }
    printf("%d",s);
    return 0;
}

