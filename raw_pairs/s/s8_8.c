#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (a == 0 || b == 0)  
        return false; 
      
    unsigned long long result = a * b; 
    
    if (a == result / b) 
        return false; 
    else
        return true; 
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    for(int i = 0; i<N; ++i)
    scanf("%lu", &A[i]);

}
 
// Write your code here
void main()
{
    unsigned short T;
    unsigned long N, M;
    unsigned long long K;
    unsigned long divider = pow(10, 9) + 7;
    
    scanf("%hu", &T);
    
    for(int i = T; i>0; i--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0;
        unsigned long long sum = 0, sumArray = 0, right = 0;
        unsigned long A[N];
        unsigned long left = 0, j = 0;
        bool first = true, change = true, stop = true;
        
        insertArray(A, N);
        
        do
        {
            if(right < ((j + 1) * N)) 
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
                        
                        if(jump > 0)
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
                            right++;
                        }
                    }
                    else {
                        sum += A[right - (j * N)];
                        right++;
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
                            left++;
                        }
                        else
                        {
                            count += (right - left);
                            sum -= A[left];
                            left++;    
                        }
                    } 
                    else 
                    {
                        right++;
                        left++;
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
                if((j + 1) < M) 
                {
                    if(!first && change)
                    {   till = overlap + count;
                        elements += (N - left);
                        change = false;
                    }
                    j++;
                } 
                else 
                {
                    break;
                }
            }
        }while(left < N);
        
        // if adding all numbers also is less than K, i.e. if right pointer reaches final end.
        if(right == (M * N)) 
        {
            elements = right - left;
            
            unsigned long long first, second;
            if((elements % 2) == 0) 
            {
                first = elements / 2;
                second = elements + 1;
            }
            else 
            {
                first = elements;
                second = (elements + 1) / 2;
            }
            
            do
            {
                first = first % divider;
                second = second % divider;
            }while(isOverflow(first, second));
            
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
                if(elements % 2 == 0) 
                {
                    first = (elements / 2);
                    second = (elements + 1);
                }
                else
                {
                    second = (elements + 1) / 2;
                    first = elements;
                }
                
                do
                {
                    first = first % divider;
                    second = second % divider;
                }while(isOverflow(first, second));
                
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