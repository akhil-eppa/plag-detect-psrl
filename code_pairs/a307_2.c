
#include <stdio.h>

int main()
{
    int t,n,k,ch,sn;
    scanf("%d",&t);
    while(t--)
    {
        ch=0,sn=0;
        scanf("%d %d",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)
           scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        if(n-k>k)
        {
          for(int i=0;i<k;i++)
            sn=sn+a[i];
          for(int i=k;i<n;i++)
            ch=ch+a[i];
        }
        else
        {
          for(int i=0;i<n-k;i++)
            sn=sn+a[i];
          for(int i=n-k;i<n;i++)
            ch=ch+a[i];
        }
        printf("\n%d",ch-sn);
    }
    return 0;
}