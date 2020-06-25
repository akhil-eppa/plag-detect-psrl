#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t-->0){
	     int i,n,ans = 0;
	     int sum[50],node[50];
	     scanf("%d",&n);
	     for(i=0;i<n;i++){
	          scanf("%d%d",&node[i],&sum[i]);
	     }
	     for(i=0;i<n;i++){
	          ans = ans + node[i] - sum[i];
	     }
	     printf("%d\n",ans);
	}
	return 0;
}

