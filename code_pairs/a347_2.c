#include <stdio.h>
int main(void) {
	int testcases,i,j,n;
    scanf("%d",&testcases);
    for(j=0; j<testcases; j++)
    {
        scanf("%d",&n);
        int cars[n];
        int count=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&cars[i]);
        }
        for(i=0; i<n-1; i++)
        {
            if(cars[i]<cars[i+1])
            {
                cars[i+1]=cars[i];
                count++;
            }
        }
        printf("\n%d\n",n-count);
    }
	return 0;
}

