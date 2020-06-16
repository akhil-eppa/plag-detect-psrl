#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,m,in,out,ans=0,curr=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&in,&out);
		curr=curr+in-out;
		if(curr>=m)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}