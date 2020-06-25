#include<stdio.h>
#include<string.h>

int main()
{
	int T, i, d;
	char M[27], s[101], u[27];
	scanf("%d %s",&T, M);
	d='A'-'a';
	for(i=0;M[i];i++)
		u[i]=M[i]+d;
	while(T--)
	{
		scanf("%s",s);
		for(i=0;s[i];i++)
		{
			if(s[i]>='a'&&s[i]<='z')
				putchar(M[s[i]-'a']);
			else if(s[i]>='A'&&s[i]<='Z')
				putchar(u[s[i]-'A']);
			else if(s[i]=='_') putchar(' ');
			else putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}