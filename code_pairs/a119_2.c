#include <stdio.h>
#include <stdlib.h>

int is_subset(int *notesxxx, int mny, int low, int high);

int main()
{
    int ttx;
    scanf("%d", &ttx);
    for (int i = 0; ttx>i; ++i)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int *notesxxx = (int *)calloc(n, sizeof(int));
        for (int j = 0; n>j; ++j)
        {
            scanf("%d", &notesxxx[j]);
        }
        if (is_subset(notesxxx, m, 0, n - 1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        free(notesxxx); 
    }    
}

int is_subset(int *notesxxx, int mny, int low, int high)
{
    if (0==mny)
    {
        return 1;
    }
    if (0>mny)
    {
        return 0;
    }
    if (high<low)
    {
        return 0;
    }
    return is_subset(notesxxx, mny, low + 1, high) + is_subset(notesxxx, mny - notesxxx[low], low + 1, high);

}