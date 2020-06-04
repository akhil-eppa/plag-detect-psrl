#include <stdio.h>
int abs(int xa)
{
	if (xa<0)
		return -xa;
	else
		return xa;
}
int quad(int xa,int ya)
{
	if (xa>0 && ya>0)
		return 1;
	else if (xa<0 && ya>0)
		return 2;
	else if (xa<0 && ya<0)
		return 3;
	else
		return 4;
}
int steps(int xa,int ya,int qx)
{
	int a=0;int b=0;int cnt=0;
	printf("(0,0)->");
	switch (qx)
	{
		case 1:while (a!=xa || b!=ya)
		       {
			       if (((a+1)<=xa) && ((b+1)<=ya))
				       {a+=1;b+=1;cnt+=1;}
			       else if((a+1)<=xa)
				       {a+=1;cnt+=1;}
			       else
				       {b+=1;cnt+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 2:while (a!=xa || b!=ya)
		       {
			       if (((a-1)>=xa) && ((b+1)<=ya))
				       {a-=1;b+=1;cnt+=1;}
			       else if((a-1)>=xa)
				       {a-=1;cnt+=1;}
			       else
				       {b+=1;cnt+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 3:while (a!=xa || b!=ya)
		       {
			       if (((a-1)>=xa) && ((b-1)>=ya))
				       {a-=1;b-=1;cnt+=1;}
			       else if((a-1)>=xa)
				       {a-=1;cnt+=1;}
			       else
				       {b-=1;cnt+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
		case 4:while (a!=xa || b!=ya)
		       {
			       if (((a+1)<=xa) && ((b-1)>=ya))
				       {a+=1;b-=1;cnt+=1;}
			       else if((a+1)<=xa)
				       {a+=1;cnt+=1;}
			       else
				       {b-=1;cnt+=1;}
				   printf("(%d,%d)->",a,b);
		       }
		       break;
	}
	printf("\n\n");
	return (cnt);
}		
int main()
{
	int xp1=0;int xy1=0;int xp2,yp2;int qx,sx;
	printf("Enter xp2 and yp2:");
	scanf("%d %d",&xp2,&yp2);
	if (xp2==0)
		printf("%d\n",abs(yp2));
	else if(yp2==0)
		printf("%d\n",abs(xp2));
	else
	{
		qx=quad(xp2,yp2);
		printf("%d\n",qx);
		sx=steps(xp2,yp2,qx);
		printf("Number of steps to be taken are: %d\n",sx);
		}
}