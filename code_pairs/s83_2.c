#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
    Extra comments
*/
 
bool isOverflow(unsigned long long a, unsigned long long b) 
{ 
    if (a == 0 || b == 0)  //Comment
        return false; 
      
    unsigned long long result = a * b; //Long Long result
    
    if (a == result / b) 
        return false; 
    else
        return true; 
    /*
        End of the function
        true or false is returned
    */
}
 
void insertArray(unsigned long *A, unsigned long N) 
{
    unsigned long i = 0; //i is a long variable
    //Insert elements into the array
    while(i < N)
    {   
        scanf("%lu", &A[i]);
        i++;
    }
}

void main()
{
    //All the variables are declared here
    unsigned short T;
    unsigned long N, M;
    unsigned long long K;
    unsigned long divider = pow(10, 9) + 7;
    
    scanf("%hu", &T); //Number of test cases
    
    while(T--) //while loop for each test case
    {
        scanf("%lu %lu %lu", &N, &M, &K);
        //This is a very long program
        unsigned long long count = 0, overlap = 0, till = 0, elements = 0; //Inssert
        unsigned long long sum = 0, sumArray = 0, right = 0;//delete
        unsigned long A[N];//Update
        unsigned long left = 0, j = 0; //Other
        bool first = true, change = true, stop = true; //Yes
        
        insertArray(A, N);
        
        while(left < N) //While looop
        {
            if(right < ((j + 1) * N))  //Many nested if conditions
            {
                if((sum + A[right - (j * N)]) <= K) 
                {
                    if((right - left) >= N)
                    {
                        if(stop)
                        {
                            sumArray = sum;
                            stop = false; //dont stop
                        }
                        
                        unsigned long jump = (K - sum) / sumArray; //This is a comment
                        
                        if(jump > 0) //Another comment
                        {
                            if((j + jump) < M) //If else case
                            {
                                right += (N * jump); //update right
                                sum += (sumArray * jump); //update sum
                                //update jump
                                j += jump;
                            }
                            else
                            {
                                right = (M * N); //set value of right
                                break; //break
                            }
                        }
                        else //else
                        {
                            sum += A[right - (j * N)]; //update sum
                            right++; //increment right variable
                        }
                    }
                    //else case
                    else {
                        sum += A[right - (j * N)];
                        right++;
                    }
                } 
                else //another else case
                {
                    if(left < right) //This program is very long
                    {
                        if(right >= N)  //if-else condtion
                        {
                            count += (N - left);
                            overlap += (right - N);
                            //Comment Comment Comment
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
                        right++; //right+=1
                        left++; //left+=1
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
                    if(!first && change) //Too many if-else conditions
                    {   till = overlap + count;
                        elements += (N - left);
                        change = false;
                    }
                    j++; //j++
                } 
                else 
                {
                    break; //break
                }
            }
        }
        /*
            This is a comment
        */

        if(right == (M * N))//Removed some comments
        {
            elements = right - left;
            
            unsigned long long first, second;
            if((elements % 2) == 0) //yes
            {
                first = elements / 2;
                second = elements + 1;
            }
            else //no
            {
                first = elements;
                second = (elements + 1) / 2;
            }
            //while loop for overflow
            while(isOverflow(first, second))
            {
                first = first % divider;
                second = second % divider;
            }
            
            count = first * second; //first * second = count
            
            count = count % divider;
            printf("%llu\n", count);
        } 
        
        //left
        else 
        {
            //right
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
            printf("%llu\n", count);
        }
    }
    //End of the long program.
}