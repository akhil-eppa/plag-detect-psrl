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
#include<stdio.h>
 
void main()
{
    int tc,N,M,r1,r2,temp = -1;
    scanf("%d",&tc);
    while(tc--)
    {
        temp = -1;
        scanf("%d",&N);
        scanf("%d",&M);
        while(--M)
        {
            scanf("%d",&r1);
            scanf("%d",&r2);
            if(temp == -1)
            {
                if(r1>=0 && r2<N)
                    temp = r2;
                else
                    break;
            }
            else
            {
                if(r1==temp && r1>=0 && r2<N)
                    temp = r2;
                else
                    break;
            }
            
        
        }
         
        if(M==0)
            {
                printf("YES");
                printf("\n");
            }
        else
            {
                printf("NO");
                printf("\n");
            }
    }
}