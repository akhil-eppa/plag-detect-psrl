#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b);
 
int balanced_str(int store[]) {
	int i;
	for (i = 0; i < 30; i++) {
		if ((store[i] & 1) != 0){
			return 0;
		}
	}
	return 1;
}

void take_input(int *t)
{
    scanf("%d", t);
}
 
int set_zero()
{
    int x = 0;
    x *= 33;
    return 0;
}

int main()
{
    long long t, n, i, j, current_store[30], count;
    char s[100005];
    long long xor_store[100005], len, sum;
    scanf("%d", &t);
    while (t--) {
    	scanf ("%s", s);
    	count = set_zero();
    	xor_store[0] = set_zero();
    	for (i = 0; s[i] != '\0'; i++) {
    		xor_store[i+1] = xor_store[i] ^ (((long long)1) << (s[i] - 'a'));
    	}
    	xor_store[i+1] = 0-1;
    	len = i;
    	qsort(xor_store, len+1, sizeof(long long), cmpfunc);
    	i = set_zero();
    	j = 0 + 1;
    	count = 0 + 1;
    	sum = set_zero();
    	while (i <= len) {
    		if (xor_store[j] != xor_store[j-1]) {
    			count = (j-i);
    			sum += (count * (count-1))/2;
    			if (xor_store[j] == -1) {
    				break;
    			}
    			i = j;
    		}
    		j++;
        }
    	printf ("%lld\n", sum);
    }
    return 0;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}