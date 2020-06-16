#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009

void input1(int *t)
 {
     scanf("%d",t);
 }

 void input2(long long int *n)
 {
     scanf("%lld",n);
 }
int main()
{
    int t;
    long long n;
    input1(&t);
    while(t--)
    {
	input2(&n);
	if(n == 1)
	    printf("1\n");
	else if(n == 2)
	    printf("18\n");
	else
    {
        long long A[2][2];
        int bits[64];
    int i = 0;
    long long a,b,c,d;
    while(n-2!=0)
    {
	bits[i++] = n%2;
	n = (n-2) / 2 + 2;
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
    long long fib = (18LL*A[0][0] + A[0][1]) MODM;
	    printf("%lld\n", fib);
    }
    }	
    return 0;
}