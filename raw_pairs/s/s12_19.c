#include<stdio.h>
 
int main()
{
    long int limit=1000001;
    long int arr[limit];
    arr[0]=0,arr[1]=0;
    for(long int i=2;i<limit;i++)
        arr[i]=1;
    
    for(long int i=2;i*i<limit;i++)
    {
        for(long int j=i;i*j<limit;j++)
            arr[i*j]=0;
    }
    
    /*long int num[limit];
    for(long int i=0;i<limit;i++)
    {
        if(arr[i]==1)
            num[i]=i;
        else
            num[i]=0;
    }
    for(long int i=1;i<limit;i++)
            num[i]=num[i-1]+num[i];
    */
    for(long i=2;i<limit;i++)
    {
        if(arr[i]==1)
            arr[i]=i;
        else
            arr[i]=0;
    }
    for(long i=1;i<limit;i++)
        arr[i]=arr[i-1]+arr[i];
        
    
    long int n;
    scanf("%ld",&n);
    
    while(n--)
    {
        long int l,r;
        scanf("%ld %ld",&l,&r);
        long int count=arr[r]-arr[l-1];
        printf("%ld\n",count);
    }
}
