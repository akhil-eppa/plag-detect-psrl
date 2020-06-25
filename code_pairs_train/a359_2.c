#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int sum=0,min=100000;
	for(int i=0;i<n;i++)
	{
	    sum+=a[i];
	    if(a[i]<min)min=a[i];
	}
    printf("%d\n",sum-(n*min));
	}
	return 0;
}

