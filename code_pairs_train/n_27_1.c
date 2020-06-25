#include<stdio.h>
#include <stdlib.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,k,b[10000]={0},c[10000]={0};
		scanf("%d%d",&n,&k);
		int i,sum=0,a[10000],j,l,mm;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[a[i]]++;
		}
		for(i=1;i<=n;i++)
			if(c[i]>0) sum++;
		for(i=1,j=1;i<=n;i++)
			if(c[a[i]]>0){
				b[j++]=a[i];
				c[a[i]]=0;
			}
		if(sum>k){
			printf("-1\n");
			continue;}
		if(sum<k){
			i=1;mm=k-sum;
			while(mm--){
				b[j++]=b[i++];
				if(i==sum)i=1;
			}
		}
		printf("%d\n",n*65);
		for(i=1,l=1;i<=n*65;l++,i++){
			if(l==j)l=1;
			printf("%d ",b[l]);
		}

		printf("\n");
	}
}
