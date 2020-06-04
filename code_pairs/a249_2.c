#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **s,int index_1,int index_2)
{
    char *temp;
    temp=s[index_1];
    s[index_1]=s[index_2];
    s[index_2]=temp;
}
void reverse(char **s,int i,int size)
{
    int temp_i=i;
    int temp_size=size;
    int x=0;
    while ((temp_size-1)>temp_i)
    {
        swap(s,temp_i,(temp_size-1));
        ++temp_i;
        --temp_size;
    }
}
int next_permutation(int n, char **s)
{
	int index_k=-1;
	int index_l=-1;
	int i;
	for (i=0;n-1>i;++i)
    {
        if (strcmp(s[i],s[i+1])<0)
        {
            index_k=i;
        }
    }
    if (index_k==-1)
    {
        return 0;
    }
    for (i=index_k;n>i;++i)
    {
        if (strcmp(s[index_k],s[i])<0)
        {
            index_l=i;
        }
    }
    swap(s,index_k,index_l);
    reverse(s,index_k+1,n);
    return 1;

}
int main()
{
   char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; n>i ; ++i)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], n-1 == i ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; ++i)
		free(s[i]);
	free(s);
    return 0;
}
