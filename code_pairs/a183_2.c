#include <stdio.h>
int abs(int x)
{
	if (x<0)
		return -x;
	else
		return x;
}
int quad(int x,int y)
{
	if (x>0 && y>0)
		return 1;
	else if (x<0 && y>0)
		return 2;
	else if (x<0 && y<0)
		return 3;
	else
		return 4;
}
int steps(int x,int y,int q)
{
	int a=0;int b=0;int count=0;
	printf("(0,0)->");
	switch (q)
	{
		case 1:for (int i=1;a!=x || b!=y;i++)
		       {
			       if (((a+1)<=x) && ((b+1)<=y))
				       {a+=1;b+=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 2:for (int i=1;a!=x || b!=y;i++)
		       {
			       if (((a-1)>=x) && ((b+1)<=y))
				       {a-=1;b+=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 3:for (int i=1;a!=x || b!=y;i++)
		       {
			       if (((a-1)>=x) && ((b-1)>=y))
				       {a-=1;b-=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 4:for (int i=1;a!=x || b!=y;i++)
		       {
			       if (((a+1)<=x) && ((b-1)>=y))
				       {a+=1;b-=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
	}
	printf("\n\n");
	return (count);
}		
int main()
{
	int x1=0;int y1=0;int x2,y2;int q,s;
	printf("Enter x2 and y2:");
	scanf("%d %d",&x2,&y2);
	if (x2==0)
		printf("%d\n",abs(y2));
	else if(y2==0)
		printf("%d\n",abs(x2));
	else
	{
		q=quad(x2,y2);
		printf("%d\n",q);
		s=steps(x2,y2,q);
		printf("Number of steps to be taken are: %d\n",s);
		}
}