#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
	    int n,k;
	    long long int x,y;
	    scanf("%d",&n);
	    k=2*n;
	    x=0;
	    y=0;
	    int a[k];
	    for(int i=0;i<k;i++)
	    {
	        scanf("%d",&a[i]);
	        if(i%2==0)
	        x = x+a[i];
	        else
	        y = y+a[i];
	    }
	    long long int l=x-y;
	    printf("%lld\n",l);
	}
	return 0;
}

