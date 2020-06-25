#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009
void atopower(long long n, long long A[][2])
{
    int bits[64];
    int i = 0, j;
    long long a,b,c,d;
    for(;n!=0;n/=2)
    {
	bits[i++] = n%2;
    }
    i--;
    long long int ans[2][2]={{1,0},{0,1}};
    for(j=i;j>=0;--j)
    {
	a = (((ans[0][0]*ans[0][0])MODM) + ((ans[0][1]*ans[1][0])MODM))MODM;
	b = (((ans[0][0]*ans[0][1])MODM) + ((ans[0][1]*ans[1][1])MODM))MODM;
	c = (((ans[1][0]*ans[0][0])MODM) + ((ans[1][1]*ans[1][0])MODM))MODM;
	d = (((ans[1][0]*ans[0][1])MODM) + ((ans[1][1]*ans[1][1])MODM))MODM;
	ans[0][0] = a; ans[0][1] = b;
	ans[1][0] = c; ans[1][1] = d;
	if(bits[j])
	{
	    ans[0][0] = (18LL*a + (bcmod - 80LL)*c) MODM;
	    ans[0][1] = (18LL*b + (bcmod - 80LL)*d) MODM;
	    ans[1][0] = a;
	    ans[1][1] = b;
	}
    }
    a = 0;
    while(a<2)
    {
        b = 0;
	    while(b<2)
        {
	        A[a][b] = ans[a][b];
            ++b;
        }
        ++a;
    }
}
long long fib(long long n)
{
    long long A[2][2];
    atopower(n-2,A);
    return (18LL*A[0][0] + A[0][1]) MODM;
}
 
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    do
    {
	scanf("%lld",&n);
	if(n == 1)
	    printf("1\n");
	else if(n == 2)
	    printf("18\n");
	else
	    printf("%lld\n", fib(n));
    }while(--t);
    return 0;
}