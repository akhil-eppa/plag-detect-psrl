

#include<stdio.h>
int main()
{
    long int N;
    int G,T,I,Q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&G);
        while(G--)
        {
            scanf("%d%ld%d",&I,&N,&Q);
            if(N%2==0 || I==Q) 
                printf("%ld\n",N/2);
            else
                printf("%ld\n",N/2+1);

        }
    }
    return 0;
}