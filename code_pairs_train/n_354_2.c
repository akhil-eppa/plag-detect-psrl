#include <stdio.h>
#include <stdlib.h>

void update(int *arr, int n, int i, int v)
{
	while (i <= n)
	{
		arr[i] += v;
		i += i & -i;
	}
}
int sum(int *arr, int n, int i)
{
	int out = 0;
	for(;i > 0;)
	{
		out += arr[i];
		i -= i & -i;
	}
	return out;
}
int getKth(int *arr, int n, int k)
{
	int pow = 1 << 20, idx = 0;
	for (;pow > 0;pow/=2)
	{
		if (idx + pow <= n && arr[idx + pow] < k)
		{
			idx += pow;
			k -= arr[idx];
		}
	}
	return idx + 1;
}
int main(void)
{
	int n, q;
	scanf("%d %d", &n, &q);
	int *arr;
	arr = calloc(n + 1, sizeof(int));

	int i = 0;
	while (i < n)
	{
		int in;
		scanf("%d", &in);
		update(arr, n, in, 1);
		i++;
	}

	i=0;
	while(i < q)
	{
		int k;
		scanf("%d", &k);

		if (k > 0)
		{
			update(arr, n, k, 1);
		}
		else
		{
			update(arr, n, getKth(arr, n, -k), -1);
		}
		++i;
	}

	int out = getKth(arr, n, 1);
	if (sum(arr, n, n) == 0)
	{
		out = 0;
	}

	printf("%d\n", out);

	return 0;
}
