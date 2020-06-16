#include<stdio.h>
#include<conio.h>
void main()
{
    int a[20], i, j, k, n;
    clrscr();

    printf("\nEnter array size: ");
    scanf("%d", &n);

    printf("\nEnter %d array element: ", n);
    i=0;
    while (i < n)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("\nOriginal array is: ");
    i=0;
    while (i < n)
    {
        printf(" %d", a[i]);
        i++;
    }

    printf("\nNew array is: ");
    i=0;
    while (i < n)
    {
        j=i+1;
        while (j < n)
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
        i++;
    }
    i=0;
    while (i < n)
    {
        printf("%d ", a[i]);
        i++;
    }
    getch();
}