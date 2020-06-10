#include<stdio.h>
long int M = 1000000009;
 
long long int power(int,long long int);
main()
{
	long long int tc,str_len,i,result;
	scanf("%lld",&tc);
 
	for(i=0;i<tc;i++)
	{
		scanf("%lld",&str_len);
 
		result=(((5*power(10,str_len-1))%M)-((4*power(8,str_len-1))%M)+M)%M;
	
		printf("%lld\n",result);
	}
}
 
long long int power(int base,long long int e)
{
	if(e==0)
	{
		return(1);
	}
	long long int ans=power(base,e/2);
	ans=(ans*ans)%M;
	if(e%2!=0)
	{
		return((base*ans)%M);
	}
	else
	{
		return(ans);
	}
 
}