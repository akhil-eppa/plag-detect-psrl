#include <stdio.h>
#include <string.h>
int main()
{
    int t,n,s,a;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        s=n-1;
        a=2;
        while(a<=n/a)
        {
            if(n%a==0)
            {
                if(n/a>a)
                {
                    if((n/a)-a<s)
                    {
                s=(n/a)-a;
                    }
                }
                else{
                    if(a-(n/a)<s)
                    {
                    s=a-(n/a);
                    }
                }
            }
            a++;
        }
    printf("%d\n",s);
    t--;
    }
    return 0;
}