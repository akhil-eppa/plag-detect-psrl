#include <stdio.h>
#include <stdlib.h>
#define m 1000000007
 
typedef long long int lli;
 
lli modulExpo(lli x,lli n){
    lli re = 1;
    while(n!=0){
        if(n%2 == 1)
            re = (re*x)%m;
        x=(x*x)%m;
        n=n>>1;
    }
    return re;
}
 
 
int main(int argc,char **argv){
    lli t,n,f,Q,som,a,inve,j,i;
    scanf("%d",&t);
    for(j = 1 ;j<=t;j++){
        scanf("%lld",&n);
    	lli *arr = (lli*)malloc(sizeof(lli)*n);
    	for(lli j=0;j<n;j++)
    	    scanf("%lld",&arr[j]);
        f=0;
        Q=0;
        for(lli i = 0 ; i<n-1;i++){
            inve=modulExpo(arr[i],m-2);
    		a=(arr[i+1]*inve)%m;
    		som=((a*(a+1))/2)%m;
    		f=(f+som)%m;
        }
        
        Q =(f*(f+1)/2)%m;
        printf("%lld\n",Q%m);
        free(arr);
    }
    return 0;
}