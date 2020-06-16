#include <stdio.h>
int isprime(int);
int main()
{
 int T,t,N;
 scanf("%d",&T);
 for(t=0;t<T;t++)
	{
	 scanf("%d",&N);
	 int arr[N],prime[N],i,j,sum,result=2;
	 for(i=0;i<N;i++)
		{
		 scanf("%d",&arr[i]);
		 prime[i]=isprime(arr[i]);
		}
	 while(N>0)
		{
		 for(i=0;i<N;i++)
			{
			 sum=0;
			 for(j=i;j<N;j++)
				 sum=sum+prime[j];
			 sum=sum+2;
			 result=result*sum;
			}
		 N--;
		}
	 printf("%d\n",result);
	}
}
int isprime(int a)
{
 if(a==0||a==1)
	return 0;
 int i;
 for(i=2;i<=sqrt(a);i++)
	{
	 if(a%i==0)
		return 0;
	}
 return 1;
}