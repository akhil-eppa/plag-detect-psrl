#include <stdio.h>
#include <stdlib.h>

//Function to swap 2 variables
void swap(double *x,double *y)
{
    double temp=*x;
    *x=*y;
    *y=temp;
}
double partition(double *arr,double start,double end)
{
    /*Pivot can be any random element of the array, but
    I have taken it to be the last element*/
    double pivot=arr[end];
    double pIndex=start;
    double i;
    for (i=start;i<end;++i)
    {
        if (arr[i]<=pivot)
        {
            swap(&arr[i],&arr[pIndex]);
            ++pIndex;
        }

    }
    swap(&arr[pIndex],&arr[end]);
    return pIndex;
}
void Quicksort(double *arr,double start,double end)
{
    if (start<end)
    {
        double pIndex=partition(arr,start,end);
        Quicksort(arr,start,pIndex-1);
        Quicksort(arr,pIndex+1,end);
    }
}
int main()
{
    double arr[10]={24,23,11,45,7,79,55,21,54,10};
    Quicksort(arr,0,9);
    double i;
    for (i=0;i<10;++i)
    {
        printf("%f\n",arr[i]);
    }
}