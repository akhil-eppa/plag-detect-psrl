/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int c,n,k;
        int count=0;
        scanf("%lld %lld",&n,&k);
        c=k;
        while(c>1)
        {
            c=c/2;
            count++;
        }
        printf("%lld %lld\n",((n-(k%(1LL<<count)))/(1LL<<(count+1))),(((n-(k%(1LL<<count)))/(1LL<<(count)))-1)/2);
    }
    
    return 0;
}