#include <stdio.h>
 
int main()
{
  int testCases,N;
  int i,j,k,isPrime[1000000];
  isPrime[0]=isPrime[1]=0;
 
  for(i=2;i<=1000000;i++)
      isPrime[i]=1;
 
  for(i=2;i<=sqrt(1000000);i++)
  {
	  if(isPrime[i]==1)
	  {
		  for(j=i*i;j<=1000000;j+=i)
		    isPrime[j]=0;
	  }
  }
 
  for(i=2;i<=1000000;i++)
	  {
			if(isPrime[i]==1 && (i-1)%11==0)
			  isPrime[i]=1;
 
			else
			isPrime[i]=0;	
		}
 
  scanf("%d",&testCases);
 
  while(testCases--)
  { 
	  int flag=1;
	 scanf("%d",&k);
	 for(i=k;i<=1000000;i++)
	    {
			if(isPrime[i]==1)
			{ 
			  printf("%d\n",i);
			  flag=-1;
			  break;
		    }
		}
		if(flag==1)
		 printf("1000033\n");
  }
  return 0;
}