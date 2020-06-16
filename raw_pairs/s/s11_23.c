#include <stdio.h>
 
int main(){
	
	int n,k;
	int c=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
	    int id,e,w,r;
	    float h;
	    scanf("%d%d%d%f%d",&id,&e,&w,&h,&r);
	    
	 
	     if(2*w>r)
	     printf("%d %d\n",-1,-1);
	     else
	     printf("%d %d\n",e-10,i/k+1);
	    
	}
}
 
