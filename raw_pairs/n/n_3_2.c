#include <stdlib.h>
#include <stdio.h>

int main()
{
	long long int t;
	long long int n;
	long long int a[n];
	long long int i;
	scanf("%lld", &t);

	do
	{
		scanf("%lld", &n);

		for ( i = 0; i < n; ++i )
		{
			scanf("%lld", &a[i]);
		}

		long long int sol = 0;
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
