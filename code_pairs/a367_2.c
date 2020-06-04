#include <stdio.h>

#define MAX_N 100

void update_arr (int *arr, int n, int idx, int c) {
    if (c == 0)
        return;
        
    for (int i = 0; i < n; i++) {
        if (i != idx)
            arr [i] += c;
    }
    return;
}

void solve (int *arr, int n) {
    int steps = 0, l_steps = 0;
    int min_i = 0, max_i = 0, i;
    
    do {
        update_arr (arr, n, max_i, l_steps);
        
        for (i = 0; i < n; i++) {
            if (arr [i] < arr [min_i])
                min_i = i;
                
            if (arr [i] > arr [max_i])
                max_i = i;
        }
        
        l_steps = arr [max_i] - arr [min_i];
        steps += l_steps;
    } while (l_steps > 0);
    
    printf ("%d\n", steps);
}


int main(void) {
	// your code goes here
	int t, n, i;
	int arr [MAX_N];
	
	scanf ("%d", &t);
	
	while (t --) {
	    scanf ("%d", &n);
	    
	    for (i = 0; i < n; i++) {
	        scanf ("%d", &arr [i]);
	    }
	    
	    solve (arr, n);
	}
	
	
	return 0;
}