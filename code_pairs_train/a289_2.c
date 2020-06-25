#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,k,c,l,m;
    scanf("%d",&t);
    while(t--)
    {
        char j[100],s[100];
        c=0;
        scanf("%s",j);
        scanf("%s",s);
        l=strlen(s);
        m=strlen(j);
        for(i=0;i<l;i++)
        {
            for(k=0;k<m;k++)
            { if(s[i]==j[k])
              { ++c; break; } }
        }
        printf("%d\n",c);
    }
 return 0;
}