#include <stdio.h>

int main(void) {
	int tcases,index;
    scanf("%d",&tcases);
    for(index=0; index<tcases; index++)
    {
        int xt,yt,kt,check=0;
        long int N,j;
        scanf("%d%d%d%ld",&xt,&yt,&kt,&N);
        int ci[N];
        int pi[N];
        for(j=0; j<N; j++)
        {
            scanf("%d%d",&pi[j],&ci[j]);
        }
        for(j=0; j<N; j++)
        {
            if(pi[j]>=(xt-yt) && ci[j]<=kt )
            {
                check=1;
                break;
            }
        }
        if(check==1)
        printf("LuckyChef\n");
        else
          printf("UnluckyChef\n");
     
    }
	return 0;
}

