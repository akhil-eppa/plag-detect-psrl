#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	long long var1;
	int i,var2;
	long long s;
	scanf("%lld%lld",&var1,&s);
	if(s>=2*var1)
	{
		printf("YES\n");
		for(i=0;i<var1-1;i++)
		{
			putchar('2');
			putchar(' ');
		}
		printf("%lld\n%d\n",s-(var1-1)*2,1);
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
