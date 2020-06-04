#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
      int T, i, N, K, a[106], sum1, sum2;
    scanf("%d", &T);
    while(T--)
    {
        sum1=0;
        sum2=0;
        scanf("%d %d", &N, &K);
        for(i=0;i<N;i++)
        {
            scanf("%d", &a[i]);
        }
        qsort(a,N,sizeof(int),cmp);
        if(K>N/2)
            K=N-K;
        for(i=0;i<K;i++)
            sum1+=a[i];
        for(i=K;i<N;i++)
            sum2+=a[i];
        printf("%d\n", sum2-sum1);
    }
     }
     
     


