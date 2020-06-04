#include <stdio.h>
#include <stdlib.h>
void merge(int *left,int *right,int *a,int nl,int nr)
{
    int i=0;
    int j=0;
    int k=0;
    while (j<nr && i<nl)
    {
        if (right[j]>=left[i])
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
    while (n1>i)
    {
        a[k]=left[i];
        k++;
        i++;
    }
    while (nr>j)
    {
        a[k]=right[j];
        k++;
        ++j;
    }
}
void mergesort(int *a,int n)
{
    if (2>n)
    {
        return;
    }
    int mid=n/2;
    int left[mid];
    int right[n-mid];
    int i;
    for (i=0;mid>i;i++)
    {
        left[i]=a[i];
    }
    for (i=mid;n>i;i++)
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
    for (i=0;8>i;i++)
    {
        printf("%d\n",a[i]);
    }
}