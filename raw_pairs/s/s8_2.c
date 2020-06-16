#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
bool check_for_overflow(unsigned long long x, unsigned long long y) 
{ 
    if (x == 0 || y == 0)  
        return false; 
      
    unsigned long long value = x * y; 
    
    if (x == value / y) 
        return false; 
    else
        return true; 
}
 
void add_new_element(unsigned long *a, unsigned long n) 
{
    unsigned long temp = 0;
    while(temp < n)
    {   
        scanf("%lu", &a[temp]);
        temp++;
    }
}
 
// Write your code here
void main()
{
    unsigned short number_of_test_cases;
    unsigned long n, m;
    unsigned long long k;
    unsigned long some_variable = pow(10, 9) + 7;
    
    scanf("%hu", &number_of_test_cases);
    
    while(number_of_test_cases--)
    {
        scanf("%lu %lu %lu", &n, &m, &k);
        
        unsigned long long COUNT = 0, o = 0, t = 0, ELE = 0;
        unsigned long long S = 0, sarr = 0, r = 0;
        unsigned long A[n];
        unsigned long l = 0, x = 0;
        bool f = true, ch = true, st = true;
        
        add_new_element(A, n);
        
        while(l < n)
        {
            if(r < ((x + 1) * n)) 
            {
                if((S + A[r - (x * n)]) <= k) 
                {
                    if((r - l) >= n)
                    {
                        if(st)
                        {
                            sarr = S;
                            st = false;
                        }
                        
                        unsigned long xump = (k - S) / sarr;
                        
                        if(xump > 0)
                        {
                            if((x + xump) < m)
                            {
                                r += (n * xump);
                                S += (sarr * xump);
                                x += xump;
                            }
                            else
                            {
                                r = (m * n);
                                break;
                            }
                        }
                        else
                        {
                            S += A[r - (x * n)];
                            r++;
                        }
                    }
                    else {
                        S += A[r - (x * n)];
                        r++;
                    }
                } 
                else 
                {
                    if(l < r) 
                    {
                        if(r >= n) 
                        {
                            COUNT += (n - l);
                            o += (r - n);
                            S -= A[l];
                            l++;
                        }
                        else
                        {
                            COUNT += (r - l);
                            S -= A[l];
                            l++;    
                        }
                    } 
                    else 
                    {
                        r++;
                        l++;
                    }
                    if(f) 
                    {
                        ELE += x * n;
                        f = false;
                    }
                }
            } 
            else 
            {
                if((x + 1) < m) 
                {
                    if(!f && ch)
                    {   t = o + COUNT;
                        ELE += (n - l);
                        ch = false;
                    }
                    x++;
                } 
                else 
                {
                    break;
                }
            }
        }
        
        // if adding all numbers also is less than k, i.e. if r pointer reaches final end.
        if(r == (m * n)) 
        {
            ELE = r - l;
            
            unsigned long long f, SEC;
            if((ELE % 2) == 0) 
            {
                f = ELE / 2;
                SEC = ELE + 1;
            }
            else 
            {
                f = ELE;
                SEC = (ELE + 1) / 2;
            }
            
            while(check_for_overflow(f, SEC))
            {
                f = f % some_variable;
                SEC = SEC % some_variable;
            }
            
            COUNT = f * SEC;
            
            COUNT = COUNT % some_variable;
            printf("%llu\n", COUNT);
        } 
        
        //if l pointer reaches the end of the array A[] i.e. l pointer completes one array traversal
        else 
        {
            //if r pointer goes to (x * n)th position, but is not used and the loop breaks. So, decrementing x.
            if(r == (x * n)) 
            {
                x--;
            }
            
            if((r - l) >= n) 
            {
                unsigned long long TOT;
                unsigned long long f, SEC;
                if(ELE % 2 == 0) 
                {
                    f = (ELE / 2);
                    SEC = (ELE + 1);
                }
                else
                {
                    SEC = (ELE + 1) / 2;
                    f = ELE;
                }
                
                while(check_for_overflow(f, SEC))
                {
                    f = f % some_variable;
                    SEC = SEC % some_variable;
                }
                
                TOT = f * SEC;
                TOT = TOT % some_variable;
                t = t % some_variable;
                COUNT = ((m - x) * (o + COUNT));
                COUNT = COUNT % some_variable;
                COUNT += TOT + t;
            } 
            else 
            {
                COUNT = ((m - x) * o) + (m * COUNT);
            }
            
            COUNT = COUNT % some_variable;
            printf("%llu\n", COUNT);
        }
    }
    
}