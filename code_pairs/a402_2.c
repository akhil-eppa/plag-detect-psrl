#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t, *root;
    scanf("%d",&t);
    root = (int*) calloc(sizeof(int),t);
    for(int one=0;one<t;one++)
    {
        int n;
        scanf("%d",&n);
        int *ids = (int*) calloc(sizeof(int),n), *sums = (int*) calloc(sizeof(int),n);
        for(int two=0;two<n;two++)
        {
            scanf("%d %d",&ids[two],&sums[two]);
        }
        for(int two=0;two<n;two++)
        {
            root[one] += ids[two] - sums[two];
        }
    }
    for(int one=0;one<t;one++)
    {
        printf("%d\n",root[one]);
    }
    return 0;
}
