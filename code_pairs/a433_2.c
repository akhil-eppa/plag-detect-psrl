#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    int t;
    char a[30];
    scanf("%d %s",&t,a);
    char s[110];
    while(t--)
    {
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            int x=s[i];
            if(s[i]=='_')
              printf(" ");
            else if( (x>=65 && x<=90) || (x>=97 && x<=122) )
            {
                char c=tolower(s[i]);
                char r=a[ ((int)(c))-97];
                if(x>=65 && x<=90)
                  printf("%c",toupper(r));
                  else
                   printf("%c",r);
            }
            else
             printf("%c",s[i]);
        }
        printf("\n");
        
        
        
        
        
    }
}