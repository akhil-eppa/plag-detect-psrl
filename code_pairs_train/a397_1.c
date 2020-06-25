#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
       while(t--)
       {       int n;
       int sum1=0,sum2=0;
              scanf("%d",&n);
           for(int i=0,x,y;i<n;i++)
            {   scanf("%d %d",&x,&y);
                 sum1+=x;
                 sum2+=y;
            }
          printf("%d\n",sum1-sum2);
      }
     

    return 0;
}