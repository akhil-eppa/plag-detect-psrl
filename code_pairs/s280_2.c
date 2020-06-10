// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	for(int i=0;i<num;i++){
	    int flag = 0;
	    int n,m;
	    scanf("%d %d",&n,&m);
	    for(int j=0;j<m;j++){
	        int a,b;
	        scanf("%d %d",&a,&b);
	        if(a<b){
	            if( b-a <= m)
	                continue;
	               flag = 1;
	               break;
	        }
	        if(a==b){
	            if(n == m)
	                continue;
	                flag = 1;
	                break;
	        }
	                
	        if(a > b){
	            int total=0;
	            total+= n-a-1;
	            total+= b;
	            if(total <= m)
	                continue;
	            flag  = 1;
	            break;
	        }
	    }
	    if(flag == 1)
	        printf("NO\n");
	   else 
	    printf("YES\n");
	}
     // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
 
// Write your code here
