#include <stdio.h>
 
int main()
{
    int n,i,s,t;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d\n",&t);
        if(t%12==1||t%12==0)
        {
            if(t%12==0)
            {
                s=t-11;
                printf("%d WS\n",s);
            }
            else
            {
                s=t+11;
                printf("%d WS\n",s);
            }
            
        }
        else if(t%12==6||t%12==7)
        {
            if(t%12==6)
            {
                s=t+1;
                printf("%d WS\n",s);
            }
            else
            {
                s=t-1;
                printf("%d WS\n",s);
            }
        }
        else if(t%12==5||t%12==8)
        {
            if(t%12==5)
            {
                s=t+3;
                printf("%d MS\n",s);
            }
            else
            {
                s=t-3;
                printf("%d MS\n",s);
            }
        }
        else if(t%12==2||t%12==11)
        {
            if(t%12==2)
            {
                s=t+9;
                printf("%d MS\n",s);
            }
            else
            {
                s=t-9;
                printf("%d MS\n",s);
            }
        }
        else if(t%12==3||t%12==10)
        {
            if(t%12==3)
            {
                s=t+7;
                printf("%d AS\n",s);
            }
            else
            {
                s=t-7;
                printf("%d AS\n",s);
            }
        }
        else
        {
            if(t%12==4)
            {
                s=t+5;
                printf("%d AS\n",s);
            }
            else
            {
                s=t-5;
                printf("%d AS\n",s);
            }
       }
            }
        
            
        
    
    
    //printf("Hello World!\n");
    return 0;
}