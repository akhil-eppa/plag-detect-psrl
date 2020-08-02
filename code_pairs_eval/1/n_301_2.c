#include<stdio.h>

int main()
{
	int n;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[200005]={0};
		int b[200005]={0};
		int i;
		int j;
		long long k=0;
		long long sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			b[i]=a[i]>0?1:0;
		}
		b[0]=2;
		for(i=1;i<=n;i++){
			if(b[i]==b[i-1]){
				k=a[i]>k?a[i]:k;
			}else{
				sum+=k;
				k=a[i];
			}
		}
		sum+=k;
		printf("%lld\n",sum);
	}
	return 0;
}
