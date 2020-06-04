#include <stdio.h>

int main(void) {
	double testcases,i;
    scanf("%f",&testcases);
    for(i=0; i<testcases; i++)
    {
        double X,Y,K,flag=0;
        long double N,j;
        scanf("%f%f%f%ld",&X,&Y,&K,&N);
        double ci[N];
        double pi[N];
        for(j=0; j<N; j++)
        {
            scanf("%f%f",&pi[j],&ci[j]);
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

