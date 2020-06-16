#include <stdio.h>
#include <math.h>
 
int binarysearch(long long int k)
{
	long long int start=5,end=400005,mid,i,t,f,answer=0;
	while(start<end)
	{
		mid=(start+end)/2;
		t=0;
		i=1;
		while(1)
		{
			f=mid/pow(5,i);
 
			if(f==0)
			{
				break;
			}
			t+=f;
			i++;
		}
		if(t==k)
		{
			answer=mid;
			end=answer;
		}
		else if(t<k)
		{
			start=mid+1;
		}
		else
			end=mid-1;
			
	}
	
	return answer;
}
int main(){
	int testCases;
	long long int temp,j=1,n,result,g,res=0;
	int i;
	scanf("%d",&testCases);
	for(i=0;i<testCases;i++)
	{
		scanf("%lld",&n);
		result=binarysearch(n);
		if(result==0)
			printf("0\n");
		else
		{
			temp=result+4;
			printf("%lld\n",5);
			long long int d;
			for(d=result;d<=temp;d++)
			{
				printf("%lld ",d);
			}
			printf("\n");
		}
	}
}
