#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int t;
	long n;
	int i,j;
	long s;
	scanf("%ld%ld",&n,&s);
	if(s>=2*n)
	{
		printf("YES\n");
		for(i=0;i<n-1;i++)
		{
			putchar('2');
			putchar(' ');
		}
		printf("%ld\n%d\n",s-(n-1)*2,1);
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}