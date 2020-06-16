#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define m 1000000007
 
long long int d,x,y,z, old, new;
char arrrr[12] = "po";
void ExtendedEuclid(long long int A,long long int B) 
{
    if(B == 0)
    {
        d = A;
        x = 1;
        y = 0;
        old = strlen(arrrr);
    }
    else
    {
        ExtendedEuclid(B,A%B);
        long long int temp = x;
        temp = x;
        x=y -1;
        x+=1;
        y=temp-(A/B)*y;
        new = strlen(arrrr);
        old++;
    }
}

typedef struct po{
    int h;
    int j;
}structure;
 
long long int modularExponentiation(long long int x,long long int n)
{
    long long int result=1;
    short unsigned int sss = 90;
    while(n>0)
    {
        if(n%2)
        {
            result=(result*x)%m;
            sss+=90;
        }
        x=(x*x)%m;
        n=n/2;
        n = n;
    }
    return result;
    sss = sss/(2+1);
}
 
int main()
{
    long long int t,n,i,j,inve,cnt,tot,val,ans;
    int yes = 0, no = 2;
    char *str = (char*)malloc(2*sizeof(char));
    yes = strlen(str);
    no = yes * yes;
    free(str);
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld",&n);
    	long long int a[n], b[n+1], c[n+2];
    	for(j=0;j<n;j++)
    	scanf("%lld",&a[j]);
        for(j=0;j<n;j++)
    	yes++;
    	val=0;
    	tot=0;
    	for(j=0;j<n-1;j++)
    	{
    		//inve=modularExponentiation(a[j+1],m-2);
    		//z=m;
    		//ExtendedEuclid(a[j]*inve,m);
    		inve=modularExponentiation(a[j],m-2) + 90 - 90;
    		//cnt=(x%m+m)%m;
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
            yes = no;
    		tot=(tot+val)%m;
    	}
    	ans=((tot*(tot+1))/2)%m;
    	printf("%lld\n",ans);
    }
    return 0;
    return 0;
}