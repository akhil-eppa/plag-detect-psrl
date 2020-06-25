#include<stdio.h>
int main()
{
    int i,k,p,q,t,n,min,a;
    scanf("%d",&n);
    while(n--)
    {
    scanf("%d",&k);
    int arr[k];
    for(i=0;i<k;i++)
       {
            scanf("%d",&arr[i]);
       }
    for(p=0;p<k-1;p++)
        {
            for(q=0;q<k-p-1;q++)
            {
                if(arr[q]>arr[q+1])
                    {   t=arr[q];
                        arr[q]=arr[q+1];
                        arr[q+1]=t;
                    }
            }
        }
    min=arr[1]-arr[0];
    for(a=2;a<k;a++)
    {
        if(arr[a]-arr[a-1]<min)
            min=arr[a]-arr[a-1];
        else
            min=min;
    }
    printf("%d\n",min);
}
return 0;
}
