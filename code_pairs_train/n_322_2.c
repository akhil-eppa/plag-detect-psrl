#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,m,n,t,sum,k,det;
    scanf("%d%d", &n,&k);
    char *ans = (k<2*n)?"NO":"YES";
    printf("%s\n", ans);
    if(k>=2*n) {
        for(j=1;j<n;j++){
            putchar('1');
            putchar(' ');
        }
        //if(n%2==0)printf("1 ");
        printf("%d\n%d", k-n+1,n);
    }
    return 0;
}