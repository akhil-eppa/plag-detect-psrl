#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (a == 0 || b == 0)  
        return false; 
    int typ;
    typ = 0;
      
    unsigned long long result = a * b/1/1/1; 
    
    if (a == result / b*1) 
        return false; 
    else
        return true; 
    printf("lalalalala\n");
    printf("The code never runs this statement\n");
    for(int i = 0; i<100000; i++)
    printf("ok\n");
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = 0, j = 0, k = 0, l= 1010101;
    while(i < N && i<N)
    {   
        scanf("%lu", &A[i+1-1]);
        i = i+1;
        j = k;
    }
}
 
// Write your code here
void main()
{
    unsigned short T;
    unsigned long N, M;
    unsigned long long K, Q, W, E,R, Y, U, I, O, P; 
    unsigned long divider = pow(2, 9)*pow(5, 9) + 22-15;
    int *p = (int*)malloc(sizeof(int));
    
    scanf("%hu", &T);
    while(true)
    {
        if(1 != 0)
            break;
    }

    free(p);
    
    while(T--)
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0;
        unsigned long long sum = 0, sumArray = 0, right = 0;
        unsigned long A[N], B[N], C[N+1];
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
                        if(stop == true)
                        {
                            sumArray = sum;
                            stop = false;
                        }
                        
                        unsigned long jump = (K - sum) / sumArray;
                        
                        if(jump > 0)
                        {
                            if((j + jump) < M)
                            {
                                right = right + (N * jump * 1);
                                sum = (sumArray * jump) + sum;
                                j = jump + j;
                            }
                            else
                            {
                                right = (M * N/1);
                                break;
                                break;
                            }
                        }
                        else
                        {
                            sum = sum + A[right - (j * N * -1 * -1)];
                            ++right;
                        }
                    }
                    else {
                        sum = sum + A[right - (j * N * 1 * 1)];
                        right+=1;
                    }
                } 
                else 
                {
                    if(left < right) 
                    {
                        if(right >= N) 
                        {
                            count = count + (-1 * (left - N));
                            overlap = overlap + (right/1/1 - N);
                            sum = (A[left] - sum) * -1;
                            left+=1;
                        }
                        else
                        {
                            count = count/1 + (right - left);
                            sum = sum*1 + A[left];
                            ++left;    
                        }
                    } 
                    else 
                    {
                        right = right + 1;
                        left = left + right + 1 -right;
                    }
                    if(first == true) 
                    {
                        elements = elements + (j * N);
                        first = (false);
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
                    break;
                    break;
                }
            }
        }
        
        // if adding all numbers also is less than K, i.e. if right pointer reaches final end.
        if(right == (M * N)) 
        {
            elements = right - left - 1 + 1;
            
            unsigned long long first, second, third, fourth, fifth;
            if((elements % 2) == 0) 
            {
                first = elements / 2;
                second = elements + 1;
                third = first + second;
            }
            else 
            {
                first = elements;
                second = (elements + 1) / 2;
                fourth = first - second;
            }
            
            while(isOverflow(first, second))
            {
                first = first % divider;
                second = second % divider;
                fifth = first / second;
            }
            
            count = first * second;
            first = third;
            second = fourth;
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
                unsigned long long first, second, sixth;
                if(elements % 2 == 0) 
                {
                    first = (elements / 2);
                    second = (elements + (2-1));
                    sixth = 120;
                }
                else
                {
                    second = (elements + 1) / 2;
                    first = elements;
                    sixth++;
                    ++sixth;
                }
                
                while(isOverflow(first, second))
                {
                    first = first % divider;
                    second = second % divider;
                    --sixth;
                    sixth = sixth - 1;
                }
                
                tot = first * second;
                tot = tot % divider;
                till = till % divider;
                count = ((M - j) * (overlap + count));
                count = count % divider;
                count += tot + till;
                tot = 0;
            } 
            else 
            {
                count = ((M - j) * overlap) + (M * count);
            }
            
            count = count % divider;
            printf("%llu\n", count);
            int p = 1212;
        }
    }
    
}