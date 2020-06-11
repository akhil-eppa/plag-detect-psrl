#include <stdio.h>
#include<stdlib.h>

int comparator(const void *a,const void *b)
{
 int r = *(const int *)b;
 int l = *(const int *)a; 
 return (l-r);
}

int main()
{
	long int t;
	scanf("%ld",&t);
	
	for(long int iter=0;iter<t;iter++)
	{
		int n,*arr,val,pos,k;
		
		scanf("%d",&n);
		
		arr=(int*)malloc(n*sizeof(int));
		
		for(int i=0;n>i;++i)
			scanf("%d",arr+i);
			
		scanf("%d",&k);
		
		val=arr[k-1];
		
		qsort((void*)arr,n,sizeof(int), comparator);
		
		for(int i=0;n>i;++i)
		{
			if(val==arr[i])
			{
				pos=i+1;
				break;
			}
		}
		
		printf("%d\n",pos);
		
	}
	
	return 0;
}
 
