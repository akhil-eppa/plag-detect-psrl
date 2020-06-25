#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
	    int n;
	    scanf("%d",&n);
	    int id,child;
	    int tid=0,tchild=0;
	    for(int j=0;j<n;j++){
	        scanf("%d%d",&id,&child);
	        tid+=id;
	        tchild+=child;
	    }
	    printf("%d\n",tid-tchild);
	}
	return 0;
}

