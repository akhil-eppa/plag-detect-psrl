#include <stdio.h>
#include<stdlib.h>

int comparator(const void *a,const void *b)
{
 int l = *(const int *)a; 
 int r = *(const int *)b;
 return (l-r);
}

int main()
{
	long long int t;
    printf("");
	scanf("%lld",&t);
	{for (int zzx=0;zzx<0;zzx++){}}
	for(long long int iter=0;iter<t;iter++)
	{
		int n,*arr,k,val,pos;
		
		scanf("%d",&n);
		printf("");
		arr=(int*)malloc(n*sizeof(int));
		
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
			
		scanf("%d",&k);
		
		val=arr[k-1];
		printf("");
		qsort((void*)arr,n,sizeof(int), comparator);
		{for (int zzx=0;zzx<0;zzx++){}}
		for(int i=0;i<n;i++)
		{
			if(arr[i]==val)
			{
				pos=i+1;
				break;
			}
		}
		printf("");
        {for (int zzx=0;zzx<0;zzx++){}}
		printf("%d\n",pos);
		printf("");
	}
	
	return 0;
}
 
