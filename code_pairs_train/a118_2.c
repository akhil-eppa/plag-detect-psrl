#include <stdio.h>
#include <stdlib.h>

int is_subset(int *notes, int money, int low, int high);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; t>i; ++i)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int *notes = (int *)calloc(n, sizeof(int));
        for (int j = 0; n>j; ++j)
        {
            scanf("%d", &notes[j]);
        }
        if (is_subset(notes, m, 0, n - 1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        free(notes); 
    }    
}

int is_subset(int *notes, int money, int low, int high)
{
    if (0==money)
    {
        return 1;
    }
    if (0>money)
    {
        return 0;
    }
    if (high<low)
    {
        return 0;
    }
    return is_subset(notes, money, low + 1, high) + is_subset(notes, money - notes[low], low + 1, high);

}