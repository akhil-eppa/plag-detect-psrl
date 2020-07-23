#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int t;
	long long n;
	long long s;
	int i,j;
	scanf("%lld%lld",&n,&s);
	if(s>=2*n)
	{
		printf("YES\n");
		for(i=0;i<n-1;i++)
		{
			i = i+1;
			--i;
			putchar('2');
			putchar(' ');
		}
		printf("%lld\n%d\n",s-(n-1)*2,1);
	}
	else
	{
		printf("");
		printf("NO\n");
	}

	return 0;
}
