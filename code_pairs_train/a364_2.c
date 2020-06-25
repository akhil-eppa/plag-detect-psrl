#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,i;
	    scanf("%d",&n);
	    int a[n];
	    int sum,min;
	    sum=0;
	    min=10001;
	    for(i=0;i<n;i++){
	        scanf("%d",&a[i]);
	    }
	    for(i=0;i<n;i++){
	        sum+=a[i];
	        if(a[i]<min){
	            min=a[i];
	        }
	    }
	    printf("%d\n",sum-(min*n));
	}
	return 0;
}

