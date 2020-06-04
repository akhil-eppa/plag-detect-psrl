#include <stdio.h>

int main(void) {
	int x,y,k,n,t,sum;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    int sum=0;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&k);
    scanf("%d",&n);
    int arr[n][2],m;
    m=x-y;
    for(int j=0;j<n;j++)
    {
     scanf("%d %d",&arr[j][0],&arr[j][1]);
    }
    for(int p=0;p<n;p++)
    {
      if((arr[p][0]>=m)&&(arr[p][1]<=k))
      {
        sum++;
      }
    }
    if(sum>0)
    {
      printf("LuckyChef\n");
    }
    else
    {
      printf("UnluckyChef\n");
    }
    printf("\n");
  }
	return 0;
}

