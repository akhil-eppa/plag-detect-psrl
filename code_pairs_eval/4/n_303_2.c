#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--){
		long i,j;
		long b[200005]={0};
		long a[200005]={0};
		long k=0,sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%ld",a+i);
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
		printf("%ld\n",sum);
	}
	return 0;
}
