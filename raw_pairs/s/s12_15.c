#include<stdio.h>
#define max 1000001
//#define mod 1000000007
int main()
{
    long long p[max]={0},i,j;
    p[0]=p[1]=1;
    for(i=2;i*i<=max;i++) {
        if(p[i]==0){
            for(j=i*i;j<max;j+=i)
                p[j]=1;
        }
    }
    for(i=0;i<max;i++){
        if(p[i]==0){
            p[i]=i;
        }
        else{
            p[i]=0;
        }
    }
    for(i=1;i<max;i++) {
        p[i]=p[i-1]+p[i];
    }
   int t; scanf("%d",&t);
    while(t--) {
        int l,r; 
        scanf("%d%d",&l,&r);
         printf("%lld\n",(p[r]-p[l-1]));
    }
}
    