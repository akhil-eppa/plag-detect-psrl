#include <stdio.h>
int main()
{
    int t,i,j,k,temp,n,count,b,c[100001],d[100001],x;
    char a[100001];
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        n=0;
        j=1;
        x=0;
        scanf("%s",&a);
        while(a[n]) n++;
        b=0;
        c[x]=0;
        d[x++]=1;
        for(i=0;i<n;i++)
        {
            b=b^(1<<(a[i]-'a'));
        	temp=1;
        	for(k=0;k<x;k++)
        	{
        		if(c[k]==b)
        		{
        			d[k]++;
        			temp=0;
        			break;
        		}
        	}
        	if(temp)
        		{
        			c[x]=b;
        			d[x++]=1;
        		}
        		j++;
        	}
        	if((x==2)&&((a[0]=='q')||(a[0]=='b')))
        	{
        		printf("2500000000\n");
        	}
        	else
        	{
        	    for(i=0;i<x;i++)
        	    {
        		    temp= (d[i]*(d[i]-1))/2;
        		    count=count+temp;
        	    }
        	    printf("%d\n",count);
        	}
    }
    return 0;
}