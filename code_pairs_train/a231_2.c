#include<stdio.h>
#include<malloc.h>

int main()
{

    int *b,**m,i,j,n,total,temp,flag=0,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    scanf("%d",&total);
    flag=0;
    m=(int**)calloc(n+1,sizeof(int *));
    b=(int*)calloc(n+1,sizeof(int));
    for(i=0;i<=n;i++)
        m[i]=(int*)calloc(total+1,sizeof(int));
    b[0]=0;
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=total;j++)
        {
            temp=j-b[i];

            if(m[i-1][j])
                m[i][j]=m[i-1][j];
            if(temp>=0)
            {
                m[i][j]=(m[i-1][temp]+b[i]==j?j:m[i-1][j]);
            }

        }
    }
    
    for(i=1;i<=n;i++)
    {
        if(m[i][total])
        {
            flag=1;

        }
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");

   free(b);
   for(i=0;i<=n;i++)
   free(m[i]);
   free(m);
    }

    return 0;
}