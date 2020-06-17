#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	for(int i = 0; i < t; ++i) {
		int n,k,arr[100]={},b[105]={},c=0,d[102]={};
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			b[arr[i]]=arr[i];
		}
		int i=1;
		while(i<100) { if(b[i]!=0) { c++; d[c-1]=b[i]; }++i; }
		if(c>k) { printf("-1"); }
		else {
			printf("%d\n",n*k);
			while(n--) {
				for(int p=0;p<k;p++) {
					printf("%d ",d[p%c]);
				}
			} }
		printf("\n");
	}
	return 0;
}
