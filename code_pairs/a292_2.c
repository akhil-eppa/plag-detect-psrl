#include <stdio.h>
#include<string.h>
int main(void) {
    int t;
    scanf("%d",&t);
        while(t--)    
       { 
        char s[1001],j[1001];
     scanf("%s",j);
     scanf("%s",s);
        
        int x=0;
        for(int l=0;l<strlen(s);l++)
        {
            for(int k=0;k<strlen(j);k++)
            {
                if(s[l]==j[k])
                {
                    x++;
                    break;
                }
            }
        
        }
        printf("%d\n",x);
    }
    
	return 0;
}