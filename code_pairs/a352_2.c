#include<stdio.h>
#define getcx getchar_unlocked
int inp()
{
    int n=0,ch=getcx();
    while(ch>='0'&&ch<='9')
    {
                           n=(n<<1)+(n<<3)+(ch-'0');
                           ch=getcx();
    }
    return n;
}
int main()
{
    int y,x,n,ans,t,i;
    t=inp();
    while(t--)
    {
              n=inp();
              x=inp();
              ans=1;
              for(i=0;i<n-1;i++)
              {
                              y=inp();
                              if(y<=x)
                              {
                                      ans++;
                                      x=y;
                              }
              }
              printf("%d\n",ans);
    }
    return 0;
}
