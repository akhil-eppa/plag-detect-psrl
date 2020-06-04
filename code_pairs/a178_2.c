#include <stdio.h>
double abs(double x)
{
	if (x<0)
		return -x;
	else
		return x;
}
double quad(double x,double y)
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
double steps(double x,double y,double q)
{
	double a=0;double b=0;double count=0;
	printf("(0,0)->");
	switch (q)
	{
		case 1:while (a!=x || b!=y)
		       {
			       if (((a+1)<=x) && ((b+1)<=y))
				       {a+=1;b+=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 2:while (a!=x || b!=y)
		       {
			       if (((a-1)>=x) && ((b+1)<=y))
				       {a-=1;b+=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 3:while (a!=x || b!=y)
		       {
			       if (((a-1)>=x) && ((b-1)>=y))
				       {a-=1;b-=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 4:while (a!=x || b!=y)
		       {
			       if (((a+1)<=x) && ((b-1)>=y))
				       {a+=1;b-=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
	}
	printf("\n\n");
	return (count);
}		
int main()
{
	double x1=0;double y1=0;double x2,y2;double q,s;
	printf("Enter x2 and y2:");
	scanf("%f %f",&x2,&y2);
	if (x2==0)
		printf("%f\n",abs(y2));
	else if(y2==0)
		printf("%f\n",abs(x2));
	else
	{
		q=quad(x2,y2);
		printf("%f\n",q);
		s=steps(x2,y2,q);
		printf("Number of steps to be taken are: %f\n",s);
		}
}