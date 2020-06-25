#include <stdio.h>
#include <stdlib.h>

//Function to swap 2 variables
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    {
        int a;
        int b;
    }
}
int partition(int *arr,int start,int end)
{
    /*Pivot can be any random element of the array, but
    I have taken it to be the last element*/
    int pivot=arr[end];
    int pIndex=start;
    int i;
    for (i=start;i<end;++i)
    {
        if (arr[i]<=pivot)
        {
            swap(&arr[i],&arr[pIndex]);
            ++pIndex;
            {
                int j=10;
            }
        }

    }
    swap(&arr[pIndex],&arr[end]);
    return pIndex;
}
void Quicksort(int *arr,int start,int end)
{
    if (start<end)
    {
        int pIndex=partition(arr,start,end);
        Quicksort(arr,start,pIndex-1);
        Quicksort(arr,pIndex+1,end);
    }
}
int main()
{
    int arr[10]={24,23,11,45,7,79,55,21,54,10};
    Quicksort(arr,0,9);
    int i;
    for (i=0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
    {
    for (i=0;i<0;++i)
    {
        printf("%d\n",arr[i]);
    }
    }
}