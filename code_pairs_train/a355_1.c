

#include <stdio.h>

int main(void)
{
	int t;
	scanf("%i", &t);
	
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%i", &n);
		
		int max[n], speed, cars = 0;
		for(int j = 0; j < n; j++)
		{
			scanf("%i", &max[j]);
			if(j == 0)
				speed = max[j];
			if(speed >= max[j])
				cars++;
			if(max[j] < speed)
				speed = max[j];
		}
		printf("%i\n", cars);
	}
}