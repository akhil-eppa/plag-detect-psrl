#include <stdio.h>
#include <stdlib.h>

 
int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}
 
int main()
{
    long long t, n, i, j, current_store[30], count;
    char s[100005];
    long long xor_store[100005], len, sum;
    scanf ("%d", &t);
    while (t--)
    {
    	scanf ("%s", s);
    	count = 0;
    	xor_store[0] = 0;
    	for (i = 0; s[i] != '\0'; i++) 
        xor_store[i+1] = xor_store[i] ^ (((long long)1) << (s[i] - 'a'));
    	xor_store[i+1] = -1, len = i;
    	qsort(xor_store, len+1, sizeof(long long), cmpfunc);
    	i = 0, j = 1, count = 1, sum = 0;
    	while (i <= len) 
        {
    		if (xor_store[j] != xor_store[j-1])
            {
    			count = (j-i);
    			sum += (count * (count-1))/2;
    			if (xor_store[j] == -1)
    			    break;
    			i = j;
    		}
    		j++;
    	}
    	printf ("%lld\n", sum);
    }
    return 0;
}