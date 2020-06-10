#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char **s,int i,int sze)
{
    int temp_i=i;
    int temp_size=sze;
    int x=0;
    while (temp_i<(temp_size-1))
    {
        swp(s,temp_i,(temp_size-1));
        temp_i++;
        temp_size--;
    }
}
void swp(char **s,int index_1,int index_2)
{
    char *temper;
    temper=s[index_1];
    s[index_1]=s[index_2];
    s[index_2]=temper;
}
int next_permutation(int n, char **s)
{
	int index_k=-1;
	int index_l=-1;
	int i;
	for (i=0;i<n-1;i++)
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
    for (i=index_k;i<n;i++)
    {
        if (strcmp(s[index_k],s[i])<0)
        {
            index_l=i;
        }
    }
    swp(s,index_k,index_l);
    reverse(s,index_k+1,n);
    return 1;

}
int main()
{
   char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
    return 0;
}
