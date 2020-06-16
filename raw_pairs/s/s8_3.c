#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isOverflow(unsigned long long a, unsigned long long b) ;
void insertArray(unsigned long *A, unsigned long N);


 

 
// Write your code here
void main()
{
    unsigned long N, M;
    unsigned short T;
    scanf("%hu", &T);
    unsigned long divider = pow(10, 9) + 7;
    unsigned long long K;
    
    
    
    
    while(T--)
    {
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0;
        unsigned long long sum = 0, sumArray = 0, right = 0;
        scanf("%lu %lu %lu", &N, &M, &K);
        
        
        unsigned long A[N];
        insertArray(A, N);
        bool first = true, change = true, stop = true;
        unsigned long left = 0, j = 0;
        
        
        
        while(left < N)
        {
            if(right < ((j + 1) * N)) 
            {
                if((sum + A[right - (j * N)]) <= K) 
                {
                    if((right - left) >= N)
                    {
                        if(stop)
                        {
                            stop = false;
                            sumArray = sum;
                            
                        }
                        
                        unsigned long jump = (K - sum) / sumArray;
                        
                        if(jump > 0)
                        {
                            if((j + jump) < M)
                            {
                                j += jump;
                                sum += (sumArray * jump);
                                right += (N * jump);
                                
                            }
                            else
                            {
                                right = (M * N);
                                break;
                            }
                        }
                        else
                        {
                            right++;
                            sum += A[right-1 - (j * N)];
                            
                        }
                    }
                    else {
                        right++;
                        sum += A[right-1 - (j * N)];
                        
                    }
                } 
                else 
                {
                    if(left < right) 
                    {
                        if(right >= N) 
                        {
                            overlap += (right - N);
                            count += (N - left);
                            left++;
                            sum -= A[left-1];
                            
                        }
                        else
                        {
                            count += (right - left);
                            left++; 
                            sum -= A[left-1];
                               
                        }
                    } 
                    else 
                    {
                        ++left;
                        right++;
                        
                    }
                    if(first) 
                    {
                        first = false;
                        elements += j * N;
                        
                    }
                }
            } 
            else 
            {
                if((j + 1) < M) 
                {
                    if(!first && change)
                    {   till = overlap + count;
                    change = false;
                        elements += (N - left);
                        
                    }
                    j++;
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
            unsigned long long first, second;
            elements = right - left;
            
            
            if((elements % 2) == 0) 
            {
                second = elements + 1;
                first = elements / 2;
                
            }
            else 
            {second = elements + 1;
                first = elements;
                
            }
            
            while(isOverflow(first, second))
            {
                second = second % divider;
                first = first % divider;
                
            }
            
            count = (first * second)%divider;
            printf("%llu\n", count);
        } 
        
        //if left pointer reaches the end of the array A[] i.e. left pointer completes one array traversal
        else 
        {
            //if right pointer goes to (j * N)th position, but is not used and the loop breaks. So, decrementing j.
            if(right == (j * N)) 
            {
                --j;
            }
            
            if((right - left) >= N) 
            {
                unsigned long long tot;
                unsigned long long first, second;
                if(elements % 2 == 0) 
                {
                     second = (elements + 1);
                    first = (elements / 2);
                   
                }
                else
                {
                    first = elements;
                    second = (elements + 1) / 2;
                    
                }
                
                while(isOverflow(first, second))
                {
                    second = second % divider;
                    first = first % divider;
                    
                }
                
                tot = (first * second) % divider;
                till = till % divider;
                count = ((M - j) * (overlap + count)) % divider;
                count = count + tot + till;
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

void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = 0;
    while(i < N)
    {   
        i++;
        scanf("%lu", &A[i-1]);
        
    }
}

bool isOverflow(unsigned long long a, unsigned long long b) 
{ 

    unsigned long long result = a * b; 
    
    if (a == 0 || b == 0)  
        return false; 
      
    
    
    if (a == result / b) 
        return false; 
    else
        return true; 
}