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
 
size_t trailing_zeroes(size_t N){
 
    size_t tz_count = 0, t = N/5;
 
    do
    {
        tz_count += t;
        t /= 5;
    } 
    while (t > 0);
    
    return tz_count;
}
 
int main(){
 
    size_t T, M, N, tz_count;
    
    scanf("%zu", &T);
 
    while (T-- && scanf("%zu", &M))
    {
        N = M*5;
        tz_count = trailing_zeroes(N);
 
        while (tz_count > M)
        {
            N -= 5;
            tz_count = trailing_zeroes(N);
        }
 
        if (tz_count == M)
            printf("5\n%zu %zu %zu %zu %zu\n", N, N+1, N+2, N+3, N+4);
        else
            printf("0\n");
    }
    
}