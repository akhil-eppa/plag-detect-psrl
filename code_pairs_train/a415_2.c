#include <stdio.h>
#include <math.h>
int main(void) 
{
	long int n,i,p=0;
	int x1,y1,x2,y2,x3,y3,a,b,c;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	    a=pow((x2-x1),2)+pow((y2-y1),2);
	    b=pow((x3-x2),2)+pow((y3-y2),2);
	    c=pow((x3-x1),2)+pow((y3-y1),2);
	    if(a>=b && a>=c)
	    {
	        if(a==(b+c))
	            p+=1;
	    }
	    if(a<=b && b>=c)
	    {
	        if(b==(a+c))
	            p+=1;
	    }
	    if(c>=b && a<=c)
	    {
	        if(c==(b+a))
	            p+=1;
	    }
	}
	printf("%ld",p);
	return 0;
}

