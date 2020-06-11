#include <stdio.h>//beggars method of distribution of identical objects.

int main(void) {
   int t;
   scanf("%d",&t);
   long int n,k;
   // scanf("%ld%ld",&n,&k);
   while(t--)
   {
       scanf("%ld%ld",&n,&k);
       long long int prod=1;
      //  long long int prod2=1;
       for(int i=1;i<=(k-1);i++)
       {
        prod=(prod)*(n+i-k);
        prod=prod/i;
         // prod=((n-i)/(k-i))*prod;
       }
        
         printf("%lld\n",prod);
   }
	// your code goes here
	return 0;
}
