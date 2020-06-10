#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **srr,int i_1,int i_2)
{
    char *temperoray;
    temperoray=srr[i_1];
    srr[i_1]=srr[i_2];
    srr[i_2]=temperoray;
}
void reverse(char **srr,int i,int size)
{
    int temper_i=i;
    int temp_sz=size;
    int x=0;
    while (temper_i<(temp_sz-1))
    {
        swap(srr,temper_i,(temp_sz-1));
        temper_i++;
        temp_sz--;
    }
}
int next_permutation(int num, char **srr)
{
	int i_k=-1;
	int i_l=-1;
	int i;
	for (i=0;i<num-1;i++)
    {
        if (strcmp(srr[i],srr[i+1])<0)
        {
            i_k=i;
        }
    }
    if (i_k==-1)
    {
        return 0;
    }
    for (i=i_k;i<num;i++)
    {
        if (strcmp(srr[i_k],srr[i])<0)
        {
            i_l=i;
        }
    }
    swap(srr,i_k,i_l);
    reverse(srr,i_k+1,num);
    return 1;

}
int main()
{
   char **srr;
	int num;
	scanf("%d", &num);
	srr = calloc(num, sizeof(char*));
	for (int i = 0; i < num; i++)
	{
		srr[i] = calloc(11, sizeof(char));
		scanf("%srr", srr[i]);
	}
	do
	{
		for (int i = 0; i < num; i++)
			printf("%srr%c", srr[i], i == num - 1 ? '\n' : ' ');
	} while (next_permutation(num, srr));
	for (int i = 0; i < num; i++)
		free(srr[i]);
	free(srr);
    return 0;
}
