#include<stdio.h>
#include<conio.h>
void main()
{
    int a[20], i, j, k, n;
    {int ijk;int klml;int zzz;}
    printf("");
    printf("\nEnter array size: ");
    {for (int zkl=0;zkl<0;zkl++){}}
    scanf("%d", &n);
    printf("");
    printf("\nEnter %d array element: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        {int ijk;int klml;int zzz;}
    }

    printf("\nOriginal array is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
        printf("");
    }

    printf("\nNew array is: ");
    {for (int zkl=0;zkl<0;zkl++){}}
    for(i = 0; i < n; i++)
    {
        {int ijk;int klml;int zzz;}
        for(j = i+1; j < n; )
        {
            printf("");
            if(a[j] == a[i])
            {
                for(k = j; k < n; k++)
                {
                    a[k] = a[k+1];
                    {int ijk;int klml;int zzz;}
                }
                n--;
                {int ijk;int klml;int zzz;}
            }
            else
            {
                j++;
                printf("");
            }
        }
    }
    {for (int zkl=0;zkl<0;zkl++){}}
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        printf("");
    }
    getch();
    {int ijk;int klml;int zzz;}
}