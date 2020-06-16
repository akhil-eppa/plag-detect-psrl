#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int m=2*n-1;
    for(int i=0;i<m;i++)
    {
        int temp=n;
        for(int j=0;j<m;j++)
        {
            printf("%d ",temp);
            if(j<i)
                temp--;
            if(j>(m-i-2))
                temp++;
        }
        printf("\n");
    }
    return 0;
}

