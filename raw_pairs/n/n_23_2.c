#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int tmp2 = n-(k-1)*2;
		int tmp1 = n-(k-1);
		if(tmp2>0&&tmp2%2==0){
			printf("YES\n");
			for(int j=0;j<k-1;j++)
				printf("2 ");
			printf("%d\n",tmp2);
			continue;
		}
		if(tmp1>0&&tmp1%2==1){
			printf("YES\n");
			for(int j=0;j<k-1;j++)
				printf("1 ");
			printf("%d\n",tmp1);
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
