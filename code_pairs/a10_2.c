#include <stdio.h>
#include <stdlib.h>
void merge(int *left,int *right,int *a,int nl,int nr)
{
    int j=0;
    int k=0;
    int i=0;
    while (j<nr && i<nl)
    {
        if (left[i]<=right[j])
        {
            a[k]=left[i];
            ++i;
        }
        else
        {
            a[k]=right[j];
            ++j;
        }
        ++k;
        
    }
    while (j<nr)
    {
        a[k]=right[j];
        k++;
        ++j;
    }
    while (i<nl)
    {
        a[k]=left[i];
        k++;
        i++;
    }
}
void mergesort(int *a,int n)
{
    if (n<2)
    {
        return;
    }
    int mid=n/2;
    int left[mid];
    int right[n-mid];
    int i;
    for (i=0;i<mid;++i)
    {
        left[i]=a[i];
    }
    for (i=mid;i<n;++i)
    {
        right[i-mid]=a[i];
    }
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,right,a,sizeof(left)/sizeof(left[0]),sizeof(right)/sizeof(right[0]));

}
int main()
{
    int a[]={8,7,6,5,4,3,2,1};
    mergesort(a,8);
    int i;
    for (i=0;i<8;++i)
    {
        printf("%d\n",a[i]);
    }
}