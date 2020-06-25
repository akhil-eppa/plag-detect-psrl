#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define c 1000000007
#define lli  long long int
 
lli modularExponentiation(lli value,lli n)
{
	if(n==0)
		return 1;
	else
	{
		if(n%2==0)
			return modularExponentiation((value*value)%c,n/2);
		else
			return (value*modularExponentiation((value*value)%c, (n-1)/2))%c;
	}
}
 
lli calculateQ(lli a[],lli n)
{
	lli A =0, B=0, ans=0,first =0;
 
	for(int i=0;i<n;i++)
	{
		A = (A+(a[i]*a[i])%c)%c;
		B = (B+a[i])%c;
	}
 
	
	first = (A*A)%c;
 
	first = (first +(B*B)%c )%c;
 
	first = (first + (2*A*B)%c)%c;
 
	
 
	ans = (first*modularExponentiation(8,c-2))%c;
 
 
	//printf("first = %lld\n",ans );
	lli temp = (A+B)%c;
	temp = (temp*modularExponentiation(4,c-2))%c;
 
	ans = (ans+temp)%c;
	//printf("final = %lld\n", ans);
	return ans;
}
 
void print(lli a[], lli n)
{
	for(lli i=0;i<n;i++)
		printf("%lld\n",a[i] );
}
 
 
int main()
{
	lli t, factor = modularExponentiation(2,c-2);
	scanf("%lld",&t);
 
	while(t--)
	{
		lli n, ans = 0;
		scanf("%lld",&n);
		lli arr[n], a[n-1],x;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			if(arr[i]==0)
				arr[i] =c;
		}
		for(int i=0;i<n-1;i++)
			a[i] = (arr[i+1]*modularExponentiation(arr[i],c-2))%c;
 
		//printf("%lld\n",calculateQ(a,n-1));
		ans = calculateQ(a,n-1);
		printf("%lld\n",ans );
	}
}
