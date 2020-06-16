#include <stdio.h>
#include <stdlib.h>
 
int comparison (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}
 
int main()
{
    long long test_cases, n, o, p, new_array[30], character_number;
    char s[100005];
    long long old_array[100005], length, sum;
    scanf ("%d", &test_cases);
    while (test_cases--) {
    	scanf ("%s", s);
    	character_number = 0;
    	old_array[0] = 0;
    	for (o = 0; s[o] != '\0'; o++) {
    		old_array[o+1] = old_array[o] ^ (((long long)1) << (s[o] - 'a'));
    	}
    	old_array[o+1] = -1;
    	length = o;
    	qsort(old_array, length+1, sizeof(long long), comparison);
    	/*for (i = 0; i <= length + 1; i++) {
    		printf ("%d ", old_array[i]);
    	}
    	printf ("\n");*/
    	int i = 0;
    	p = 1;
    	character_number = 1;
    	sum = 0;
    	while (i <= length) {
    		if (old_array[p] != old_array[p-1]) {
    			character_number = (p-i);
    			sum += (character_number * (character_number-1))/2;
    			if (old_array[p] == -1) {
    				break;
    			}
    			i = p;
    		}
    		p++;
    	}
    	/*for (i = 0; s[i] != '\0'; i++) {
	    	for (p = 0; p < 30; p++) {
	    		new_array[p] = 0;
	    	}
	    	sum = 1;
    		for (p = i; s[p] != '\0'; p++) {
    			sum += (s[p] - 'a');
    			//new_array[s[p] - 'a']++;
    			if (balanced_str(new_array) == 1) {
    				character_number++;
    			}
    		}
    	}*/
    	printf ("%lld\n", sum);
    }
    return 0;
}