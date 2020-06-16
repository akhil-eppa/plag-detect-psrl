#include <stdio.h>
 
#define ll long long unsigned int
ll modInverse = 500000004;
ll binaryModularExponentiation(ll,ll,ll);
ll sum(ll,ll);
int main()
{
	int testCases,size,i;
   ll mod=1000000007;
	scanf("%d",&testCases);
	while(testCases--)
	{
	   ll ans,summed=0;
		scanf("%d",&size);
		ll inp[size],arr[size-1];
 
 
	 for(i=0;i<size;i++)
		{
          scanf("%llu",&inp[i]);
	    	if(i>=1)
		      {
	    	    arr[i-1]=(((inp[i]%mod)*((binaryModularExponentiation(inp[i-1],mod-2,mod))%mod)))%mod;
		      }
		}
	  
	   for(i=0;i<size-1;i++)
	   {
		summed = ((summed%mod) + (sum(arr[i],mod)))%mod;
	   }
           
        
		ans=sum(summed,mod)%mod; 
		printf("%llu\n",ans);
  
	}	
	return 0;
}
 
ll sum(ll num,ll mod)
{
   ll result;
   result= (((num*num)%mod)+((num)%mod))%mod;
   result= (result*(modInverse%mod))%mod;
   return result;
}
 
ll binaryModularExponentiation(ll a,ll b,ll mod)
{
	if(b==0)
	 return 1;
 
	else if(b%2==0)
	 return binaryModularExponentiation((a*a)%mod,b/2,mod);
 
	else
	 return (a*binaryModularExponentiation((a*a)%mod,(b-1)/2,mod))%mod;
   
}