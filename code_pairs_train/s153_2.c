#include <stdio.h>
#define MODM % (1000000009)
#define bcmod 1000000009
/*
    comments
    are
    added
*/
void atopower(long long n, long long A[][2])
{
    int bits[64];//comment
    int i = 0;
    long long a,b,c,d;
    while(n!=0)//comment
    {
	bits[i++] = n%2;
	n/=2;
    }//comment
    i--;
    long long int ans[2][2]={{1,0},{0,1}};//new comment
    while(i>=0)
    {
	a = (((ans[0][0]*ans[0][0])MODM) + ((ans[0][1]*ans[1][0])MODM))MODM; //a
	b = (((ans[0][0]*ans[0][1])MODM) + ((ans[0][1]*ans[1][1])MODM))MODM;//bb
	c = (((ans[1][0]*ans[0][0])MODM) + ((ans[1][1]*ans[1][0])MODM))MODM;//c
	d = (((ans[1][0]*ans[0][1])MODM) + ((ans[1][1]*ans[1][1])MODM))MODM;//d
	ans[0][0] = a; ans[0][1] = b;
	ans[1][0] = c; ans[1][1] = d;
	if(bits[i])//if
	{
	    ans[0][0] = (18LL*a + (bcmod - 80LL)*c) MODM;
	    ans[0][1] = (18LL*b + (bcmod - 80LL)*d) MODM;
	    ans[1][0] = a;
	    ans[1][1] = b;
	}
	i--;//i--
    }
    for(a=0;a<2;a++)//double for loop
	for(b=0;b<2;b++)//nested for
	    A[a][b] = ans[a][b];
}
long long fib(long long n)//fib function
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
    while(t--)
    {
	scanf("%lld",&n);
	if(n == 1)
	    printf("1\n");
	else if(n == 2)
	    printf("18\n");
	else
	    printf("%lld\n", fib(n));//print
    }	
    return 0;
}