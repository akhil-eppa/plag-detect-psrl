#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int t;
	scanf("%ld", &t);

	do
	{
		long int n;
		scanf("%ld", &n);

		long int a[n];
		long int i;
		for ( i = 0; i < n; ++i )
		{
			scanf("%ld", &a[i]);
		}

		long int sol = 0;
		for ( i = 0; i < n-1; ++i )
		{
			if ( a[i]+1 < a[i+1] )
			{
				sol = 1;
			}
		}

		if ( sol == 0 )
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		--t;
	} while ( t != 0 );
	//system("pause");
}
