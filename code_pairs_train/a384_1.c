#include<stdio.h>
int main(){
    long long int t;
    scanf("%lld",&t);
    for(int i=0;i<t;i++){
        long long int n,k;
        scanf("%lld %lld",&n,&k);
        long long int result,menor;
        if((n-k)<(k-1)){
            menor=n-k;
        }
        else{
            menor=k-1;
        }
        result=1ll;
        for(int j=1;j<=menor;j++){
            result=result*(n-j)/j;
        }
        printf("%lld\n",result);
    }
    return 0;
}