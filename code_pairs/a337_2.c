#include <stdio.h>
#include <math.h>

int main()
{
  // printf("The programme begins here\n");
   int t;
   scanf("%d",&t);
   while(t){
   int n,i,max,x;
   scanf("%d",&n);
   if(n==1){
      printf("\n0\n");
       }
   else{
    for(i=1;i<=sqrt(n);i++){
        if(n%i==0){
            max=i;
        }
    }
   x=n/max;
   printf("\n%d\n",x-max);
   }
   t--;
   }
}
