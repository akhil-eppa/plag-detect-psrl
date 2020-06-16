#include <stdio.h>
 
#define MOD 1000000007
 
long long int fact[1001],factinv[1001],c[1000001];
 
void soe()
{
	long long int i,j;
	for(i=2;i<=500000;i++)
	{
		if(c[i]==1)
		{
			for(j=2*i;j<=1000000;j+=i)
			c[j]=0;
		}
	}
}
 
long long int binExpo(long long int y,long long int n,long long int p)
{
    long long int val=1;
    while(n>0)
    {
        if(n%2==1)
            val=(val*y)%p;
        y=(y*y)%p;
        n=n/2;
    }
    return val;
}
 
long long int calcfac(long long int n,long long int x)
{
    if(n==0 || x==0)
    return 1;
    if(x>n/2)
    x=n-x;
    long long int val=1,y=1;
    while(y!=x+1)
    {
        val=((val*n)/y)%(MOD-1);
        n--;
        y++;
    }
    return val;
}
 
long long int nCrModpDP(long long int n,long long int r,long long int p)
{
    long long int c[r+1],i,j,x;
    for(i=1;i<=r;i++)
    c[i]=0;
    c[0]=1;
    if(i<r)
    x=i;
    else
    x=r;
    for(i=1;i<=n;i++)
    {
        for(j=x;j>0;j--)
        c[j]=(c[j]+c[j-1])%p;
    }
    return c[r];
}
 
long long int nCrModpLucas(long long int n,long long int r,long long int p)
{
   if(r==0)
      return 1;
   long long int ni=n%p,ri=r%p;
   return (nCrModpLucas(n/p,r/p,p)*nCrModpDP(ni,ri,p))%p;
}
 
long long int ExtEuc(long long int a,long long int m)
{
    long long int m0=m,x0=0,x1=1,t,q;
    if(m==1)
       return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0)
       x1+=m0;
    return x1;
}
 
long long int findminx(long long int num[],long long int rem[],long long int k)
{
    long long int prod=1,i,result=0;
    for(i=0;i<k;i++)
    prod*=num[i];
    for(i=0;i<k;i++)
    {
        long long int pp=prod/num[i];
        result+=rem[i]*ExtEuc(pp,num[i])*pp;
    }
    return result % prod;
}
 
int main()
{
    long long int t,n,i,j,k,val,val1,val2,cnt,ans;
    scanf("%lld",&t);
    fact[0]=1;
    factinv[0]=1;
    for(i=1;i<=1000;i++)
    {
        fact[i]=(i*fact[i-1])%(MOD/2);
        factinv[i]=(binExpo(i,MOD/2-2,MOD/2)*factinv[i-1])%(MOD/2);
    }
    for(i=2;i<=1000000;i++)
    c[i]=1;
    c[0]=0;
    c[1]=0;
    soe();
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long long int a[n];
    	cnt=0;
    	for(j=0;j<n;j++)
    	{
    		scanf("%lld",&a[j]);
    		if(c[a[j]]==1)
    		cnt++;
    	}
    	ans=1;
    	val1=binExpo(2,n-cnt,MOD-1);
    	for(j=0;j<=cnt;j++)
    	{
    	    long long int num[2],rem[2];
    	    num[0]=2;
    	    rem[0]=nCrModpLucas(cnt,j,2);
    	    num[1]=500000003;
    	    rem[1]=(fact[cnt]*((factinv[j]*factinv[cnt-j])%(MOD/2)))%(MOD/2);
    	    val=findminx(num,rem,2);
    	    val=(val*val1)%(MOD-1);
    	    val2=binExpo(j+2,val,MOD);
    	    ans=(ans*val2)%MOD;
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}