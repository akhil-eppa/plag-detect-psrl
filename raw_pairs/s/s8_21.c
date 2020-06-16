/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include <stdio.h>
 
int main(){
	unsigned int T, N, M, K1;
	unsigned int *data;
	unsigned long temp = pow(10,9) + 7;
	long i, j, k;
	unsigned long result = 0;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
	    result = 0;
	    scanf("%d %d %d", &N, &M, &K1);
	    data = calloc(sizeof(unsigned int) * N, 1);
	    for (j = 0; j < N; j++)
	    {
	        scanf("%d", &data[j]);
	    }
	    /*for (j = 1; j < M; j++)
	    {
	        memcpy(&data[N * j], &data[0], N * sizeof(unsigned int) );
	    }*/
	    for (j = 0; j < (N*M); j++)
	    {
	        unsigned long sum = 0;
	        for(k = j; k < (N*M); k ++)
	        {
	            sum += data[k % N];
	             //printf("%d: %d ", k, sum);
	            if(sum > K1)
	            {
	                break;
	            }
	            result++;
	           
	        }
	        //printf("\n");
	    }
    	printf("%d\n", (result % temp));
	}
}