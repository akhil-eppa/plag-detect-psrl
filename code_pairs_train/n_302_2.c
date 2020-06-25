#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--){
		int i,j;
		int b[200005]={0};
		int a[200005]={0};
		long long k=0,sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			b[i]=a[i]>0?1:0;
		}
		b[0]=2;
		for(i=1;i<=n;i++){
			if(b[i]==b[i-1]){
				k=a[i]>k?a[i]:k;
			}else{
				k=a[i];
				sum+=k;
			}
		}
		sum+=k;
		printf("%lld\n",sum);
	}
	return 0;
}
