#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define ZERO 0
#define ONE 1
#define MAX 1000000007
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (a == ZERO || b == ZERO)  
        return false; 
      
    unsigned long long result = a * b; 
    
    if (a == result / b) 
        return false; 
    else
        return true; 
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = ZERO;
    while(i < N)
    {   
        scanf("%lu", &A[i]);
        i+=ONE;
    }
}
 
// Write your code here
void main()
{
    unsigned short T;
    unsigned long N, M;
    unsigned long long K;
    unsigned long divider = MAX;
    
    scanf("%hu", &T);
    
    while(T--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = ZERO, overlap = ZERO, till = ZERO, elements = ZERO;
        unsigned long long sum = ZERO, sumArray = ZERO, right = ZERO;
        unsigned long A[N];
        unsigned long left = ZERO, j = ZERO;
        bool first = true, change = true, stop = true;
        
        insertArray(A, N);
        
        while(left < N)
        {
            if(right < ((j + ONE) * N)) 
            {
                if((sum + A[right - (j * N)]) <= K) 
                {
                    if((right - left) >= N)
                    {
                        if(stop)
                        {
                            sumArray = sum;
                            stop = false;
                        }
                        
                        unsigned long jump = (K - sum) / sumArray;
                        
                        if(jump > ZERO)
                        {
                            if((j + jump) < M)
                            {
                                right += (N * jump);
                                sum += (sumArray * jump);
                                j += jump;
                            }
                            else
                            {
                                right = (M * N);
                                break;
                            }
                        }
                        else
                        {
                            sum += A[right - (j * N)];
                            right+=ONE;
                        }
                    }
                    else {
                        sum += A[right - (j * N)];
                        right+=ONE;
                    }
                } 
                else 
                {
                    if(left < right) 
                    {
                        if(right >= N) 
                        {
                            count += (N - left);
                            overlap += (right - N);
                            sum -= A[left];
                            left+=ONE;
                        }
                        else
                        {
                            count += (right - left);
                            sum -= A[left];
                            left+=ONE;    
                        }
                    } 
                    else 
                    {
                        right+=ONE;
                        left+ONE;
                    }
                    if(first) 
                    {
                        elements += j * N;
                        first = false;
                    }
                }
            } 
            else 
            {
                if((j + ONE) < M) 
                {
                    if(!first && change)
                    {   till = overlap + count;
                        elements += (N - left);
                        change = false;
                    }
                    j+=ONE;
                } 
                else 
                {
                    break;
                }
            }
        }
        
        // if adding all numbers also is less than K, i.e. if right pointer reaches final end.
        if(right == (M * N)) 
        {
            elements = right - left;
            
            unsigned long long first, second;
            if((elements % 2) == ZERO) 
            {
                first = elements / (ONE + ONE);
                second = elements + ONE;
            }
            else 
            {
                first = elements;
                second = (elements + ONE) / (ONE + ONE + ZERO);
            }
            
            while(isOverflow(first, second))
            {
                first = first % divider;
                second = second % divider;
            }
            
            count = first * second;
            
            count = count % divider;
            printf("%llu\n", count);
        } 
        
        //if left pointer reaches the end of the array A[] i.e. left pointer completes one array traversal
        else 
        {
            //if right pointer goes to (j * N)th position, but is not used and the loop breaks. So, decrementing j.
            if(right == (j * N)) 
            {
                j--;
            }
            
            if((right - left) >= N) 
            {
                unsigned long long tot;
                unsigned long long first, second;
                if(elements % 2 == ZERO) 
                {
                    first = (elements / (ONE + ONE - ZERO));
                    second = (elements + ONE);
                }
                else
                {
                    second = (elements + ONE) / (ONE + ONE - ZERO);
                    first = elements;
                }
                
                while(isOverflow(first, second))
                {
                    first = first % divider;
                    second = second % divider;
                }
                
                tot = first * second;
                tot = tot % divider;
                till = till % divider;
                count = ((M - j) * (overlap + count));
                count = count % divider;
                count += tot + till;
            } 
            else 
            {
                count = ((M - j) * overlap) + (M * count);
            }
            
            count = count % divider;
            printf("%llu\n", count);
        }
    }
    
}