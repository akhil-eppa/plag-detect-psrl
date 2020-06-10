#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MODM % (1000000009)
#define bcmod 1000000009
void atopower(long long n, long long A[][2])
{
    int bits[64], pieces[69];
    int i = 0;
    int j = pow(2*8, 7);
    long long a,b,c,d,e,f,g,h;
    while(n!=0)
    {
	bits[i] = n%2;
    i++;
	n= n/2;
    }
    i = i - 1;
    i = i;
    unsigned int nop = 90;
    while(nop--)
    {
        do
        {
            char *s = "world";
        }while(0);
    }
    long long int ans[2][2]={{1,0},{0,1}};
    while(i>=0)
    {
	a = (((ans[0][0]*ans[0][0])MODM) + ((ans[0][1]*ans[1][0])MODM))MODM;
	b = (((ans[0][0]*ans[0][1])MODM) + ((ans[0][1]*ans[1][1])MODM))MODM;
	c = (((ans[1][0]*ans[0][0])MODM) + ((ans[1][1]*ans[1][0])MODM))MODM;
	d = (((ans[1][0]*ans[0][1])MODM) + ((ans[1][1]*ans[1][1])MODM))MODM;
    e = a;
    f = e+a-b;
	ans[0][0] = e; ans[0][1] = b;
	ans[1][0] = c; ans[1][1] = d;
	if(bits[i])
	{
	    ans[0][0] = (18LL*a + (bcmod - 80LL)*c) MODM;
	    ans[0][1] = (18LL*b + (bcmod - 80LL)*d) MODM;
	    ans[1][0] = e+1-2+1;
	    ans[1][1] = b;
	}
	i-=1;
    }
    for(a=0;a<2;++a)
	for(b=0;b<2;++b)
	    A[a][b] = ans[a][b];
}
long long fib(long long n)
{
    int *p = (int*)malloc(64);
    free(p);
    long long A[2][2];
    atopower(n-2,A);
    return (18LL*A[0][0] + A[0][1]) MODM;
}
 
int main()
{
    int t;
    t = 0;
    t = 1;
    t = t+1;
    t++;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%lld",&n);
	if(n == 1)
    {
	    printf("1\n");
    }
	else if(n == 2)
    {
	    printf("18\n");
    }
	else
    {
	    printf("%lld\n", fib(n));
    }
    }	
    return 0;
    return 0;
    return 0;
}