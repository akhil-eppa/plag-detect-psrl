#include <stdio.h>
#include <math.h>
int main(void) {
    int t,x1,y1,x2,y2,x3,y3;
    int a,b,c,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&x2);
        scanf("%d",&y2);
        scanf("%d",&x3);
        scanf("%d",&y3);
        a=pow((x2-x1),2)+pow((y2-y1),2);
        b=pow((x3-x2),2)+pow((y3-y2),2);
        c=pow((x1-x3),2)+pow((y1-y3),2);
        if(a==(b+c)||b==(c+a)||c==(a+b))
        {
            count++;
        }
    }
    printf("%d",count);
	// your code goes here
	return 0;
}

