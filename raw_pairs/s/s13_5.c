#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009
char atopower(long long int n, long long int A[][2])
{
    long long int bits[64];
    long long int i = 0;
    long long int a,b,c,d;
    while(n!=0)
    {
	bits[i++] = n%2;
	n/=2;
    }
    i--;
    long long int ans[2][2]={{1,0},{0,1}};
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
    for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	    A[a][b] = ans[a][b];
    return '9';
}
long long int fib(long long int n)
{
    long long int A[2][2];
    atopower(n-2,A);
    return (18LL*A[0][0] + A[0][1]) MODM;
}
 
void main()
{
    long long int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%lld",&n);
	if(n == 1)
	    printf("1\n");
	else if(n == 2)
	    printf("18\n");
	else
	    printf("%lld\n", fib(n));
    }	
}