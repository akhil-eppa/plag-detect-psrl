#include <stdio.h>
#define max 1000

int main()
{
    int T, X, Y, N, K;
    int P[max], C[max];
    int i;

    scanf("%d",&T);
    while(T--)
    {
        int flag = 0;
        scanf("%d %d %d %d",&X,&Y,&K,&N);
        for(i=1;i<=N;i++)
        {
            scanf("%d %d",&P[i],&C[i]);
        }

        for(i=1;i<=N;i++)
        {
            if((P[i]>=(X-Y))&&(C[i]<=K)&&flag==0)
            {
                printf("LuckyChef\n"); 
                flag = 1;           
            }            
        }
        
        if(flag==0)  printf("UnluckyChef\n");
    }

    return 0;
}