#include <stdio.h>
#include <math.h>
long int mindiff(long long int num)
{
    long long int i;
    long int min,diff;
    min=100000000;
    for(i=1;i<=2*sqrt(num);++i)
    {
        if(num%i==0)
          diff=abs((num/i)-i);
          
        if(min>diff)
           min=diff;
          
    }
    return min;
}

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;
	    scanf("%lld",&n);
	    long int d;
	    d=mindiff(n);
	    printf("%ld\n",d);
	}
	return 0;
}

