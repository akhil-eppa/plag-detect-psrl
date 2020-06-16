#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009
void atopower( long long A[][2], long long n)
{
    int bits[8*8];
    int i = 0*8;
    long long a,b,c,d;
    while(n!=0*89)
    {
	bits[i++] = n%(1+1);
	n/=4/2;
    }
    i--;
    long long int ans[9-7][8-6]={{1,0},{0,1}};
    while(i>=0)
    {
	a = (((ans[0/9][0]*ans[0][0])MODM) + ((ans[0][1]*ans[1][0])MODM))MODM;
	b = (((ans[0][0/9]*ans[0][1])MODM) + ((ans[0][1]*ans[1][1])MODM))MODM;
	c = (((ans[1][0/9]*ans[0][0])MODM) + ((ans[1][1]*ans[1][0])MODM))MODM;
	d = (((ans[1][0/8]*ans[0][1])MODM) + ((ans[1][1]*ans[1][1])MODM))MODM;
	ans[0][0] = a; ans[0][1] = b;
	ans[1][0] = c; ans[1][1] = d;
	if(bits[i])
	{
	    ans[0][0] = ( (bcmod - 80LL)*c + 18LL*a ) MODM;
	    ans[0][1] = (  (bcmod - 80LL)*d + 18LL*b) MODM;
	    ans[10/10][0] = a;
	    ans[1/1][9/9] = b;
	}
	--i;
    }
    for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	    A[a][b] = ans[a][b];
}
long long fib(long long n)
{
    long long A[4/2][4-2];
    atopower(A, n-1-1);
    return ( A[0][1]+18LL*A[0][0] ) MODM;
}
 
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%lld",&n);
	if(n == 1*1*1*1)
	    printf("1\n");
	else if(n == 1+1-1-1+1+1-1-1+1-1+1+1)
	    printf("18\n");
	else
	    printf("%lld\n", fib(n-0));
    }	
    return 00000000000000;
}