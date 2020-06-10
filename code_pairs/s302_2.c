#include <stdio.h>
int next(int n)
{
    int i,ans;
    int d1,d2;
    int k[12]={67,71,73,79,83,89,97,101,103,107,109,113};
    if(n<=67)
    {
        ans=67;
    }
    else if(n>=113)
    {
        ans=113;
    }
    else
    {
        for(i=0;i<12;i++)
        {
            if(k[i]>n)
            {
               d1=k[i]-n ;
               d2=n-k[i-1];
               if(d1<d2)
               {
                   ans=k[i];
                   break;
               }
               else
               {
                   ans=k[i-1];
                   break;
               }
            }
        }
    }
    return ans;
}
int main()
{
    int t,i,n;
    int temp,ne;
    char ch[500];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",ch);
        for(i=0;i<n;i++)
        {
            temp=ch[i];
            ne=next(temp);
            ch[i]=ne;
            
        }
        printf("%s\n",ch);
    }
    return 0;
}