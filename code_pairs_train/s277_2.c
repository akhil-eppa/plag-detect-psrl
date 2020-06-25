/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
int main()
{
    int t,j;
    scanf("%d",&t);
    while(t--)
    {
        long int n,m,i,f=0;
        long int a[1000000001]={0};
        scanf("%ld %ld",&n,&m);
        while(m--)
        {    
            long int x,y;
            scanf("%ld %ld",&x,&y);
            
            
            if(x==y)
            {
                f=1;
                break;
            }
            else if(x>y&&x>n)
            {
                if((x-y)>n)
                f=1;
            }
         /*  if(x<=y)
            {
               for(i=x;i<=y;i++)
                {
               
                   a[i]++;
                }
            }
            else
            {
                for(i=x;i<=n-1;i++)
                a[i]++;
                for(i=0;i<=y;i++)
                a[i]++;
            }*/
        }
        
        
        if(f==1)
        printf("NO\n");
        else
        printf("YES\n");
        
    }
}