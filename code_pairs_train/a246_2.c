#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n],i,j,min,k,l;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        min=abs(a[0]-a[1]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                k=abs(a[i]-a[j]);
                if(min>k)
                min=k;
            }
        }
     
      
      printf("%d\n",min);
    }

return 0;    
}