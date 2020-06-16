#include<stdio.h>
int main()
{
    int t;scanf("%d",&t);
    int bf[t],gf[t];int count=0;
    int i,j,k;int s,m;
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&bf[i],&gf[i]);
        int ss[gf[i]],mm[gf[i]];
        for(j=0;j<gf[i];j++)
        {
            scanf("%d %d",&ss[j],&mm[j]);
            
        } for(k=0;k<=gf[i]-2;k++)
        {
            if(mm[k]==ss[k+1])
            count++;
        }if(count==(gf[i]-1))
       { printf("YES\n");
           count =0;
       }
        else 
       { printf("NO\n");
       count=0;}
        
    }return 0;
}