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

int t_value()
{
    unsigned short x;
    scanf("%hu", &x);
    return x;

}

void print_count(unsigned long long c)
{
    printf("%llu\n", c);
}

 
// Write your code here
void main()
{
    unsigned short T = t_value();
    unsigned long N = 12, M = 13;
    unsigned long long K = 1313;
    unsigned long divider = pow(10, 9) + 7;
    
    while(T--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0;
        unsigned long long sum = 0, sumArray = 0, right = 0;
        unsigned long A[N];
        unsigned long left = 0, j = 0;
        bool first = true, change = true, stop = true;
        
        for(int i = 0; i<N; ++i)
        {
            scanf("%lu", &A[i]);
        }
        
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
        }
        
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
            
            while(isOverflow(first, second))
            {
                first = first % divider;
                second = second % divider;
            }
            
            count = first * second;
            
            count = count % divider;
            print_count(count);
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
            print_count(count);
            
        }
    }
    
}