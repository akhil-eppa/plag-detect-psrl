#include <stdio.h>

int main(void) {
    // your code goes here
    int T;
    scanf("%d",&T);
    while(T-->0 && T>=0 && T<=100)
    {
        int n;
        scanf("%d",&n);
        if(n>=1 && n<=100)
        {
        int i,w[n],sum=0,min=10001;
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            if(w[i]>=0 && w[i]<=10000)
            {
            if(w[i]<min)
            min=w[i];
            sum=sum+w[i];
            }
        }
        printf("%d\n",(sum-n*min));
        }
    }
    return 0;
}
