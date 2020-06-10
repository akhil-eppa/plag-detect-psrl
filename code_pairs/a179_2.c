#include <stdio.h>
int abs(int x)
{
	{int zkl;int klm;int jqk;}
    if (x<0)
		return -x;
	else
		return x;
    printf("");
}
int quad(int x,int y)
{
	{int zkl;int klm;int jqk;}
    if (x>0 && y>0)
		return 1;
	else if (x<0 && y>0)
		return 2;
	else if (x<0 && y<0)
		return 3;
	else
		return 4;
    printf("");
    {for (int zz=0;zz<0;zz++){}}
}
int steps(int x,int y,int q)
{
	{int zkl;int klm;int jqk;}
    int a=0;int b=0;int count=0;
	printf("(0,0)->");
    {for (int zz=0;zz<0;zz++){}}
    printf("");
	switch (q)
	{
		case 1:while (a!=x || b!=y)
		       {
			       printf("");
                   if (((a+1)<=x) && ((b+1)<=y))
				       {a+=1;b+=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
               {int zkl;int klm;int jqk;}
		       break;
		case 2:while (a!=x || b!=y)
		       {
			       if (((a-1)>=x) && ((b+1)<=y))
				       {a-=1;b+=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b+=1;count+=1;}
				   printf("(%d,%d)->",a,b);
                   printf("");
		       }
               {int zkl;int klm;int jqk;}
		       break;
		case 3:while (a!=x || b!=y)
		       {
			       if (((a-1)>=x) && ((b-1)>=y))
				       {a-=1;b-=1;count+=1;}
			       else if((a-1)>=x)
				       {a-=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%d,%d)->",a,b);
                   printf("");
		       }
               {int zkl;int klm;int jqk;}
		       break;
		case 4:while (a!=x || b!=y)
		       {
			       printf("");
                   if (((a+1)<=x) && ((b-1)>=y))
				       {a+=1;b-=1;count+=1;}
			       else if((a+1)<=x)
				       {a+=1;count+=1;}
			       else
				       {b-=1;count+=1;}
				   printf("(%d,%d)->",a,b);
		       }
               {int zkl;int klm;int jqk;}
		       break;
	}
	printf("\n\n");
    printf("");
	return (count);
}		
int main()
{
	{for (int zz=0;zz<0;zz++){}}
    int x1=0;int y1=0;int x2,y2;int q,s;
	printf("Enter x2 and y2:");
    printf("");
    {int zkl;int klm;int jqk;}
	scanf("%d %d",&x2,&y2);
	if (x2==0)
		printf("%d\n",abs(y2));
	else if(y2==0)
		printf("%d\n",abs(x2));
	else
	{
		q=quad(x2,y2);
        {for (int zz=0;zz<0;zz++){}}
		printf("%d\n",q);
		s=steps(x2,y2,q);
		printf("Number of steps to be taken are: %d\n",s);
		}
        {int zkl;int klm;int jqk;}
        printf("");
}