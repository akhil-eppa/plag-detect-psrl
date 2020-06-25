#include<stdio.h>
int main()
{
  long int t;
  scanf("%ld",&t);
  int x,y,k;
  long int n;
  while(t--)
  {
    scanf("%d%d%d%ld",&x,&y,&k,&n);
     int p[n];
     int c[n];
     for(int i=0;i<n;i++){
        scanf("%d%d",&p[i],&c[i]);
     }
     int flag=0;
     for(int i=0;i<n;i++)
     {
     	if(c[i]<=k)
     	{
     		if((p[i]+y)>=x)
     		{
     			flag=1;
     			break;
     		}
     	}
     }
     if(flag==1)
     {
     	printf("LuckyChef\n");
     }
     else
     {
     	printf("UnluckyChef\n");
     }

  } 

return 0;	
}
