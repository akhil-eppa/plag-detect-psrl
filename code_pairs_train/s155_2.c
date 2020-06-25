#include <stdio.h>
#define bcmod 1000000009
#define MODM % (1000000009)
void atopower(long long n, long long A[][2]);

long long fib(long long n);

 
int main()
{
    long long n;
    int t;
    
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
    return 0;
}

long long fib(long long n)
{
    long long A[2][2];
    atopower(n-2,A);
    return (18LL*A[0][0] + A[0][1]) MODM;
}

void atopower(long long n, long long A[][2])
{
    long long b,a,d,c;
    int i = 0;
    int bits[64];
    long long int ans[2][2]={{1,0},{0,1}};
    
    while(n!=0)
    {
	bits[i] = n%2;
    ++i;
	n /= 2;
    }
    --i;
    
    while(i>=0)
    {
        ans[0][1] = ( ((ans[0][1]*ans[1][1])MODM)+((ans[0][0]*ans[0][1])MODM) )MODM;
	ans[0][0] = ( ((ans[0][1]*ans[1][0])MODM)+((ans[0][0]*ans[0][0])MODM) )MODM;
	ans[1][1] = ( ((ans[1][1]*ans[1][1])MODM)+((ans[1][0]*ans[0][1])MODM) )MODM;
	ans[1][0] = ( ((ans[1][1]*ans[1][0])MODM)+((ans[1][0]*ans[0][0])MODM) )MODM;

    b = ( ((ans[0][1]*ans[1][1])MODM)+((ans[0][0]*ans[0][1])MODM) )MODM;
	a = ( ((ans[0][1]*ans[1][0])MODM)+((ans[0][0]*ans[0][0])MODM) )MODM;
	d = ( ((ans[1][1]*ans[1][1])MODM)+((ans[1][0]*ans[0][1])MODM) )MODM;
	c = ( ((ans[1][1]*ans[1][0])MODM)+((ans[1][0]*ans[0][0])MODM) )MODM;

	if(bits[i])
	{
        ans[0][1] = (18LL*b + (bcmod - 80LL)*d) MODM;
	    ans[0][0] = (18LL*a + (bcmod - 80LL)*c) MODM;
	    
	    
	    ans[1][1] = b; ans[1][0] = a;
	}
	i--;
    }
    for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	    A[a][b] = ans[a][b];
}