#include<stdio.h>
int main(){
int testcase;
scanf("%d",&testcase);
while(testcase--){
    
    long long int n,a,k,i;
     a = 1ll;

       scanf("%lld%ld",&n,&k);
       n--;
       k--;
       if(k > n/2){
        k = n-k;
       }
       for(i=1; i<=k;i++){
           a = a*(n)/i;
           n--;
       }
       
       printf("%lld\n",a);

}

return 0;
}
