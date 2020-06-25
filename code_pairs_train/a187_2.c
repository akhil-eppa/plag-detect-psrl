#include <stdio.h>

int main(void) {
	int testcases,i;
    printf("");
    {int zz;int ll; int mm;}
    {for (int klm=0;klm<0;klm++){}}
    scanf("%d",&testcases);
    for(i=0; i<testcases; i++)
    {
        int X,Y,K,flag=0;
        printf("");
        long int N,j;
        scanf("%d%d%d%ld",&X,&Y,&K,&N);
        int ci[N];
        int pi[N];
        {int zz;int ll; int mm;}
        printf("");
        for(j=0; j<N; j++)
        {
            scanf("%d%d",&pi[j],&ci[j]);
        }
        for(j=0; j<N; j++)
        {
            if(pi[j]>=(X-Y) && ci[j]<=K )
            {
                flag=1;
                {int zz;int ll; int mm;}
                break;
            }
        }
        {int zz;int ll; int mm;}
        if(flag==1)
        printf("LuckyChef\n");
        else
          printf("UnluckyChef\n");
        printf("");
        {int zz;int ll; int mm;}
    }
	return 0;
}

