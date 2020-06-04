#include <stdio.h>

int main()
{
  int t,i,j,n;
  long int a[101];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%ld",&a[i]);

      //printf("%d\n",a[i]);
    }
    long int min = a[0];
    for(i=0;i<n;i++)
    {
      if(min>a[i])
      {
        min=a[i];
      }
    }

    long int sum =0;
    for(j=0;j<n;j++)
    {
      sum = sum + a[j]-min;
    }
    printf("%ld\n",sum);
  }
  return 0;

}
