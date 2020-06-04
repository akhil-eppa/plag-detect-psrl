#include<stdio.h>
#include<math.h>
int main()
{   int n1,i1,n,min,i,l1;
    scanf("%d",&n1);
    for(i1=0;i1<n1;i1++)
    {
        scanf("%d",&n);
        min=(n-1);
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                l1=((n/i)-i);
                
                if(l1<min)
                min=l1;
            }
        }
        printf("%d\n",min);
    }
}