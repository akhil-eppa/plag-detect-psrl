#include <stdio.h>

int main(void) {
	// your code goes here
	int tc,i,no,p[10000];
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
	    scanf("%d",&no);
	    int j,k,cnt=1,max;
	    for(j=0;j<no;j++)
	        scanf("%d",&p[j]);
	    max=p[0];
	    for(j=1;j<no;j++)
	    {
	        if(p[j]<=max)
	        {
	            max=p[j];
	            cnt++;
	        }
	    }
	    printf("%d\n",cnt);
	}
	return 0;
}

