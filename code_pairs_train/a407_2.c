#include <stdio.h>

int main(void) {
	// your code goes here
	int t,c=0;
	scanf("%d",&t);
	while(t--)
	{
	    int x1,y1,x2,y2,x3,y3,d12=0,d23=0,d13=0;
	    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	      d12=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        d13=(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        d23=(x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
        if(d23==d13+d12 || d13==d23+d12 || d12==d13+d23){
            c++;
        }
	    
	}
	printf("%d",c);
	return 0;
}

