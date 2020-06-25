#include <stdio.h>

int main(void) {
	int t;
	char m[26];
	scanf("%d %s",&t,m);
	
	for(int i=0;i<t;i++)
	{
	    char str[100];
	    scanf("%s",str);
	    int j = 0;
	    
	    while(str[j])
	    {
	        int x = (int) str[j];
    	    //printf("(%d)",x);
    	    
	        switch(str[j])
	        {
	            case '.':
    	            printf(".");
    	            break;
    	        case ',':
    	            printf(",");
    	            break;
	            case '?':
    	            printf("?");
    	            break;
	            case '!':
    	            printf("!");
    	            break;
    	        case '_':
    	            printf(" ");
    	            break;
    	        default:
    	            if(x>=97 && x<=122)
    	            {
    	                printf("%c", m[x-97]);
    	            }
    	            else
    	            {
    	                x+=32;
    	                //printf("*%d*",x);
    	                printf("%c", m[x-97] - 32);
    	            }
    	            break;
	        }
	        j++;
	    }
	    
	    printf("\n");
	}
	return 0;
}

