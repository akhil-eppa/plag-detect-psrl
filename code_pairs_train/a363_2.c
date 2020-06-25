#include <stdio.h>
 int sho(int a[],int m){
    int min=a[0],i;
    for(i=1;i<m;i++){
        if(a[i]<=min){
            min=a[i];
        }
    }
    return min;
}

int main(void) {
	int t,w[100],n,i,k,s,s1;
	scanf("%d",&t);
	for(k=0;k<t;k++){
	    int sum=0;
	    scanf("%d",&n);
	    for(i=0;i<n;i++){
	        scanf("%d",&w[i]);
	       sum=sum+w[i]; 
	    }
	   s=sho(w,n); 
	   s1=sum-n*s;
	   printf("%d\n",s1);
	    
	}
	return 0;
}

