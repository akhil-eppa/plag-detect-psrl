#include <stdio.h>
#define BIG % (1000000009)
#define mmm 1000000009
void convert(long long n, long long A[][2])
{
    int arr[64];
    int i = 0;
    long long a,b,c,d;
    while(n!=0)
    {
	arr[i++] = n%2;
	n/=2;
    }
    i--;
    long long int value[2][2]={{1,0},{0,1}};
    while(i>=0)
    {
	a = (((value[0][0]*value[0][0])BIG) + ((value[0][1]*value[1][0])BIG))BIG;
	b = (((value[0][0]*value[0][1])BIG) + ((value[0][1]*value[1][1])BIG))BIG;
	c = (((value[1][0]*value[0][0])BIG) + ((value[1][1]*value[1][0])BIG))BIG;
	d = (((value[1][0]*value[0][1])BIG) + ((value[1][1]*value[1][1])BIG))BIG;
	value[0][0] = a; value[0][1] = b;
	value[1][0] = c; value[1][1] = d;
	if(arr[i])
	{
	    value[0][0] = (18LL*a + (mmm - 80LL)*c) BIG;
	    value[0][1] = (18LL*b + (mmm - 80LL)*d) BIG;
	    value[1][0] = a;
	    value[1][1] = b;
	}
	i--;
    }
    for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	    A[a][b] = value[a][b];
}
long long fibonacci(long long n)
{
    long long A[2][2];
    convert(n-2,A);
    return (18LL*A[0][0] + A[0][1]) BIG;
}
 
int main()
{
    int test;
    long long number;
    scanf("%d",&test);
    while(test--)
    {
	scanf("%lld",&number);
	if(number == 1)
	    printf("1\n");
	else if(number == 2)
	    printf("18\n");
	else
	    printf("%lld\n", fibonacci(number));
    }	
    return 0;
}