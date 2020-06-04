#include <stdio.h>
#include<math.h>
int main(void) {
	// your code goes here
	int t,n,m,a[1048575],num,i,j,k;
	scanf("%d",&t);
	while(t--)
	{ j=0;k=0;
	    scanf("%d%d",&n,&m);
	    while(n--)
	    {
	        scanf("%d",&num);
	        a[j]=num;j++;
	        for(i=0;i<k;i++)
	        {
	            a[j]=a[i]+num;j++;
	        }
	        k=j;
	    }
	    for(i=0;i<j;i++)
	    if(a[i]==m)
	    {printf("Yes\n");break;}
	    if(i==j)
	    printf("No\n");
	}
	return 0;
}

