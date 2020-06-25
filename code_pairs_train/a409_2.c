#include <stdio.h>

int main(void) {
	// your code goes here
	int N,i,x1,y1,x2,y2,x3,y3,s=0,a,a1,b,b1,c,c1;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
	    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	    a=x1-x3;
	    a1=y1-y3;
	    b=x2-x3;
	    b1=y2-y3;
	    c=x1-x2;
	    c1=y1-y2;
	    if(((a*a+a1*a1)==(b*b+b1*b1)+(c*c+c1*c1))||((b*b+b1*b1)==(a*a+a1*a1)+(c*c+c1*c1))||((c*c+c1*c1)==(b*b+b1*b1)+(a*a+a1*a1)))
	    s=s+1;
	}
	printf("%d",s);
	s=0;
	return 0;
}

