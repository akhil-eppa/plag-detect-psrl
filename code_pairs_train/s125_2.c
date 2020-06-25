#include <stdio.h>
 
#define m 1000000007

/*
    one macro is already defined
    value of m is 1000000007 */
 
long long int d,x,y,z; //there are 4 global variables.
void ExtendedEuclid(long long int A,long long int B) 
{
    if(B == 0) //second number is zero
    {
        d = A; //d is equal to first number
        x = 1; //x value is 1
        y = 0; //y value is 0
    }
    else
    {
        ExtendedEuclid(B,A%B); //Recursion until B is zero
        long long int temp = x;
        //x and y are made equal
        x=y;
        y=temp-(A/B)*y;
    }
}
 
long long int modularExponentiation(long long int x,long long int n)
{
    long long int result=1; //result is initialised to 1.
    while(n>0)
    {
        if(n%2==1) //n value is odd
            result=(result*x)%m;
        x=(x*x)%m;
        //n is halved
        n=n/2;
    }
    return result; //result is returned.
}
 
int main()
{
    long long int t,n,i,j,inve,cnt,tot,val,ans; //all variables are declared here
    scanf("%lld",&t); //Take number of test cases as input
    for(i=1;i<=t;i++) //for each test case...
    {
    	scanf("%lld",&n); //input value of n
        //integer array of length n is created.
    	long long int a[n]; 
    	for(j=0;j<n;j++) //Another for loop to scan array values.
    	scanf("%lld",&a[j]);
    	val=0;
    	tot=0;
    	for(j=0;j<n-1;j++) //Third for loop
    	{
    		inve=modularExponentiation(a[j],m-2); //Extra comments are added 1 2 3 4.
    		cnt=(a[j+1]*inve)%m;
    		val=((cnt*(cnt+1))/2)%m;
    		tot=(tot+val)%m;
            //End of inner 4 loop
    	}
    	ans=((tot*(tot+1))/2)%m; //Special characters: !@#$%^&*9)()
    	printf("%lld\n",ans); //\n
    }
    return 0;
}

//This is the end.