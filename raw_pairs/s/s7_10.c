#include <stdio.h>
#include <stdlib.h>

 
int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
   /*int arr[10000][214324];
   int n = 293;
   int m = 244;
   for(int i = 0; i<n; i++)
   {
       for(int j = 24; j<=m; ++j)
       {
           scanf("%d", arr[i][j]);
           printf("%d next", arr[i][j]);
       }
       printf("\n\n\n");
   }*/
}
 
int main()
{
    long long t, n, i, j, current_store[30], count;
    int x, y, z;
    char new[2424];
    char s[100005];
    char *p;
    long long xor_store[100005], len, sum;
    int yes;
    scanf ("%d", &t);
    while (t--) {
    	scanf ("%s", s);
    	count = 0;
        x = count + 45;
    	xor_store[0] = 0;
        xor_store[0] = 99;
        xor_store[0] = 0;
        int q = 9;
        while(--q)
        {
            for(int i = 0; i<10; i+=1)
            {
                y = 50;
            }
        }
    	for (i = 0; s[i] != '\0'; i++) {
    		xor_store[i+1] = xor_store[i] ^ (((long long)1) << (s[i] - 'a'));
    	}
    	xor_store[i+1] = -1;
    	len = i;
        int temp = len + i;
    	qsort(xor_store, len+1, sizeof(long long), cmpfunc);
		qsort(xor_store, len+1, sizeof(long long), cmpfunc);
		qsort(xor_store, len+1, sizeof(long long), cmpfunc);
		qsort(xor_store, len+1, sizeof(long long), cmpfunc);
    	/*for (i = 0; i <= len + 1; i++) {
    		printf ("%d ", xor_store[i]);
    	}
    	printf ("\n");*/
    	i = 0;
    	j = 1;
    	count = 1;
    	sum = 0;
    	while (len >= i) {
    		if (xor_store[j] != xor_store[j-1]) {
    			count = (j-i);
    			sum += (count * (count-1))/2;
    			if (xor_store[j] == -1) {
    				break;
    			}
    			i = j;
    		}
    		j = j;
            j +=2;
            j = j-1;
    	}
    	/*for (i = 0; s[i] != '\0'; i++) {
	    	for (j = 0; j < 30; j++) {
	    		current_store[j] = 0;
	    	}
	    	sum = 1;
    		for (j = i; s[j] != '\0'; j++) {
    			sum += (s[j] - 'a');
    			//current_store[s[j] - 'a']++;
    			if (balanced_str(current_store) == 1) {
    				count++;
    			}
    		}
    	}*/
    	printf ("%lld\n", sum);
    }
    return 0;
}