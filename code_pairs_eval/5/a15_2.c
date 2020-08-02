#include <stdio.h>
#include <stdlib.h>
void merge(int *left_part,int *right_part,int *arr,int nl,int nr)
{
    int ij=0;
    int jk=0;
    int kl=0;
    while (ij<nl && jk<nr)
    {
        if (left_part[ij]<=right_part[jk])
        {
            arr[kl]=left_part[ij];
            ++ij;
        }
        else
        {
            arr[kl]=right_part[jk];
            ++jk;
        }
        ++kl;
        
    }
    while (ij<nl)
    {
        arr[kl]=left_part[ij];
        kl++;
        ij++;
    }
    while (jk<nr)
    {
        arr[kl]=right_part[jk];
        kl++;
        ++jk;
    }
}
void mergesort(int *arr,int num)
{
    if (num<2)
    {
        return;
    }
    int middle=num/2;
    int left_part[middle];
    int right_part[num-middle];
    int ij;
    for (ij=0;ij<middle;++ij)
    {
        left_part[ij]=arr[ij];
    }
    for (ij=middle;ij<num;++ij)
    {
        right_part[ij-middle]=arr[ij];
    }
    mergesort(left_part,middle);
    mergesort(right_part,num-middle);
    merge(left_part,right_part,arr,sizeof(left_part)/sizeof(left_part[0]),sizeof(right_part)/sizeof(right_part[0]));

}
int main()
{
    int arr[]={8,7,6,5,4,3,2,1};
    mergesort(arr,8);
    int ij;
    for (ij=0;ij<8;++ij)
    {
        printf("%d\num",arr[ij]);
    }
}