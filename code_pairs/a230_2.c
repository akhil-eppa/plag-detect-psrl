#include <stdio.h>

int main(void) {
	// your code goes here
	int t,i;
	scanf("%d",&t);
    int a[21];
	for(i=0;i<t;i++)
	{
	    int n,j,k,m;
	    scanf("%d %d",&n,&m);
	    int count=0;
	    int dp[21][20001]={0};
	    for( j=0;j<n;j++)
	    {
	        scanf("%d",&a[j]);
	    }
	        dp[0][0]=1;
		for(j=1;j<=n;j++)
	    {
	    	dp[j][0]=1;
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
			    {
    				if(k-a[j-1]>=0)
    				{
    				    dp[j][k] = dp[j-1][k-a[j-1]]||dp[j-1][k];
    				}
    				else
    				    dp[j][k] = dp[j-1][k];
			    }
			}


		 	if(dp[n][m]==1)
			 {

			    printf("Yes\n");

			}
	    else
		{
			printf("No\n");
		}
	}
}