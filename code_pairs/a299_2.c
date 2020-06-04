#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t>0){
	    int n,k,temp;
	    scanf("%d%d",&n,&k); 
	    int a[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&a[i]);
	    } 
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[i]>a[j]){
	                temp=a[i];
	                a[i]=a[j];
	                a[j]=temp;
	            }
	        }
	    }  
	    int sum=0,sum1=0,d=0,x=0,c=0;
	    for(int i=0;i<n;i++){
	        x=x+a[i];
	    } 
	    for(int i=0;i<k;i++){
	        sum=sum+a[i];
	    } 
	    for(int i=0;i<n-k;i++){
	        sum1=sum1+a[i];
	    }  
	   // printf("%d %d",sum,sum1);
	    if(sum<=sum1){
	        d=sum;
	    } 
	    else{
	        d=sum1;
	    } 
	  //  printf("%d ",x);
	    c=x-2*d;
	    printf("%d\n",c);
	    t--;
	}
	return 0;
}

