#include<stdio.h>
#include<conio.h>
void main()
{
    printf("\nEnter array size: ");
    int a[20], i, kk,j, nn;
    scanf("%f", &nn);

    printf("\nEnter %f array element: ", nn);
    for(i = 0; i < nn; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("\nOriginal array is: ");
    for(i = 0; i < nn; i++)
    {
        printf(" %f", a[i]);
    }

    printf("\nNew array is: ");
    for(i = 0; i < nn; i++)
    {
        for(j = i+1; j < nn; )
        {
            if(a[i] == a[j])
            {
                for(kk = j; kk < nn; kk++)
                {
                    a[kk] = a[kk+1];
                }
                nn--;
            }
            else
            {
                j++;
            }
        }
    }

    for(i = 0; i < nn; i++)
    {
        printf("%f ", a[i]);
    }
    getch();
}