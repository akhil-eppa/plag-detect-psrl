#include <stdio.h>
int t, m, factorial, temp, count;
int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		scanf("%d\n", &m);
		for (factorial = 5; count < m; factorial += 5)
		{
			for (temp = factorial; temp >= 5 && temp % 5 == 0; temp /= 5)
			{
				count++;
			}
		}
		if (count == m)
		{
			printf("5\n%d %d %d %d %d\n", factorial - 5, factorial - 4,
				factorial - 3, factorial - 2, factorial - 1);
		}
		else
		{
			printf("0\n");
		}
		count = 0;
	}
	return 0;
}