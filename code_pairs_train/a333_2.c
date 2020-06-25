#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t>0)

  {
     long int n,min,temp,q,k;
     scanf("%ld",&n);
     min = n-1;
     k = sqrt(n);
     for(long int i=2;i<=(k+1);i++)
     {
       if(n%i==0)
       {
         q = n/i;
         temp = q-i;
         if(temp<0)
           temp = (-1)*temp;
           if(temp<min)
             min = temp;

       }
     }
     printf("%ld\n",min);



     t--;
  }
      
  


  return 0;
}