#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
int main()
{
    int iter,max,k;
    scanf("%d%d", &max,&k);
    if(k<2*max)printf("NO");
    else{
        printf("YES\n");
        for(iter=1;iter<max;iter++){
            putchar('1');
            putchar(' ');
        }
        //if(max%2==0)printf("1 ");
        printf("%d\n%d", k-max+1,max);
    }
    return 0;
}
