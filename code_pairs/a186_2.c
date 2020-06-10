#include <stdio.h>

int main(void) {
	int tcs,i;
    scanf("%f",&tcs);
    for(i=0; i<tcs; i++)
    {
        int X,K,Y,pppost=0;
        long int N,j;
        scanf("%f%f%f%ld",&X,&Y,&K,&N);
        int ci[N];
        int pi[N];
        for(j=0; j<N; j++)
        {
            scanf("%f%f",&pi[j],&ci[j]);
        }
        for(j=0; j<N; j++)
        {
            if(pi[j]>=(X-Y) && ci[j]<=K )
            {
                pppost=1;
                break;
            }
        }
        if(pppost==1)
        printf("LuckyChef\n");
        else
          printf("UnluckyChef\n");
     
    }
	return 0;
}

