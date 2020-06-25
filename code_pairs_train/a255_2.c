#include <stdio.h>

inline int input(){
    int a=0;
    char c;
    c=getchar_unlocked();
    while(c<33)
    {
        c=getchar_unlocked();
    }
    while(c>=33)
    {
        a=(a<<3)+(a<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return a;
};

int main(void) {
	
	int t, g, l, n, q, ans;
	t = input();
	while(t--){
	    g = input();
	    while(g--){
	        
	        l = input();
	        n = input();
	        q = input();
	        
	        if(n%2==0){
	            ans = n/2;
	            goto ab;
	        }
	        
	        if(l == 1){
	            
	            if(n%2==1){
	                if(q==1) 
	                    ans = n/2;
	                
	                if(q==2) 
	                    ans = n/2 + 1;
	            }
	        }
	        else{
	            
	            if(n%2==1){
	                if(q==1)
	                    ans = n/2 + 1;
	                if(q==2)
	                    ans = n/2;
	            }
	        }
	        
	        ab: printf("%d\n", ans);  
	    }
	}
	
	return 0;
}

