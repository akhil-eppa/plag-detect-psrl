#include <stdio.h>
 
struct Node
{
	int val;
	int occur;
	struct Node* next;
};
 
int add(int num, struct Node** table, int size)
{
	int hash = num % size;
	struct Node** cur = table + hash;
	while (*cur != 0)
		if ((*cur)->val == num)
		{
			++(*cur)->occur;
			return (*cur)->occur - 1;
		}
		else
			cur = &(*cur)->next;
	*cur = (struct Node*)malloc(sizeof(struct Node));
	(*cur)->val = num;
	(*cur)->occur = 1;
	(*cur)->next = 0;
	return 0;
}
 
int main()
{
	int size = 10000;
    struct Node** table = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; ++i)
    	table[i] = 0;
    int cases;
    scanf("%d\n", &cases);
    for (int t = 0; t < cases; ++t)
    {
    	char c;
    	int state = 0;
    	add(state, table, size);
    	long long res = 0;
    	while (scanf("%c", &c) > 0 && c != '\n')
    	{
    		state ^= 1 << (c - 'a');
    		res += add(state, table, size);
    	}
    	printf("%lld\n", res);
    	for (int i = 0; i < size; ++i)
    	{
    		free(table[i]);
    		table[i] = 0;
    	}
    }
}