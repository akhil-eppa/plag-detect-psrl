#include <stdio.h>
#include <string.h>
 
int main()
{
    char a[10000],b[10000];
    int t,i,j,k,l1,l2,count;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        count=0;
        scanf(" %s",&a);
        scanf(" %s",&b);
        l1=strlen(a);
        l2=strlen(b);
        for(i=0;i<l1;i++)
        {
           for(j=0;j<l2;j++)
           {
               if(a[i]==b[j])
               {
                   //a[i]=' ';
                   b[j]=' ';
                   count++;
                   break;
               }
            }
        }
        printf("%d\n",(l1+l2-(2*count)));
        //return 0;
    }  
    return 0;
}
 
 
