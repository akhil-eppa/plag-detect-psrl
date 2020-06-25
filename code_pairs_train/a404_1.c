#include<stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int id[50];
        int sum[50];
        int n,i;
        int cal=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&id[i],&sum[i]);
        for(i=0;i<n;i++)
            cal-=sum[i];
        for(i=0;i<n;i++)
            cal+=id[i];
        printf("%d\n",cal);
    }
    return 0;
}
        