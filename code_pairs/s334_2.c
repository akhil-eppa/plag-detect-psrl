#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int long long
 
int M = 1000000009;
int __power(int x , int p) {
    int res = 1;
    while(p) {
        if(p & 1) res = (res * x)%M;
        p >>= 1;
        x = (x * x)%M;
    }
    return res;
}
 
signed main() {
    
    int t , n;
    scanf("%lld" , &t);
    while(t--) {
        scanf("%lld" , &n);
        int ans = (__power(10 , n) - __power(8 , n) + M)%M;
        ans = (ans * __power(2 , M-2))%M;
        printf("%lld\n" , ans);
    }    
    return 0;
}