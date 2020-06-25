#include <stdio.h>
int main()
{
	int T;
	long long nCr, n, r;

	scanf("%d", &T);

	while(T--)
    {
        scanf("%lld %lld", &n, &r);

        n = n - 1;
        r = r - 1;

        nCr = 1;
        if(r > (n / 2))
            r = n - r;

        for(int i = 0; i < r; i++)
        {
            nCr = nCr * (n - i);
            nCr = nCr / (i + 1);
        }

        printf("%lld\n", nCr);
    }


	return 0;
}
