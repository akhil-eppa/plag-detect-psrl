#include <stdio.h>

int main(void) {
	int testcases,i;
    scanf("%d",&testcases);
    i=0;
    while (i<testcases)
    {
        int X,Y,K,flag=0;
        long int N,j;
        scanf("%d%d%d%ld",&X,&Y,&K,&N);
        int ci[N];
        int pi[N];
        j=0;
        while (j<N)
        {
            scanf("%d%d",&pi[j],&ci[j]);
            j++;
        }
        j=0;
        while (j<N)
        {
            if(pi[j]>=(X-Y) && ci[j]<=K )
            {
                flag=1;
                break;
            }
            j++;
        }
        if(flag==1)
        printf("LuckyChef\n");
        else
          printf("UnluckyChef\n");
        i++;
     
    }
	return 0;
}

