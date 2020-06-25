#include <stdio.h>

int main(void) {
	int testcases,i;
    scanf("%d",&testcases);
    for(i=0; i<testcases; i++)
    {
        long int N,j;
        int X,Y,K,flag=0;
        scanf("%d%d%d%ld",&X,&Y,&K,&N);
        int pi[N];
        int ci[N];
        for(j=0; j<N; j++)
        {
            scanf("%d%d",&pi[j],&ci[j]);
        }
        for(j=0; j<N; j++)
        {
            if(pi[j]>=(X-Y) && ci[j]<=K )
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("LuckyChef\n");
        else
          printf("UnluckyChef\n");
     
    }
	return 0;
}

