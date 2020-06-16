#include <stdio.h>
#include <stdlib.h>

/*
    This is a sample program
    printf("Hello World\n\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
*/
 
int cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b ); //Returns the difference of 2 numbers.
}
 
int main()
{
    //All the variables are declared here
    long long t, n, i, j, current_store[30], count;
    char s[100005]; //s is a string
    long long xor_store[100005], len, sum; //len and sum are long long integers
    scanf ("%d", &t); //Number of test cases
    while (t--) { //While loop
    	scanf ("%s", s);
        //Set count to 0
    	count = 0;
        //Set xor store to 0
    	xor_store[0] = 0;
    	for (i = 0; s[i] != '\0'; i++) { //For loop
    		xor_store[i+1] = xor_store[i] ^ (((long long)1) << (s[i] - 'a'));
    	}
        //end of for
    	xor_store[i+1] = -1;
    	len = i; //len=i
    	qsort(xor_store, len+1, sizeof(long long), cmpfunc);
    	i = 0;//i=0
    	j = 1;//j=1
    	count = 1;
    	sum = 0; //sum is zero
    	while (i <= len) { ///while loop
    		if (xor_store[j] != xor_store[j-1]) { //if condition
    			count = (j-i);
    			sum += (count * (count-1))/2;
    			if (xor_store[j] == -1) {
    				break; //break out of while loop
    			}
    			i = j; //i is equal to j
    		}
    		j++; //j = j+1
    	}
    	printf ("%lld\n", sum);
    }
    return 0; //end
}