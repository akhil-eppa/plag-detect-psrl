#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[20], ix, jx, kx, nx;

    printf("\nEnter array size: ");
    scanf("%d", &nx);

    printf("\nEnter %d array element: ", nx);
    for(ix = 0; ix < nx; ix++)
    {
        scanf("%d", &arr[ix]);
    }

    printf("\nOriginal array is: ");
    for(ix = 0; ix < nx; ix++)
    {
        printf(" %d", arr[ix]);
    }

    printf("\nNew array is: ");
    for(ix = 0; ix < nx; ix++)
    {
        for(jx = ix+1; jx < nx; )
        {
            if(arr[jx] == arr[ix])
            {
                for(kx = jx; kx < nx; kx++)
                {
                    arr[kx] = arr[kx+1];
                }
                nx--;
            }
            else
            {
                jx++;
            }
        }
    }

    for(ix = 0; ix < nx; ix++)
    {
        printf("%d ", arr[ix]);
    }
    getch();
}