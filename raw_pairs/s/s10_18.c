#include <stdio.h>
#define MOD 1000000007
long long fact(long long);
long long isprime(long long x)
{	long long i;
	if(x == 2)return 1;
	if(x%2==0)return 0;
	for( i=3;i*i<=x;i+=2)
		if(x%i==0)return 0;
	return 1;
}
 
long long power(long long a ,long long b)
{	if(b==0)return 1;
	long long x = power(a,b/2);
	if(b%2==0)return (x*x)%MOD;
	x = (x*x)%MOD;
	return (a*x)%MOD;
}
/* long long nCr(long long n,long long r)
{ 	long long i,C=1;
	if(r > n-r)r = n-r;
	for(i = 1 ;i<=r ;i++)
    {
		C = ((n-i+1)* C)/(i) ;
      //  printf("*%lld.",C);
	}return C;
}*/
 
int main()
{
    long long n,i,m,j,a[10000],b[10000],d=0,count=0;
    long long k=1;
    scanf("%lld",&n);
    while(n--)
    {
    scanf("%lld",&m);
    count=0;
    for(i=0;i<m;i++)
    {
    	scanf("%lld",&a[i]);
    	//if(isprime(a[i]))count++;
    	if(a[i]==2)
    	count++;
    	else
    	{
    		d=0;
    	     for(j=2;j<a[i];j++)
    	    {
    		if(a[i]%j!=0)
    		d++;
    		}
    		if(d==(a[i]-2))
    		count++;
 
    	}
 
    }
    if(count==0)
    {
    k=power(2,power(2,m));
 
    }
    else
    {
  b[0] = b[count] = 1;
 // printf("%lld:::", nCr(12,3));
  for(i=1;i<=count/2;i++)
  {
  	// b[i]=(fact(count)/(fact(i)*fact(count-i)))*pow(2,(m-count));
  	//b[i]=nCr(count,i)*power(2,(m-count));
  	b[i] = b[count - i ] = ((count-i+1)* b[i-1]) / i;
  }
  long long x = power(2,m-count);
  for(i=0;i<=count;i++)
  	b[i]*=x;
 
  for(i=0;i<=count;i++)
  {
  	k=(k*power((2+i),b[i]))%MOD;
 
  }
    } 
  printf("%lld\n",k);
 
    }
  return 0;
}
 
 /*  int fact( int x)
   {
     int f=1;
     int i;
     for(i=1;i<=x;i++)
       f=f*i;
     return(f);
   }
   long long ncr(long long x,long long y)
   {
   	int p,i,q=1,r=1;
   	p=x-y;
   	if(y==0 || y==x)
   	return 1;
   	else{
 
   	if(p>y)
   	{
   	  for(i=0;i<y;i++)
   	   {
   		q=q*(x-i);
   		r=r*i;
   		return(q/r);
   	    }
   	}
   	else
   	{
   	  for(i=0;i<p;i++)
   	   {
   		q=q*(x-i);
   		r=r*i;
   		return(q/r);
   	    }
   	}
 
   	}
   }
 
*/
