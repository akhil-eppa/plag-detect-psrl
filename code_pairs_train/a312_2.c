#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,sum,t,i,j,k,l,s,f=0;
        scanf("%d%d",&n,&sum);
        int a[n];
        for(i=0,j=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t<=sum)
            {
                a[j]=t;
                j++;
            }
        }
        j=pow(2,j);

        for(i=1;i<j;i++)
        {
            for(k=i,l=0,s=0;k>0;k/=2,l++)
            {
                if(k&1)
                    s=s+a[l];
            }
            if(s==sum)
            {
                f=1;
                break;
            }
           // printf("%d\n",s);
        }
        if(f==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
