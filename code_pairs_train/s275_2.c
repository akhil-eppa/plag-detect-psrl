// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,g,p,j,i,q1,q2;
	    scanf("%d %d",&g,&p);
	    scanf("%d",&n);
	    for(i=0,q1=0,q2=0;i<n;i++)
	    {
	        scanf("%d",&j);
	        if(j)q1++;
	        scanf("%d",&j);
	        if(j)q2++;
	    }
	    (q1>q2)?(g>p)?printf("%d\n",q1*p+q2*g):printf("%d\n",q1*g+q2*p):(g>p)?printf("%d\n",q2*p+q1*g):printf("%d\n",q1*p+q2*g);
	}
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
 
// Write your code here