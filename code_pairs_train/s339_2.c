#include <stdio.h>
#define MOD 1000000009
#define s(k) scanf("%d",&k)
#define sll(k) scanf("%lld",&k)
#define p(k) printf("%d\n",k)
#define pll(k) printf("%lld\n",k)
typedef long long ll;
ll pow(int base, ll N){
	ll X;
	if(N==0)
		return 1;
	X=pow(base,N/2);
	X=(X*X)%MOD;
	if(N%2)
		X=(X*base)%MOD;
	return X;
}
int main()
{
	int T;
	ll N,X;	
	s(T);
	while(T--) {
		sll(N);
		X=(((5*pow(10,N-1))%MOD)-((4*pow(8,N-1))%MOD)+MOD)%MOD;
		pll(X);
	}
    //printf("Hello World!\n");
    return 0;
}