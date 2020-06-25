#include<stdio.h>
    int gcd(int a,int b)
    {
    	if(b==0)
    	{
    		return a;
    	}
    	else
    	{
    		return gcd(b,a%b);
    	}
    }
    int main()
    {
    	int answer,i,a,number,remainder=0,t,b;
    	char ar[300];
    	scanf("%d",&t);
    while(t--)
    {
    	
    	scanf("%d",&a);
    	scanf("%s",ar);
    	remainder=0;
    	if(a==0)
    	{
    		printf("%s\n",ar);
    	}
    	else
    	{
    		for(i=0;ar[i]!='\0';i++)
    		{
    			number=remainder*10+(ar[i]-'0');
                          remainder=number%a;
    		}
    		b=remainder;
    		answer=gcd(a,b);
    		printf("%d\n", answer);
    	
    	}
      
    }
    	return 0;
    	}	  