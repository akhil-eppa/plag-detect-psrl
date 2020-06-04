#include <stdio.h>
int abs(int x)
{
	if (0>x)
		return -x;
	else
		return x;
}
int quad(int x,int y)
{
	if (y>0 && x>0)
		return 1;
	else if (y>0 && x<0)
		return 2;
	else if (y<0 && x<0)
		return 3;
	else
		return 4;
}
int steps(int x,int y,int q)
{
	int a=0;int count=0;int b=0;
	printf("(0,0)->");
	switch (q)
	{
		case 1:while (b!=y || a!=x)
		       {
			       if ((x>=(a+1)) && (y>=(b+1))
				       {b+=1;a+=1;count+=1;}
			       else if(x>=(a+1))
				       {count+=1;a+=1;}
			       else
				       {count+=1;b+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 2:while (a!=x || b!=y)
		       {
			       if (((b+1)<=y)&&((a-1)>=x))
				       {a-=1;count+=1;b+=1;}
			       else if((x<=(a-1))
				       {a-=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 3:while (b!=y || a!=x)
		       {
			       if (((b-1)>=y)&&((a-1)>=x))
				       {a-=1;count+=1;b-=1;}
			       else if(x<=(a-1)
				       {a-=1;count+=1;}
			       else
				       {count+=1;b-=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 4:while (b!=y||a!=x)
		       {
			       if (((b-1)>=y)&&((a+1)<=x))
				       {a+=1;b-=1;count+=1;}
			       else if(x>=(a+1))
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
	int x1=0;int y1=0;int q,s;int x2,y2;
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