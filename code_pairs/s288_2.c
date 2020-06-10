#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char S1[100000];
        char S2[100000];
        scanf("%s  ",&S1);
        scanf("%s",&S2);
        int length1=strlen(S1);
        
        int count;
        for(int i=0;i<length1;i++)
        {
            count=0;
            for(int j=0;j<length1;j++)
            {
                if(S1[i]==S2[j])
                {
                    count++;
                    S2[j]='1';
                    break;
                }
                
            }
            if(count==0)
            {
                printf("NO\n");
                
                break;
            }
        }
        if(count!=0)
        {
            printf("YES\n");
        }
    }
    return 0;
}