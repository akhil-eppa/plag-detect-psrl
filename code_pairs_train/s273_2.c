#include <stdio.h>
#include<string.h>
void main()
{
    char a[100],b[1000];
    int n,i,j=0,f=0;
    scanf("%s",a);
    n=strlen(a);
    for(i=n-1;i>=0;i--)
    {
        b[j]=a[i];
        j++;
    }
    for(i=0;i<n-1;i++)
    {
        if(a[i]==b[i])
        {
            f++;
            
        }
    }
    if(f==n-1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}