#include <stdio.h>
#include<math.h>
int main(void) {
	// your code goes here
	int test,count=0;;
	scanf("%d",&test);
	while(test--){
	    int x1,y1,x2,y2,x3,y3;
	    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	    float d1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	    float d2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	    float d3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	  
	    float a,b,c;
	    if(d1>d2&&d1>d3)
	    {
	        c=d1;
	        a=d2;
	        b=d3;
	    }
	    else if(d2>d1&&d2>d3){
	        c=d2;
	        a=d1;
	        b=d3;
	    }
	    else{
	        c=d3;
	        a=d1;
	        b=d2;
	    }
	    if(round(c*c)==round((a*a)+(b*b)))
	    count++;
	}
	printf("%d\n",count);
	return 0;
}

