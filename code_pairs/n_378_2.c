#include<stdio.h>
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int tmp1 = n-(k-1);
		int tmp2 = n-(k-1)*2;
		if(tmp1>0&&tmp1%2==1){
			printf("YES\n");
			for(int j=0;j<k-1;j++)
				printf("1 ");
			printf("%d\n",tmp1);
			continue;
		}
		if(tmp2>0&&tmp2%2==0){
			printf("YES\n");
			for(int j=0;j<k-1;j++)
				printf("2 ");
			printf("%d\n",tmp2);
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
