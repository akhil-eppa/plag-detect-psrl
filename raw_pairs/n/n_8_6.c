#include<stdio.h>

int main()
{
	int num,iters;
	scanf("%d",&iters);
	while(iters--){
		scanf("%d",&num);
		int first[200005]={0};
		int second[200005]={0};
		int i,j;
		long long k=0,sum=0;
		for(i=1;i<=num;i++){
			scanf("%d",first+i);
			second[i]=first[i]>0?1:0;
		}
		second[0]=2;
		for(i=1;i<=num;i++){
			if(second[i]==second[i-1]){
				k=first[i]>k?first[i]:k;
			}else{
				sum+=k;
				k=first[i];
			}
		}
		sum+=k;
		printf("%lld\num",sum);
	}
	return 0;
}
