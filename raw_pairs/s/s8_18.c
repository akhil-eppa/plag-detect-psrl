/**/
// Sample code to perform I/O:
#include <stdio.h>
#include <math.h>
int main()
{
	int T,n,m,k,sum=0;
	long long int count=0;
	int b=pow(10,9)+7;
	scanf("%d", &T);              			// Reading input from STDIN
	
	for ( int i=0;i<T;i++)
	{	int loops=0;
		scanf("%d %d %d",&n,&m,&k);
		int a[n*m];
		for (int j=0;j<n;j++)
		{
			scanf("%d ",&a[j]);
			// for(int p=1;p<m;p++)
			// a[j+p*n]=a[j];
		}
       int c=0;
		for(int j=0;j<n*m;j++)
		{   
			int index=j+1;
			if(a[j%n]<=k)
			{
				count=(count+1)%b;
				sum=a[j%n] +a[index%n];
 
				while(index<(n*m)&&sum<=k)
				{
					index++;
					count=(count+1)%b;
				 sum+=a[index%n];
				}
				sum=0;
			}
			
		}
		printf("%lld\n",count);
		count=0;
	}
	
	
	
	       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
/**/
 
// Write your code here