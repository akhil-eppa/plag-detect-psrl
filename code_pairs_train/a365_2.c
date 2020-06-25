#include<stdio.h>
int main(){
	int i,t,n,sum=0,min;
	
	int a[101];

	scanf("%d",&t);
	while(t--!=0){
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		min=a[0];
		for(i=0;i<n;i++){
			
			if(a[i]<min)
				min=a[i];
		}
		for(i=0;i<n;i++){
			sum=sum+(a[i]-min);
		}
		printf("%d\n",sum);
	}
return 0;
}