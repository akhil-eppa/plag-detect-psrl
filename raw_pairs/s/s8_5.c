#include <stdio.h>
#include <math.h>
 
int isOverflow(int a, int b) 
{ 
    if (a == 0 || b == 0)  
        return 0; 
      
    int result = a * b; 
    
    if (a == result / b) 
        return 0; 
    else
        return 1; 
}
 
void insertArray(int *A, int N) 
{
    int i = 0;
    while(i < N)
    {   
        scanf("%d", &A[i]);
        i++;
    }
}
 
// Write your code here
void main()
{
    short int T;
    int N, M;
    int K;
    int divider = pow(10, 9) + 7;
    
    scanf("%hu", &T);
    
    while(T--)
    {
        scanf("%d %d %d", &N, &M, &K);
        
        int count = 0, overlap = 0, till = 0, elements = 0;
        int sum = 0, sumArray = 0, right = 0;
        int A[N];
        int left = 0, j = 0;
        int first = 1, change = 1, stop = 1;
        
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
                            stop = 0;
                        }
                        
                        int jump = (K - sum) / sumArray;
                        
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
                        first = 0;
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
                        change = 0;
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
            
            int long first, second;
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
            printf("%d\n", count);
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
                int long tot;
                int long first, second;
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
            printf("%llu\n", count);
        }
    }
    
}