#include <stdio.h>
#include <inttypes.h>
 
 
 
uint64_t pow(uint64_t A, uint64_t B, int M)
{
    if(B==0)
        return 1;
    
    if(B&1)
        return (A*pow(A,B-1,M)%M);
    else
        {
            uint64_t temp = pow(A,B/2,M);
            return (temp*temp)%M;
        }
}
 
 
 
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
    int M = 1000000007;
    while(num--)
    {
        int N,i;
        scanf("%d",&N);
        uint64_t result = 0;
        uint64_t num1,num2,temp;
        scanf("%llu",&num1);
        
        for(i=1;i<N;i++)
            {
                scanf("%llu",&num2);
                if(num2%num1!=0)
                    temp = (num2*pow(num1,M-2,M))%M;
                else
                    temp = num2/num1;
                
                result = (result + (temp*(temp+1)/2))%M;
                num1 = num2;
            }
        uint64_t final_result = (result*(result+1)/2)%M;
        printf("%llu\n",final_result);
    }
    
}
