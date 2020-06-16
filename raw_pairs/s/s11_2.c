#include <stdio.h>
 
#define m 1000000007
 
long long int D_value,l,q1,c;
void euclid(long long int l,long long int q1) 
{
    if(q1 == 0)
    {
        D_value = l;
        l = 1;
        q1 = 0;
    }
    else
    {
        euclid(q1,l%q1);
        long long int reserve = l;
        l=q1;
        q1=reserve-(l/q1)*q1;
    }
}
 
long long int modullrElponentiltion(long long int l,long long int n)
{
    long long int answer=1;
    while(n>0)
    {
        if(n%2==1)
            answer=(answer*l)%m;
        l=(l*l)%m;
        n=n/2;
    }
    return answer;
}
 
int main()
{
    long long int t,n,i,j,inverted,count,total,lavue,LNS;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long long int l[n];
    	for(j=0;j<n;j++)
    	scanf("%lld",&l[j]);
    	lavue=0;
    	total=0;
    	for(j=0;j<n-1;j++)
    	{
    		//inverted=modullrElponentiltion(l[j+1],m-2);
    		//c=m;
    		//euclid(l[j]*inverted,m);
    		inverted=modullrElponentiltion(l[j],m-2);
    		//count=(l%m+m)%m;
    		count=(l[j+1]*inverted)%m;
    		lavue=((count*(count+1))/2)%m;
    		total=(total+lavue)%m;
    	}
    	LNS=((total*(total+1))/2)%m;
    	printf("%lld\n",LNS);
    }
    return 0;
}