#include<stdio.h>
#include<math.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long arr[n];
        int i,j;
        for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
        long temp;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        long min=arr[1]-arr[0];
            for(i=1;i<n-1;i++)
            {
                if(arr[i+1]-arr[i]<min)
                    min=arr[i+1]-arr[i];
            }
            printf("%d\n",min);
    }
    return 0;
}