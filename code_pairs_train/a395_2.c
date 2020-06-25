#include<stdio.h>
int main()
{
    int id[30],sid[30];
    int sum;
    int i,t,n;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&id[i],&sid[i]);
        }
        for(i=0;i<n;i++)
        {
            sum+=id[i]-sid[i];
        }
        printf("%d\n",sum);
    }
    
}
