#include <stdio.h>
#include <stdlib.h>

//Function to swap 2 variables
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int *arra,int strt,int end)
{
    /*Pivot can be any random element of the array, but
    I have taken it to be the last element*/
    int pIndex=strt;
    int pivot=arra[end];
    int i;
    for (i=strt;i<end;++i)
    {
        if (arra[i]<=pivot)
        {
            swap(&arra[i],&arra[pIndex]);
            ++pIndex;
        }

    }
    swap(&arra[pIndex],&arra[end]);
    return pIndex;
}
void Quicksort(int *arra,int strt,int end)
{
    if (strt<end)
    {
        int pIndex=partition(arra,strt,end);
        Quicksort(arra,strt,pIndex-1);
        Quicksort(arra,pIndex+1,end);
    }
}
int main()
{
    int arra[10]={24,23,11,45,7,79,55,21,54,10};
    Quicksort(arra,0,9);
    int i;
    for (i=0;i<10;++i)
    {
        printf("%f\n",arra[i]);
    }
}