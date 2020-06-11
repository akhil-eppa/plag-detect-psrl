#include <stdio.h>
#include<stdlib.h>

int comparator(const void *a,const void *b)
{
 int leftx = *(const int *)a; 
 int rightx = *(const int *)b;
 return (leftx-rightx);
}

int main()
{
	long long int tttx;
	scanf("%lld",&tttx);
	
	for(long long int iter=0;iter<tttx;iter++)
	{
		int n,*arr,k,value,pos;
		
		scanf("%d",&n);
		
		arr=(int*)malloc(n*sizeof(int));
		
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
			
		scanf("%d",&k);
		
		value=arr[k-1];
		
		qsort((void*)arr,n,sizeof(int), comparator);
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]==value)
			{
				pos=i+1;
				break;
			}
		}
		
		printf("%d\n",pos);
		
	}
	
	return 0;
}
 
