#include <stdio.h>

int main(void) 
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=sqrt(n);
        while(1)
        {
           if(n%m==0)
        {
            printf("%d\n",abs(m-n/m));
            break;
            
        }
        else
        {
           m--; 
        } 
        }
        
        
    }
	return 0;
}

