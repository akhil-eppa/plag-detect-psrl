#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b){
    int f = *((int *)a);
    int s = *((int *)b);
    return (f>s) - (f<s);
}

inline int input(){
    int a=0;
    char c;
    c=getchar_unlocked();
    while(c<33){
        c=getchar_unlocked();
    }
    while(c>=33){
        a=(a<<3)+(a<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return a;
};

int main(void) {
	
	int t, n, k, arr[101], i, grp2, sum, x;
	t = input();
	while(t--){
	    n = input();
	    k = input();         //grp1
	    grp2 = n - k;
	    sum = x = 0;
	    
	    for(i=0; i<n; i++){
	        arr[i] = input();
	        sum += arr[i];
	    }
	    
	    qsort(arr, n, sizeof(arr[0]), comparator);
	    
	    k = (grp2 < k)?grp2 : k;
	    
	    for(i=0; i<k; i++){
	        x += arr[i];
	    }
	    
	    printf("%d\n", abs((sum-x)-x));
	}
	return 0;
}

