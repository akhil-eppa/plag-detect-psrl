#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,count=0,j,a[101]={0},b[101]={0},l1,l2;
        char str1[101],str2[101];
        scanf("%s",str1);
        scanf("%s",str2);
        
        l1=strlen(str1);
        l2=strlen(str2);
        
        for(i=0;i<l1;i++)
        a[i]=str1[i];
        for(i=0;i<l2;i++)
        b[i]=str2[i];
        
        for(i=0;i<l2;i++)
        {
            for(j=0;j<l1;j++)
            {
                if(b[i]==a[j])
                {
                    count++;
                    break;
                }
            }
        }
        printf("%d\n",count);
        
    }
    return 0;
}