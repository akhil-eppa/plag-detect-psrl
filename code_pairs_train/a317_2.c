#include <stdio.h>
#include <string.h>
#define N 255

int main()
{
	int T, A;
	char B[N];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %s", &A, B);
		if (A==0)
		{

			puts(B);
			continue;
		}
		if (B[0]=='0')
		{
			printf("%d\n", A);
			continue;
		}

		int len=strlen(B);
		int sum=0;
		for (int i = 0; i < len; i++)
		{
			sum=sum*10+B[i]-'0';
			sum%=A;
			/*printf("%c__",B[i]);
			printf("%d ",A);
			printf("%d",sum);

			printf("\n");*/

		}
		while (A)
		{
			int p=A;
			A=sum%A;
			sum=p;
			/*printf("%d__",A);
			printf("%d",sum);
			printf("\n");*/
		}
		printf("%d\n", sum);
	}
	return 0;
}
