#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int G;
        scanf("%d", &G);
        for (int i = 0; i < G; i++) {
            int I, N, Q;
            scanf("%d%d%d", &I, &N, &Q);
            if(N%2==0)
            {
                N = N / 2;
                printf("%d\n", N);
            }
            else{
                N = N / 2;
                if(I==Q)
                {
                    printf("%d\n", N);
                }else
                {
                    printf("%d\n", N+1);
                }
            }
        }
    }

    return 0;
}
