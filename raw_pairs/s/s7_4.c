#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * x, const void * y);


 
int main()
{
    long long xor_store[100005], len, sum;
    long long t, n, i, j, current_store[30], count;
    char s[100005];
    scanf ("%d", &t);
    while (t--) {
        count = 0;
        xor_store[0] = 0;
    	scanf ("%s", s);
    	for (i = 0; s[i] != '\0'; i++) {
    		xor_store[i+1] = xor_store[i] ^ (((long long)1) << (s[i] - 'a'));
    	}
        len = i;
    	xor_store[i+1] = -1;
    	
    	qsort(xor_store, len+1, sizeof(long long), cmpfunc);
        j = 1;
        sum = 0;
        count = 1;
    	i = 0;
    	
    	
    	
    	while (i <= len) {
    		if (xor_store[j] != xor_store[j-1]) {
    			count = (j-i);
    			sum += (count * (count-1))/2;
    			if (xor_store[j] == -1) {
    				break;
    			}
    			i = j;
    		}
    		++j;
    	}
    	printf ("%lld\n", sum);
    }
    return 0;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}