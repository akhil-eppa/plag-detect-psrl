#include<stdio.h>
#include<stdlib.h>

inline int getn(){
        int n=0, c=getchar();
        while(c < '0' || c > '9')
                c = getchar();
        while(c >= '0' && c <= '9')
                n = (n<<3) + (n<<1) + c - '0', c = getchar();
        return n;
}

int main()
{
    int t,x,y,n,k,r_page,flag,i,p,c;
    t=getn();
    while(t--)
    {
        flag=0;
        x=getn();
        y=getn();
        k=getn();
        n=getn();
        r_page=x-y;
        for(i=0;i<n;i++)
        {
            p=getn();
            c=getn();
            if(p>=r_page && c<=k)
            {
                flag=1;
            }
        }
        if(flag==1)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }
    return 0;
}
