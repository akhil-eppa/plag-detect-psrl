#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n,s,c,l,d;
	    scanf("%d",&n);
	    int a[n];
	    for(int j=0;j<n;j++)
	    {
	        scanf("%d",&a[j]);
	    }
        s=abs(a[0]-a[1]);
        for(int j=0;j<n;j++)
        {
            c=0;
            for(int k=0;k<n;k++)
            {
                if(a[k]==a[j])
                {
                    c=c+1;
                    if(c==1)
                    {    
                    continue;
                    }
                    else
                    {
                     s=0;
                     break;
                    }
                    
                }
                   
                if(abs(a[j]-a[k])<s)
                {
                    s=abs(a[j]-a[k]);
                }
            }
            if(c>1)
            {
                break;
            }
        }
	    printf("%d\n",s);
	}
	return 0;
}

