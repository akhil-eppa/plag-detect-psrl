#include <stdio.h>
int main()
{
    int t;
   scanf("%d",&t);
   while(t>0)
   {
   int n,i,j,temp,k,u,index;
   scanf("%d",&n);
   int a[n];
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   scanf("%d",&k);
   u=a[k-1];
   for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
     {
        if(a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
         }
     }
   }
   for(i=0;i<n;i++)
   {
     if(a[i]==u)
     {
      printf("%d\n",i+1);
      break;
     }
   }
   t--;
   }
   return 0;
}