#include<stdio.h>

int Test(int x1,int y1,int x2,int y2,int x3,int y3)

{
	int a=x2-x1;
	int b=y2-y1;
	int c=x3-x1;
	int d=y3-y1;
 	 	  	 	
 	int e=(a*c)+(b*d);
 	
 	
 	return e;
}


int main()
{
	int TCase,count=0;
	scanf("%d",&TCase);
	
	
	int x1,y1,x2,y2,x3,y3;
	
	for(int i=0;i<TCase;i++)
		{
		 scanf("%d",&x1);
		 scanf("%d",&y1);
		 scanf("%d",&x2);
		 scanf("%d",&y2);
		 scanf("%d",&x3);
		 scanf("%d",&y3);  
		 
		 if((Test(x2,y2,x1,y1,x3,y3)==0))
		 	{count++;}
		 				 
 	 
		 if((Test(x1,y1,x2,y2,x3,y3)==0))
		 	{count++;}
		 	
		 if((Test(x3,y3,x2,y2,x1,y1)==0))
		 	{count++;} 
		 	
		 
		 	
		 	
		 }
		 
		 
		 
	printf("%d",count);
	
        return 0;
        
}       		 		 
 