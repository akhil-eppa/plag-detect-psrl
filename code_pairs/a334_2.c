#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void) {
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    long long int n,j,l;
	    scanf("%lld",&n);
	    for(j=1;j<=(sqrt(n));j++){
	        if(n%j==0){
	            l = j;
	        }
	    }
	    printf("%d\n",(n/l)-l);
	}
	return 0;
}

