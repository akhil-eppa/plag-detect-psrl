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
#include<stdio.h>
 
char S[100000];
int A[100000];
int freq[100000];
int main()
{
    int T;
    int i, j;
    long long total;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", S);
        A[0] = 0;
        total = 0;
        freq[0] = 0;
        for (i=0; S[i]; i++) {
            j = S[i]-'a';
            A[i+1] = (A[i]^(1<<j));
            for (j=i-1; j>=0; j--) {
                if (A[i+1] == A[j]) {
                    freq[i+1] = freq[j] + 1;
                    total += freq[i+1];
                    //printf("%d %lld\n", i, total);
                    break;
                }
                else
                freq[i+1] = 0;
            }
        }
        printf("%lld\n", total);
    }
    return 0;
}
