#include <stdio.h>
int quad(int xxx,int y)
{
	if (xxx>0 && y>0)
		return 1;
	else if (xxx<0 && y>0)
		return 2;
	else if (xxx<0 && y<0)
		return 3;
	else
		return 4;
}
int abs(int xxx)
{
	if (xxx<0)
		return -xxx;
	else
		return xxx;
}
int steps(int xxx,int y,int q)
{
	int a=0;int b=0;int counter=0;
	printf("(0,0)->");
	switch (q)
	{
		case 1:while (a!=xxx || b!=y)
		       {
			       if (((a+1)<=xxx) && ((b+1)<=y))
				       {a+=1;b+=1;counter+=1;}
			       else if((a+1)<=xxx)
				       {a+=1;counter+=1;}
			       else
				       {b+=1;counter+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 2:while (a!=xxx || b!=y)
		       {
			       if (((a-1)>=xxx) && ((b+1)<=y))
				       {a-=1;b+=1;counter+=1;}
			       else if((a-1)>=xxx)
				       {a-=1;counter+=1;}
			       else
				       {b+=1;counter+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 3:while (a!=xxx || b!=y)
		       {
			       if (((a-1)>=xxx) && ((b-1)>=y))
				       {a-=1;b-=1;counter+=1;}
			       else if((a-1)>=xxx)
				       {a-=1;counter+=1;}
			       else
				       {b-=1;counter+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
		case 4:while (a!=xxx || b!=y)
		       {
			       if (((a+1)<=xxx) && ((b-1)>=y))
				       {a+=1;b-=1;counter+=1;}
			       else if((a+1)<=xxx)
				       {a+=1;counter+=1;}
			       else
				       {b-=1;counter+=1;}
				   printf("(%f,%f)->",a,b);
		       }
		       break;
	}
	printf("\n\n");
	return (counter);
}		
int main()
{
	int x1=0;int y1=0;int x2,y2;int q,s;
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