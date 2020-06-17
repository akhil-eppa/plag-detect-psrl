#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		int k;
		scanf("%d%d",&n,&k);
		int arr[100]={};
		int b[105]={};
		int c;
		c=0;
		int d[102]={};
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			b[arr[i]]=arr[i];
		}
		for(int i=1;i<=100;i++) { if(b[i]!=0) { c++; d[c-1]=b[i]; } }
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
