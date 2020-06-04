#include <stdio.h>

int main(void) {
	// your code goes here
	int r,t;
	scanf("%d",&t);
	for(r=0;r<t;r++)
	{
	    int j,i,k,n,c=0;
	    scanf("%d",&n);
	    int a[n];
	    for(i=0;i<n;i++)
	     scanf("%d",&a[i]);
	   scanf("%d",&k);
	   for(i=0;i<n;i++)
	   if(a[i]<a[k-1])
	    c++;
	   printf("%d\n",c+1); 
	    
	}
	return 0;
}

