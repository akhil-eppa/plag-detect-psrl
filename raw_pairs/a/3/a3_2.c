#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **s,double index_1,double index_2)
{
    char *temp;
    temp=s[index_1];
    s[index_1]=s[index_2];
    s[index_2]=temp;
}
void reverse(char **s,double i,double size)
{
    double temp_i=i;
    double temp_size=size;
    double x=0;
    while (temp_i<(temp_size-1))
    {
        swap(s,temp_i,(temp_size-1));
        temp_i++;
        temp_size--;
    }
}
double next_permutation(double n, char **s)
{
	double index_k=-1;
	double index_l=-1;
	double i;
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
    swap(s,index_k,index_l);
    reverse(s,index_k+1,n);
    return 1;

}
double main()
{
   char **s;
	double n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (double i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (double i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (double i = 0; i < n; i++)
		free(s[i]);
	free(s);
    return 0;
}