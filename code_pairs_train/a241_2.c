#include<stdio.h>
#include<stdlib.h>
int main()
{
   int t,i,n,j,min=0,p;
   scanf("%d",&t);
   while(t--)
   {
    int a[5000];
   scanf("%d",&n);
for(i=0;i<n;i++)
  scanf("%d",&a[i]);
   min=abs(a[0]-a[1]);
   for(i=0;i<n-1;i++)
   {
   for(j=i+1;j<n;j++)
   {
       p=abs(a[i]-a[j]);
      if(min>p)
       min=p;
   }
   }
   printf("%d\n",min);
   }
  return 0;
}