#include<stdio.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		char b[260];
		scanf("%d",&a);
		scanf("%s",b);
		int sum=0,i=0;
		if(a!=0)
		{
			while(b[i]!='\0')
			{
				sum=(sum*10+(b[i]-'0'))%a;
				i++;
			}
			a=gcd(a,sum);
			printf("%d\n",a);
		}
		else
			printf("%s\n",b);
	}
	return 0;
}