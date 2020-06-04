#include<stdio.h>
int main(void)
{
    long int t,x,y,n,k,i,flag,p,c;
    scanf("%ld",&t);
    while(t--)
    {
        flag=0;
        scanf("%ld %ld %ld %ld",&x,&y,&k,&n);
        long int pagereq=x-y;
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld",&p,&c);
            if((p>=pagereq)&&(c<=k))
                flag=1;
            
        }
        if(flag)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
        
    }
    return 0;
}