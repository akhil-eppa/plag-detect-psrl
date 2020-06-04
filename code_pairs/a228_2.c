#include <stdio.h>
#include <math.h>

int main(void){
	
	int t, n, m, i, j, sum=0, flag;
	scanf("%d", &t);
					
	while(t--){
		
        flag=0;
            
		//code for taking input
		scanf("%d%d", &n, &m);
		
		int A[n];

		for(i=0; i<n; i++){
			
			scanf("%d", &A[i]);
		}
		//end of taking input
		
		int B[n], k;
		int L=pow(2,n);
		for(i=0; i<L; i++){
		    
		    sum=0;
		    
		    for(j=0; j<n; j++){
		        if (i&(1<<j)) {
		            sum += A[j];
		        }
		    }
		    
		    if(sum==m){
		        flag=1;
		        break;
		    }
		    
		}
		
		if(flag==1){
		    printf("Yes\n");
		}else{
		    printf("No\n");
		}
	}
}