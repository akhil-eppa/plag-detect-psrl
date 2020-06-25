#include <stdio.h>
#include<stdlib.h>
int main(void) {
	int t;
	scanf("%d",&t);
	for(int x=1; x<=t;x++)
	{
		int n;
		scanf("%d",&n);
		int *ar;
	
		ar=(int*)malloc(sizeof(int)*n);
			int temp1=0,temp2=0,temp3=0;
		for(int k=0;k<n;k++)
		{
			scanf("%d",&ar[k]);
		
			 if(ar[k]%3==0)
			 {
			 	temp1++;
			 }
			 else
			 {
			 if(ar[k]%3==1)
			 {
			 	temp2++;
			 }
			 else
			 {
			 	temp3++;
			 }
			
			 }
		}
		if(temp1==n)
		{
			printf("0\n");
		}
		else
		{
		if(temp2==1&&temp3==1)
		{
			printf("%d\n",(n-1));
		}
		else
		{
		printf("%d\n",n);
		}
		}
	}
	return 0;
}
