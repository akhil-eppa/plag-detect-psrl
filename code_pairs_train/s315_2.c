#include<stdio.h>
long int n = 0, count = 0;
long int max(long int a, long int b)
{
	return (a > b)? a : b;
}
long int min(long int a, long int b)
{
	return (a < b)? a : b;
}
int main()
{
	long int t;
	scanf("%ld", &t);
	while(t--)
	{
        count = 0;
		scanf("%ld", &n);
        long int a[n + 1], pref[n + 2], suf[n + 2];
        a[0] = 0, pref[0] = 0, suf[0] = 0;
		for(int i = 1;i <= n; i++)
		{
			scanf("%ld", &a[i]);
			pref[i]= max(pref[i-1], a[i]);
		}
		suf[n+1]=1e9;
		for(int i = n;i >= 1; i--)
			suf[i]=min(suf[i+1], a[i]);
		for(int i = 1;i <= n-1; i++)
		{
			if(pref[i] < suf[i+1])
				count++;
		}
		if(count % 2)
			printf("Jeel\n");
		else
			printf("Ashish\n");
	}
	return 0;
}