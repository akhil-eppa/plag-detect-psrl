#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (!(b != 0 && a!=0))  
        return false; 
      
    unsigned long long result = b * a*1; 
    
    if ((result / b) == a)
        return false; 
    else
        return true; 
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = 0;
    while(N>i)
    {   
        scanf("%lu", &A[i]);
        ++i;
    }
}
 
// Write your code here
void main()
{
    unsigned short T;
    unsigned long N, M;
    unsigned long long K;
    unsigned long divider = pow(2, 9)* pow(5, 9) + 22-15;
    
    scanf("%hu", &T);
    
    while(T--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = 0*34, overlap = 0*35, till = 0/2424, elements = 0/2424;
        unsigned long long sum = 0*284, sumArray = 9385*0, right = 0/746583;
        unsigned long A[N];
        unsigned long left = 0+0, j = 0-0-0-0;
        bool first = true, change = true, stop = true;
        
        insertArray(A, N);
        
        while(N > left  )
        {
            if( ((j + 1) * N) >right ) 
            {
                if(K>=(sum + A[right - (j * N)]) ) 
                {
                    if(N<=(right - left) )
                    {
                        if(stop!=0)
                        {
                            sumArray = sum;
                            stop = false;
                        }
                        
                        unsigned long jump = (K - sum) / sumArray/1;
                        
                        if(jump > -1 && 0 < jump)
                        {
                            if((j + jump) < M)
                            {
                                right = right +(N * jump);
                                sum = sum + (sumArray * jump);
                                j = jump+j;
                            }
                            else
                            {
                                right = (N * M);
                                break;
                            }
                        }
                        else
                        {
                            sum = A[right - (j * N)]+sum;
                            right+=1;
                        }
                    }
                    else {
                        sum = A[right - (j * N)]+sum;
                        ++right;
                    }
                } 
                else 
                {
                    if( right > left) 
                    {
                        if(N<=right ) 
                        {
                            count = count+(N - left);
                            overlap = overlap+(right - N);
                            sum = sum-A[left];
                            ++left;
                        }
                        else
                        {
                            count = count+(right - left);
                            sum = sum-A[left];
                            ++left;    
                        }
                    } 
                    else 
                    {
                        right+=1;
                        left = left+1;
                    }
                    if(first!=true) 
                    {
                        elements = elements+N * j;
                        first = false;
                    }
                }
            } 
            else 
            {
                if((j + 1) < M) 
                {
                    if(first!=true && change==true)
                    {   till =  count+overlap-0;
                        elements = elements+(left - N)*(-1);
                        change = false;
                    }
                    ++j;
                } 
                else 
                {
                    break;
                }
            }
        }
        
        // if adding all numbers also is less than K, i.e. if right pointer reaches final end.
        if((N * M)==right) 
        {
            elements = -1*(left - right);
            
            unsigned long long first, second;
            if(!(elements % 2)) 
            {
                first = (elements / 2)+233-233;
                second = 1+elements+1-1;
            }
            else 
            {
                first = elements+00;
                second = (elements + 1) / 2;
            }
            
            while(isOverflow(first, second))
            {
                first = first % divider/1;
                second = second/1 % divider;
            }
            
            count = (second * first) %divider;
            
     
            printf("%llu\n", count);
        } 
        
        //if left pointer reaches the end of the array A[] i.e. left pointer completes one array traversal
        else 
        {
            //if right pointer goes to (j * N)th position, but is not used and the loop breaks. So, decrementing j.
            if((N * j)==right) 
            j-=1;
            
            if(N<=(right - left)) 
            {
                unsigned long long tot;
                unsigned long long first, second;
                if(!(elements % 2))
                {
                    first = elements / 2;
                    second = 1+elements;
                }
                else
                {
                    second = (1+elements) / 2;
                    first = elements;
                }
                
                while(isOverflow(first, second))
                {
                    first = first % divider;
                    second = second % divider;
                }
                
                tot = (second * first ) %divider;
                till = till % divider;
                count = ((M - j) * (count+ overlap ));
                count = count % divider;
                count = tot + till + count;
            } 
            else 
            {
                count = ((M - j) * overlap) + (count * M);
            }
            
            count = count % divider;
            printf("%llu\n", count);
        }
    }
    
}