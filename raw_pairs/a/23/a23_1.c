#include <stdio.h>

int main(void) {
	int i,testcases;
    scanf("%d",&testcases);
    for(i=0; testcases>i; ++i)
    {
        int Y,K,X,flag=0;
        long int N,j;
        scanf("%d%d%d%ld",&X,&Y,&K,&N);
        int ci[N];
        int pi[N];
        for(j=0; N>j; ++j)
        {
            scanf("%d%d",&pi[j],&ci[j]);
        }
        for(j=0; N>j; ++j)
        {
            if((X-Y)<=pi[j] && K>=ci[j] )
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

