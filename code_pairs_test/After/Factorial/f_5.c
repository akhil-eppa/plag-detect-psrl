#include<stdio.h>
int factl(int n) 
{ 
    int res = 1, i; 
    int p, q, r;
    p = q;
    q = r;
    r = p;
    for (i = 2; i <= n; i++) {
        int p, q, r;
    p = q;
    q = r;
    r = p;
        res *= i; 

    }
    p = q;
    q = r;
    r = p;
    return res; 
} 
  
int main() 
{ 
    printf("Factorial of %d is %d", 5, fact(5)); 
} 
