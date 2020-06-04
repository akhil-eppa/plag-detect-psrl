#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char ch[101];
        char ch1[101];
        int i,d,sum=0,e,j;
        scanf("%s\n",&ch);
        scanf("%s",&ch1);
        d=strlen(ch);
        e=strlen(ch1);
        for(i=0;i<e;i++)
        {
            for(j=0;j<d;j++)
            {
                if(ch1[i]==ch[j])
                {
                    sum++;
                    break;
                }
            }
        }
        
        printf("%d",sum);
        printf("\n");
    }
    return 0;
}