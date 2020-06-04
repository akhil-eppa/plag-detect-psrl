#include <stdio.h>
#include <stdlib.h>
int p=0,k,z;
int turn(int*,int,int);
int main()
{
    int a,n,i,j,y,l;
    int *arr;
    scanf("%d",&a);
    for(y=0;y<a;y++)
    {
        p=0;
        k=0;
        z=0;
        scanf("%d",&n);
       arr=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
            scanf("%d",&arr[j]);
        for(i=0;i<n;i++)
           l=turn(arr,n,i);
        printf("%d\n",l);

    }
    return 0;
}
int turn(int *arr,int n,int i)
{
    if(arr[i]%3==0)
       {
         p++;
       }
    else 
    {
        if(arr[i]%3==1)
           {
               k++;
           }
    else
        {
                z++;
        }
    }
    if(i==n-1)
    {
        if(p==n)
            return 0;
        if(k==1 && z==1)
            return (n-1);
        else
            return n;
    }
}
