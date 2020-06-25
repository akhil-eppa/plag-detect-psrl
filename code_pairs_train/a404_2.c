#include<stdio.h>
#include<stdlib.h>
main(){
	int t,n,x=0,i,id,sid;
	scanf("%d",&t);
	while(t>0){
		x=0;
		scanf("%d",&n);
		//int *id=(int *)malloc(sizeof(int)*n);
		//int *sid=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++){
			scanf("%d",&id);
			scanf("%d",&sid);
			x+=id-sid;
		}
		printf("%d\n",x);
		t--;
	}
	return 0;
}
