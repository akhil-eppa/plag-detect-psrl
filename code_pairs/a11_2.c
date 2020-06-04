#include <stdio.h>
#include <stdlib.h>
void merge(double *left,double *right,double *a,double nl,double nr)
{
    double i=0;
    double j=0;
    double k=0;
    while (i<nl && j<nr)
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
    while (i<nl)
    {
        a[k]=left[i];
        k++;
        i++;
    }
    while (j<nr)
    {
        a[k]=right[j];
        k++;
        ++j;
    }
}
void mergesort(double *a,double n)
{
    if (n<2)
    {
        return;
    }
    double mid=n/2;
    double left[mid];
    double right[n-mid];
    double i;
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
double main()
{
    double a[]={8,7,6,5,4,3,2,1};
    mergesort(a,8);
    double i;
    for (i=0;i<8;++i)
    {
        printf("%f\n",a[i]);
    }
}