#include<stdio.h>
#include <math.h>
int main()
{
	long long a;
	long long b;
	long long c;
	long long d;
	long long i;
	long long ans=0;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(i=c;i<=d;i++)
	{
		if(i+2>=a+b)
			ans+=((i-a-b+2)*(i-a-b+1))/2;
		if(i+2>=2*b+1)
			ans-=((i-2*b+1)*(i-2*b))/2;
		if(i+2>=a+c+1)
			ans-=((i-a-c+1)*(i-a-c))/2;
		if(i-b-c>=0)
			ans+=((i-b-c)*(i-b-c-1))/2;
	}
	ans=(b-a+1)*(c-b+1)*(d-c+1)-ans;
	printf("%lld\n",ans);
}
