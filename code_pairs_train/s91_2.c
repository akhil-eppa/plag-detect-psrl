#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (a == 0 || b == 0)  
        return false; 
      
    unsigned long long result = a * b; 

    return (a == result / b) ? false : true;
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = 0;
    while(i < N)
    {   
        scanf("%lu", &A[i]);
        i++;
    }
}
 
// Write your code here
void main()
{
    unsigned short T;
    unsigned long N, M;
    unsigned long long K;
    unsigned long divider = pow(10, 9) + 7;
    
    scanf("%hu", &T);
    
    while(T--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0;
        unsigned long long sum = 0, sumArray = 0, right = 0;
        unsigned long A[N];
        unsigned long left = 0, j = 0;
        bool first = true, change = true, stop = true;
        
        insertArray(A, N);
        
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
                            int val = (j + jump);
                            if(val<M)
                                val = 0;
                                else
                                    val = 1;
                            int flag = 0;
                            switch(val)
                            {
                                case 0: right += (N * jump);
                                sum += (sumArray * jump);
                                j += jump; break;
                                case 1: right = (M * N);
                                flag = 1;
                                break;

                            }
                            if(flag)
                                break;
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
                        char new;
                        if(right>=N)
                            new = 'y';
                            else
                                new = 'n';
                        switch(new)
                        {
                            case 'y':count += (N - left);
                            overlap += (right - N);
                            sum -= A[left];
                            left++;break;
                            case 'n':count += (right - left);
                            sum -= A[left];
                            left++;break;
                            default: printf("no");

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
            switch(elements%2)
            {
                case 1: first = elements;
                second = (elements + 1) / 2;
                break;
                default: first = elements / 2;
                second = elements + 1;
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
                switch(elements%2)
                {
                    case 0: first = (elements / 2);
                    second = (elements + 1);break;
                    case 1: second = (elements + 1) / 2;
                    first = elements;break;
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