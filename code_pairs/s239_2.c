#include<stdio.h>
#include<math.h>
void main()
{ int i,j,k,n,c,d,t=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
     { scanf("%d",&k);
       for(j=4*k,t=0; ;j++)
          { if(j>4)
            c=log(j/5.0)/(log(5)*1.0)+1;
            else
            c=1;
            for(t=1,d=0;t<=c;t++)
               d=d+j/pow(5,t);
            t=0;
            if(d>k)
              { printf("0");
                t=1;
                break;
              }
            if(d==k)
              { printf("5\n%d ",j);
                break;
              }
          }
       if(t==0)
         {
           for(c=1;c<5;c++)
              { printf("%d ",j+c);
              }
         }
       printf("\n");
     }
}