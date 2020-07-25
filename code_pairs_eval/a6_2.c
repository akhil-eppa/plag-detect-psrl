#include <stdio.h>
#include <stdlib.h>

//Function to swap 2 variables
void swap(int *z,int *t)
{
    int temp=*z;
    *z=*t;
    *t=temp;
}
int partition(int *ax,int start,int end)
{
    /*Pivot can be any random element of the array, but
    I have taken it to be the last element*/
    int pt=ax[end];
    int pi=start;
    int i;
    for (i=start;i<end;++i)
    {
        if (ax[i]<=pt)
        {
            swap(&ax[i],&ax[pi]);
            ++pi;
        }

    }
    swap(&ax[pi],&ax[end]);
    return pi;
}
void Qs(int *ax,int start,int end)
{
    if (start<end)
    {
        int pi=partition(ax,start,end);
        Qs(ax,start,pi-1);
        Qs(ax,pi+1,end);
    }
}
int main()
{
    int ax[10]={24,23,11,45,7,79,55,21,54,10};
    Qs(ax,0,9);
    int i;
    for (i=0;i<10;++i)
    {
        printf("%d\n",ax[i]);
    }
}