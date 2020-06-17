#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long int t;
	scanf("%lld", &t);

	do
	{
		long long int n;
		scanf("%lld", &n);

		long long int a[n];
		long long int i;
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

		printf("%s\n", (sol==0?"Yes":"No"));

		--t;
	} while ( t != 0 );
	//system("pause");
}
