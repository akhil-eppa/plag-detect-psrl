/* */
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
long int borrower,lender,amount,minTransaction=0,n,m,a[100005]={0},i;
 
 
scanf("%ld %ld",&n,&m);			// Reading input from STDIN
 
    for( i=0;i<m;i++)
	  {
		scanf("%ld %ld %ld",&borrower,&lender,&amount);
		a[borrower]+=amount;
		a[lender]-=amount;
      }  
	  
	  for( i=1;i<=n;i++)
	   if(a[i]>0)
	   minTransaction+=a[i];           			
			
			printf("%ld",minTransaction);		     // Writing output to STDOUT
 
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
/**/
 
// Write your code here
