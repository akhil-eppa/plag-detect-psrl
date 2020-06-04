#include <stdio.h>

int main(void) {
	 int t;
	 scanf("%d\n",&t);
	 while(t--){
	     int g;
	     scanf("%d\n",&g);
	     while(g--){
	         int i,q;
	         long long int n;
	         scanf("%d%lld%d\n",&i,&n,&q);
	         if(n%2==0)
	         {
	             printf("%lld\n",n/2);
	         }
	         else
	         {
	             if(((i==1)&&(q==1))||((i==2)&&(q==2)))
	             {
	                 printf("%lld\n",n/2);
	                 
	             }
	             else
	             {
	                 printf("%lld\n",((n/2)+1));
	             }
	         }
	     }
	 }
	return 0;
}