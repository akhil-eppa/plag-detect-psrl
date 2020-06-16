#include <stdio.h>
 
int main()
{
    long N,i;
    long m;
    long A[123456]={0};
    long B[123456]={0};
    scanf("%lld",&N);
    for(i=1;i<=N;i++){
    	scanf("%lld",&A[i]);
    }
    m=-1;
    for(i=1;i<=N;i++){
    	if(m<A[i]){
    		B[i]=1;
    		m=A[i];
    	}
    }
    m=-1;
    for(i=N;i>=1;i--){
    	if(m<A[i]){
    		B[i]=1;
    		m=A[i];
    	}
    }
    for(i=1;i<=N;i++){
    	if(B[i]==1)
    	printf("%lld ",i);
    }
    return 0;
}