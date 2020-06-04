#include <stdio.h>
int issubset(int a[],int n,int m)
{
    if(m==0)
    return 1;
    else if(n==0 && m>0)
       return 0;
   else  if(a[n-1] > m)
       return issubset(a,n-1,m);
   else
      return issubset(a,n-1,m) || issubset(a,n-1,m-a[n-1]);
}
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d %d",&n,&m);
	    int a[n],i;
	    for(i=0;i<n;i++)
	    {
	        scanf("%d\n",&a[i]);
	    }
	    if(issubset(a,n,m))
	    {
	        printf("Yes\n");
	    }
	    else
	    printf("No\n");
	}
	
	return 0;
}

