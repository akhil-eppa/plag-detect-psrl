#include<stdio.h>
#include<conio.h>
void main()
{
    double a[20], i, j, k, n;
    clrscr();

    printf("\nEnter array size: ");
    scanf("%f", &n);

    printf("\nEnter %f array element: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("\nOriginal array is: ");
    for(i = 0; i < n; i++)
    {
        printf(" %f", a[i]);
    }

    printf("\nNew array is: ");
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; )
        {
            if(a[j] == a[i])
            {
                for(k = j; k < n; k++)
                {
                    a[k] = a[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%f ", a[i]);
    }
    getch();
}