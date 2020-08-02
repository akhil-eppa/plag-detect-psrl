#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int t;
	long long n;
	int i,j;
	long long s;
	scanf("%lld%lld",&n,&s);
	if(s>=2*n)
	{
		printf("YES\n");
		i=0;
		while(i<n-1)
		{
			printf("2 ");
			++i;
		}
		printf("%lld\n%d\n",s-(n-1)*2,1);
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
