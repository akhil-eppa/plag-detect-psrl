#include<stdio.h>
int main()
{
	int t,k;
	scanf("%d",&t);
       for(k=0;k<t;k++)
       {
       	int g,i,n,j,q,a=0;
		scanf("%d",&g);
		for(j=0;j<g;j++)
		{
		scanf("%d %d %d",&i,&n,&q);
	       a=n/2;
		if(i==1)
		{
		  if(q==1)
		  printf("%d\n",a);
		  else
		  printf("%d\n",n-a);
		}
		else
		{
		 if(q==1)
		 printf("%d\n",n-a);
		 else
		 printf("%d\n",a);	
		} 
	       }
	}
	return 0;
}