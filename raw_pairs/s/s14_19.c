#include <stdio.h>
#define MAX 10009
long long ans[MAX];
 
long long isPrime(long long n)
{
	if(n == 0 || n == 1)
		return 0;
	if(n == 2)
		return 1;
		
	for(long long i = 2; i * i <= n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
void preprocess()
{
	long long count = 0;
	long long last = 1;
	long long inc = 2;
	for(long long i = 3; i < MAX; i+=2)
	{
		for(long long j = 0; j < 4; j++)
		{
			last += inc;
			//printf("%lld\n", last);
			if(isPrime(last))
			{
				
				count++;
				//printf("%lld   count = %lld\n", last, count);
			}
		}
		inc += 2;
		ans[i] = count;
	}
}
int main()
{
    preprocess();
    double result;
    long long test;
    scanf("%lld", &test);
    long long n;
    while(test--)
    {
    	scanf("%lld", &n);
    	double pri = (double) ans[n];
    	double tot = (n / 2) * 4 + 1;
    	result = pri / tot;
    	result *= 100;
    	//printf("pri = %lf    tot = %lf \n", pri, tot);
    	printf("%.6lf\n", result);
    }
    return 0;
}