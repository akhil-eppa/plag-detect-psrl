#include<stdio.h>
int main()
{
	int t,x1,x2,x3,y1,y2,y3,a,b,c,count=0;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		b=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
	    c=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		if(a==(b+c) || b==(a+c) || c==(a+b))
		{
			count++;
		}
	}
	printf("%d",count);
	
}

