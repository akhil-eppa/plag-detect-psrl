#include <stdio.h>
#include <string.h>
 
#define MAX_QUANTITY (int)(1e6 + 1)
 
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}
 
int upper_bound(long long arr[], int n, long long num) {
    int l = 1; 
    int h = n;
    while(l < h) {
        int mid = l + (h - l) / 2;
        if(num == arr[mid]) {
            return mid;
        }
        if(num > arr[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    
    return l;
}
 
int maximum(long long a, long long b) {
    return a > b ? a : b;
}
 
int main(){
	long long n;
	scanf("%lld", &n); 
	
	long long quantities[MAX_QUANTITY];
	memset(quantities, 0, MAX_QUANTITY * sizeof(long long));
	
	long long max = 0;
	for(long long i=0; i<n; i++) {
	    long long idx;
	    scanf("%lld", &idx);
	    max = maximum(max, idx);
	    quantities[idx]++;
	}
	
	long long sum = 0;
 
	long long idx = 1;
	for(long long i=1; i<=max; i++) {
	    long long temp = quantities[i];
        quantities[i] = sum + (n - idx + 1) * i;
	    if(temp > 0) {
	        idx += temp;
	        sum += i * temp;
	    }
	}
	
	int q;
	scanf("%d", &q);
	
	for(int i=0; i<q; i++) {
	    long long num;
	    scanf("%lld", &num);
	    int ub = upper_bound(quantities, max + 1, num); // index of value equals to num or just greater than num. ie. upper_bound computation
	    printf("%d\n", ub == max + 1 ? -1 : ub);
	}
}
 