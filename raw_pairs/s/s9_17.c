#include<stdio.h>
void main()
{
    int tc,n,r,i,j,r1,r2,flag=0;
    //printf("Enter no of test cases");
    scanf("%d",&tc);
    for (i=0;i<tc;i++)
    {
    //printf("Enter no of countries and range");
    scanf("%d %d",&n,&r);
    for (j=0;j<r;j++)
    {
        scanf("%d %d",&r1,&r2);
        if (r1==r2||r1>n-1||r2>n-1)
       { flag=0;break;}
       else if (r2==(r1+1)%r)
        flag=1;
        else flag=0;
        
    }
    if (flag==1)
    printf("YES\n");
    else printf("NO\n");
    }
 
    
}
