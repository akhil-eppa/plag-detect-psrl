#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t>0){
	    int n,temp;
	    scanf("%d",&n);
	    long long int a[n];
	    for(int i=0;i<n;i++){
	        scanf("%lld",&a[i]);
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
	    long long int b[n-1],l=0;
	    for(int i=1;i<n;i++){
	        b[l]=a[i]-a[i-1];
	        l++;
	    } 
	    long long int min=b[0];
	    for(int i=0;i<n;i++){
	        if(b[i]<min){
	            min=b[i];
	        }
	    } 
	    printf("%lld\n",min); 
	    t--;
	} 
	return 0;
}

