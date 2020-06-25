#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,k,n,m=0,v;
        scanf("%d%d%d%d",&x,&y,&k,&n);
        int p[10000000],c[10000000],i;
        v=x-y;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&p[i],&c[i]);
            if(p[i]>=v)
            {
                if(c[i]<=k)
                 m++;
            }
        }
        if(m!=0)
        printf("LuckyChef\n");
        else 
        printf("UnluckyChef\n");
    }
	// your code goes here
	return 0;
}


