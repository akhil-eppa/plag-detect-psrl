#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
   int N,x=0;
   scanf("%d",&N);
   while(N!=0)
   {
       int x1,x2,x3,y1,y2,y3,i,j;
       float temp,d[3];
       scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
       d[0]=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
       d[1]=((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2));
       d[2]=((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3));
       for(i=0;i<2;i++)
       {
           for(j=0;j<3-i-1;j++)
           {
               if(d[j]>d[j+1])
               {
                   temp=d[j];
                   d[j]=d[j+1];
                   d[j+1]=temp;
               }
           }
       }
       if((d[0]+d[1])==d[2])
        x++;
       N--;
   }
   printf("%d\n",x);
}
