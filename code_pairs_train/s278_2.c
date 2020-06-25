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
 
void main()
{
    unsigned short T;
    
    scanf("%hu", &T);
    
    while(T--)
    {
        unsigned long N, M, i = 0;
        scanf("%lu %lu", &N, &M);
        long long A[100000] = { -1 };
        
        if(M > N)
        {
            printf("NO\n");
            continue;
        }
        
        while(i < M)
        {
            unsigned long X, Y;
            scanf("%lu %lu", &X, &Y);
            
            if(X > Y)
            {
                Y = Y + N;
            }
            
            while(X <= Y)
            {
                unsigned long p;
                if(X >= N)
                    p = X - N;
                else
                    p = X;
                    
                unsigned long k = 0;
                while(k < i)
                {
                    if(A[k] != p)
                        k++;
                    else
                        break;
                }
                
                if( k == i)
                {
                    A[k] = p;
                    break;
                }
                    
                X++;
            }
            
            if(X > Y)
            {
                break;
            }
            
            i++;
        }
        
        if(i == M)
                printf("YES\n");
            else
                printf("NO\n");
    }
}