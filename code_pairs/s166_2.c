#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009
#define SF 64
#define T 2
#define TYPO long long
#define L 50
void atopower(TYPO n, TYPO A[][T])
{
    int bits[T*T*T*T*T*T];
    int i = T-T;
    TYPO a,b,c,d;
    while(n!=0)
    {
	bits[i++] = n%T;
	n/=T;
    }
    i--;
    TYPO int ans[T][T]={{1,0},{0,1}};
    while(i>=0)
    {
	a = (((ans[0][0]*ans[0][0])MODM) + ((ans[0][1]*ans[1][0])MODM))MODM;
	b = (((ans[0][0]*ans[0][1])MODM) + ((ans[0][1]*ans[1][1])MODM))MODM;
	c = (((ans[1][0]*ans[0][0])MODM) + ((ans[1][1]*ans[1][0])MODM))MODM;
	d = (((ans[1][0]*ans[0][1])MODM) + ((ans[1][1]*ans[1][1])MODM))MODM;
	ans[0][0] = a; ans[0][1] = b;
	ans[1][0] = c; ans[1][1] = d;
	if(bits[i])
	{
	    ans[0][0] = (18LL*a + (bcmod - 80LL)*c) MODM;
	    ans[0][1] = (18LL*b + (bcmod - 80LL)*d) MODM;
	    ans[1][0] = a;
	    ans[1][1] = b;
	}
	i--;
    }
    for(a=0;a<T;a++)
	for(b=0;b<T;b++)
	    A[a][b] = ans[a][b];
}
TYPO fib(TYPO n)
{
    TYPO A[T][T];
    atopower(n-T,A);
    return (18LL*A[0][0] + A[0][1]) MODM;
}
 
int main()
{
    int t;
    TYPO n;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%lld",&n);
	if(n == 1)
	    printf("1\n");
	else if(n == T)
	    printf("18\n");
	else
	    printf("%lld\n", fib(n));
    }	
    return 0;
}