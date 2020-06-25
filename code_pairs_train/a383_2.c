#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long

ll binCof(int n,int r){
    int i; 
    ll res=1;
    r=r < n-r ? r : n-r;
    for(i=0;i<r;++i){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}


int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int sum=0,n,k;
        scanf("%d %d",&n,&k);
        printf("%lld\n",binCof(n-1,k-1));
    }
    
}